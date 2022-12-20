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
#include "ItemMix.h"
#include "RecipeSO.h"

ItemTestScene::ItemTestScene()
{
}

ItemTestScene::~ItemTestScene()
{
}
void ItemTestScene::InventoryFetch()
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
			itemBoxs.at(i).SetItemData(L"");
		}
	}
}
void ItemTestScene::Enter()
{
	SOManager::GetInst()->Init();
	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\pianobgm.wav");
	SoundMgr::GetInst()->Play(L"BGM");
	m_Background_DefaultMode = new Background(L"Background1", L"Image\\Background\\background1.bmp");
	m_Background_MixMode = new Background(L"Background2", L"Image\\Background\\background2.bmp");
	m_Background_ExchangeMode = new Background(L"Background3", L"Image\\Background\\background3.bmp");
	m_Background_ItemTreeMode = new Background(L"Background4", L"Image\\Background\\background4.bmp");
	m_Background_DeleteMode = new Background(L"Background5", L"Image\\Background\\background5.bmp");


	itemMix = new ItemMix();

	Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));
	int iItem = 8;
	float fMoveDist = 10.f;
	float fObjScale = 100.f;
	float fTerm = (640 / iItem);
	for (int i = 0; i < iItem; i++)
	{
		itemBoxs.push_back(ItemBox(L""));
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
		InventoryFetch();
	}
	if (KEY_TAP(KEY::SPACE))
	{
		if (Inventory::GetInst()->GetCount() > 0)
		{
			itemMix->SelectItem(Inventory::GetInst()->GetItemData(0)->GetKey());
			Inventory::GetInst()->RemoveItem(0);
		}

		InventoryFetch();
	}

	if (KEY_TAP(KEY::S))
	{
		wstring str = itemMix->MixItem();
		if (str != L"")
		{
			if (RecipeSO::GetInst()->GetRecipe(str) != L"")
			{
				Inventory::GetInst()->AddItem(RecipeSO::GetInst()->GetRecipe(str));
				itemMix->Clear();
			}
		}
		InventoryFetch();
	}


	if (KEY_TAP(KEY::D))
	{
		itemMix->ReturnItems();
		itemMix->Clear();
		InventoryFetch();
	}

	if (KEY_TAP(KEY::F))
	{
		if (Inventory::GetInst()->GetCount() > 0)
		{
			if (RecipeSO::GetInst()->GetGirl(Inventory::GetInst()->GetItemData(0)->GetKey()) != L"")
			{
				wstring str = RecipeSO::GetInst()->GetGirl(Inventory::GetInst()->GetItemData(0)->GetKey());
				Inventory::GetInst()->RemoveItem(0);
				Inventory::GetInst()->AddItem(str);
			}
		}
		InventoryFetch();
	}


	if (KEY_TAP(KEY::ENTER))
	{
		InventoryFetch();
	}
}

void ItemTestScene::Render(HDC _dc)
{
	switch (itemMode)
	{
	case ItemMode::DEFAULTMODE:
		m_Background_DefaultMode->Render(_dc);
		break;
	case ItemMode::MIXMODE:
		m_Background_MixMode->Render(_dc);
		break;
	case ItemMode::EXCHANGEMODE:
		m_Background_ExchangeMode->Render(_dc);
		break;
	case ItemMode::ITEMTREEMODE:
		m_Background_ItemTreeMode->Render(_dc);
		break;
	case ItemMode::DELETEMODE:
		m_Background_DeleteMode->Render(_dc);
		break;
	}

	Scene::Render(_dc);
	for (int i = 0; i < 8; i++)
	{
		itemBoxs.at(i).Render(_dc);
	}
	itemMix->Render(_dc);
}