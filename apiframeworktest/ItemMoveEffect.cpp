#include "pch.h"
#include "ItemMoveEffect.h"
#include "Image.h"
#include "Core.h"
#include "TimeMgr.h"
#include "ItemAfterImage.h"

ItemMoveEffect::ItemMoveEffect()
{
	shared_ptr<ItemAfterImage> effect;
	for (int i = 1; i < 5; ++i)
	{
		effect = make_shared<ItemAfterImage>(this);
		effect->SetDelay(0.01f * i);
		itemafterImages.push_back(effect);
	}
}

ItemMoveEffect::~ItemMoveEffect()
{
}

void ItemMoveEffect::SetEffect(Object* object, Vec2 target, Image* image, shared_ptr<vector<shared_ptr<ItemMoveEffect>>> itemMoveEffects)
{
	shared_ptr<ItemMoveEffect> effect = nullptr;

	for (auto& effectObj : (* itemMoveEffects))
	{
		if (!effectObj->isMove)
		{
			effect = effectObj;
			break;
		}
	}
	if (!effect)
	{
		effect = make_shared<ItemMoveEffect>();
		itemMoveEffects->push_back(effect);
	}

	effect->SetPos(object->GetPos());
	effect->SetScale(object->GetScale());
	effect->SetImage(image);
	effect->target = target;
	effect->time = 0.f;
	effect->SetMove(true);
}

void ItemMoveEffect::SetEffect(Vec2 origin, Vec2 scale, Vec2 target, Image* image, shared_ptr<vector<shared_ptr<ItemMoveEffect>>> itemMoveEffects)
{
	shared_ptr<ItemMoveEffect> effect = nullptr;

	for (auto& effectObj : (*itemMoveEffects))
	{
		if (!effectObj->isMove)
		{
			effect = effectObj;
			break;
		}
	}
	if (!effect)
	{
		effect = make_shared<ItemMoveEffect>();
		itemMoveEffects->push_back(effect);
	}

	effect->SetPos(origin);
	effect->SetScale(scale);
	effect->SetImage(image);
	effect->target = target;
	effect->time = 0.f;
	effect->SetMove(true);
}

void ItemMoveEffect::SetImage(Image* image)
{
	this->image = image;
}

void ItemMoveEffect::Update()
{
	if (time < 0.3f)
	{
		time += TimeMgr::GetInst()->GetDT();
	}
	else
	{
		isMove = false;
	}

	for (const auto& effect : itemafterImages)
	{
		effect->SetScale(Vec2(GetScale().x, GetScale().y));
		effect->Update();
	}

	SetPos(Vec2(LERP(GetPos().x, target.x, time / 0.3f), LERP(GetPos().y, target.y, time / 0.3f)));
}

void ItemMoveEffect::Render(HDC _dc)
{
	for (const auto& effect : itemafterImages)
	{
		effect->Render(_dc, image, 100);
	}

	TransparentBlt(_dc, GetPos().x - (GetScale().x / 2) + 5, 
		GetPos().y - (GetScale().y / 2) + 5, 
		GetScale().x / 2 - 10, 
		GetScale().y / 2 - 10,
		image->GetDC(), 0, 0, image->GetWidth(), image->GetHeight(), RGB(255,0,255));

}

void ItemMoveEffect::SetMove(bool isbool)
{
	isMove = isbool;
}
