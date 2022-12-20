#include "pch.h"
#include "ItemTestScene.h"
#include "Object.h"
#include "Player.h"
#include "Monster.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "ItemBox.h"
#include "SOManager.h"
#include "Background.h"
#include "Inventory.h"
#include "ItemData.h"

ItemTestScene::ItemTestScene()
{
}

ItemTestScene::~ItemTestScene()
{
}
void ItemTestScene::Enter()
{
	SOManager::GetInst()->Init();
	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\pianobgm.wav");
	SoundMgr::GetInst()->Play(L"BGM");
	m_Background = new Background(L"Background1", L"Image\\Background\\background1.bmp");
	
	Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));
	int iItem = 8;
	float fMoveDist = 10.f;
	float fObjScale = 100.f;
	float fTerm = (640 / iItem);
	for (int i = 0; i < iItem; i++)
	{
		itemBoxs.push_back(ItemBox(L"NULL"));
		itemBoxs.at(i).SetName(L"ItemBox");
		itemBoxs.at(i).SetPos(Vec2((fMoveDist + fObjScale / 2.f) + (float)i * fTerm, 480 - fObjScale));
		itemBoxs.at(i).SetScale(Vec2(fObjScale, fObjScale));
	}

}

void ItemTestScene::Exit()
{
	DeleteAll();
}

void ItemTestScene::Update()
{
	Scene::Update();

	if (KEY_TAP(KEY::A))
	{
		Inventory::GetInst()->AddItem(L"³ª¹«");
	}


	if (KEY_TAP(KEY::ENTER))
	{
		for (int i = 0; i < 8; i++)
		{
			shared_ptr<ItemData> itemData = Inventory::GetInst()->GetItemData(i);
			if (itemData)
			{
				itemBoxs.at(i).SetItemData(itemData->GetKey());
			}
			else
			{
				itemBoxs.at(i).SetItemData(L"NULL");
			}
		}
	}
}

void ItemTestScene::Render(HDC _dc)
{
	m_Background->Render(_dc);
	Scene::Render(_dc);
	for (int i = 0; i < 8; i++)
	{
		itemBoxs.at(i).Render(_dc);
	}
}