#include "pch.h"
#include "CauldronObject.h"
#include "Image.h"
#include "ClickEffect.h"
#include "AfterImage.h"
#include "ResMgr.h"
#include "TimeMgr.h"

CauldronObject::CauldronObject()
{
	image = ResMgr::GetInst()->ImgLoad(L"CauldronImage", L"Image\\Background\\cauldronImage.bmp");
	SetPos(Vec2(320, 340));
	SetScale(Vec2(200, 200));

	shared_ptr<AfterImage> afterImage;

	for (int i = 1; i < 6; ++i)
	{
		afterImage = make_shared<AfterImage>(this);
		afterImage->SetPos(Vec2(1000, 1000));
		afterImage->SetScale(Vec2(200, 200));
		afterImage->SetDelay((float)i * 0.15f);
		afterImages.push_back(afterImage);
	}

	clickEffect = make_shared<ClickEffect>();
}

CauldronObject::~CauldronObject()
{
}

void CauldronObject::Update()
{
	static float time = 0.f;

	time += TimeMgr::GetInst()->GetDT();

	if (isCanMix)
	{
		SetPos(Vec2(320 + cos(time * 10) * 10, 340 + sin(time * 10) * 10));
		for (auto& after : afterImages)
		{
			after->Update();
		}
	}
	else
	{
		SetPos(Vec2(320, 340));
	}
	clickEffect->Update();
}

void CauldronObject::Render(HDC _dc)
{
	if (isCanMix)
	{
		for (auto& after : afterImages)
		{
			after->Render(_dc, image, 50);
		}
	}
	TransparentBlt(_dc, GetPos().x - (GetScale().x / 2), GetPos().y - (GetScale().y / 2), GetScale().x, GetScale().y, image->GetDC(), 0, 0, image->GetWidth(), image->GetHeight(), RGB(255, 0, 255));
	clickEffect->Render(_dc, image, 100);
}

void CauldronObject::SetMix()
{
	clickEffect->SetClick(GetPos());
}
