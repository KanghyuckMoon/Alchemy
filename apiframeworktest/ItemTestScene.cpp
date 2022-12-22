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
#include "ItemTree.h"
#include "Button.h"
#include "ItemCaptionWindow.h"
#include "WoodObject.h"

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
	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\Morning-Kiss.wav");
	SoundMgr::GetInst()->LoadSound(L"MIXEFF", false, L"Sound\\game-start-6104.wav");
	SoundMgr::GetInst()->LoadSound(L"DEFAULTEFF", false, L"Sound\\kick-hard-8-bit-103746.wav");
	SoundMgr::GetInst()->LoadSound(L"ITEMHIGHEFF", false, L"Sound\\one_beep-99630.wav");
	SoundMgr::GetInst()->LoadSound(L"ITEMHCLICKEFF", false, L"Sound\\confirm-38513.wav");
	SoundMgr::GetInst()->LoadSound(L"CANCLEEFF", false, L"Sound\\hurt_c_08-102842.wav");
	//SoundMgr::GetInst()->Play(L"BGM");
	m_Background_DefaultMode = new Background(L"Background1", L"Image\\Background\\background1.bmp");
	m_Background_MixMode = new Background(L"Background2", L"Image\\Background\\background2.bmp");
	m_Background_ExchangeMode = new Background(L"Background3", L"Image\\Background\\background3.bmp");
	m_Background_ItemTreeMode = new Background(L"Background4", L"Image\\Background\\background4.bmp");
	m_Background_DeleteMode = new Background(L"Background5", L"Image\\Background\\background5.bmp");

	woodObject = new WoodObject();

	inventoryWindow = new Background(L"ButtonImage640-32", L"Image\\Background\\ButtonImage640-32.bmp");
	inventoryWindow->SetScale(Vec2(640, 64));
	inventoryWindow->SetPos(Vec2(320, 440 - 32));
	inventoryWindow->SetImageSize(Vec2(640, 32));

	itemCaptionWindow = new ItemCaptionWindow();

	itemTree = new ItemTree();
	itemMix = new ItemMix();

	mixButton = new Button();
	mixButton->SetPos(Vec2(100, 270));
	mixButton->SetScale(Vec2(150, 40));
	mixButton->SetImageSize(Vec2(150, 40));
	mixButton->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");

	cancleButton = new Button();
	cancleButton->SetPos(Vec2(550, 270));
	cancleButton->SetScale(Vec2(150, 40));
	cancleButton->SetImageSize(Vec2(150, 40));
	cancleButton->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");

	Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));
	int iItem = 8;
	float fMoveDist = 30.f;
	float fObjScale = 100.f;
	float fTerm = (640 / iItem);
	for (int i = 0; i < iItem; i++)
	{
		itemBoxs.push_back(ItemBox(L""));
		itemBoxs.at(i).SetName(L"ItemBox");
		itemBoxs.at(i).SetPos(Vec2((fMoveDist + fObjScale / 2.f) + (float)i * fTerm, 440.f));
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


	if (KEY_TAP(KEY::LEFT))
	{
		switch (itemMode)
		{
		case ItemMode::DEFAULTMODE:
			itemMode = ItemMode::DELETEMODE;
			break;
		case ItemMode::MIXMODE:
			itemMode = ItemMode::DEFAULTMODE;
			break;
		case ItemMode::EXCHANGEMODE:
			itemMode = ItemMode::MIXMODE;
			break;
		case ItemMode::ITEMTREEMODE:
			itemMode = ItemMode::EXCHANGEMODE;
			break;
		case ItemMode::DELETEMODE:
			itemMode = ItemMode::ITEMTREEMODE;
			itemTree->ResetPosition();
			break;
		}
	}

	if (KEY_TAP(KEY::RIGHT))
	{
		switch (itemMode)
		{
		case ItemMode::DEFAULTMODE:
			itemMode = ItemMode::MIXMODE;
			break;
		case ItemMode::MIXMODE:
			itemMode = ItemMode::EXCHANGEMODE;
			break;
		case ItemMode::EXCHANGEMODE:
			itemMode = ItemMode::ITEMTREEMODE;
			itemTree->ResetPosition();
			break;
		case ItemMode::ITEMTREEMODE:
			itemMode = ItemMode::DELETEMODE;
			break;
		case ItemMode::DELETEMODE:
			itemMode = ItemMode::DEFAULTMODE;
			break;
		}
	}

	POINT mouse;
	GetCursorPos(&mouse);
	ScreenToClient(Core::GetInst()->GetWndHandle(), &mouse);

	switch (itemMode)
	{
	case ItemMode::DEFAULTMODE:
		woodObject->Update();
		if (KEY_TAP(KEY::LBTN))
		{
			if (woodObject->StayCollision(mouse))
			{
				SoundMgr::GetInst()->Play(L"DEFAULTEFF");
				Inventory::GetInst()->AddItem(L"나무");
				InventoryFetch();
			}
		}
		break;
	case ItemMode::MIXMODE:
		if (KEY_TAP(KEY::LBTN))
		{
			for (size_t index = 0; index < itemBoxs.size(); ++index)
			{
				if ((itemBoxs.begin() + index)->ClickEvent(mouse))
				{
					if (itemMix->GetCount() < 2 && Inventory::GetInst()->GetCount() > index)
					{
						SoundMgr::GetInst()->Play(L"ITEMHCLICKEFF");
						itemMix->SelectItem(Inventory::GetInst()->GetItemData(index)->GetKey());
						Inventory::GetInst()->RemoveItem(index);
						break;
					}
				}
			}

			if (mixButton->StayCollision(mouse))
			{
				wstring str = itemMix->MixItem();
				if (str != L"")
				{
					if (RecipeSO::GetInst()->GetRecipe(str) != L"")
					{
						SoundMgr::GetInst()->Play(L"MIXEFF");
						Inventory::GetInst()->AddItem(RecipeSO::GetInst()->GetRecipe(str));
						itemMix->Clear();
					}
					else
					{
						SoundMgr::GetInst()->Play(L"CANCLEEFF");
					}
				}
			}

			if (cancleButton->StayCollision(mouse))
			{
				SoundMgr::GetInst()->Play(L"CANCLEEFF");
				itemMix->ReturnItems();
				itemMix->Clear();
				InventoryFetch();
			}


			InventoryFetch();
		}
		break;

	case ItemMode::EXCHANGEMODE:
		if (KEY_TAP(KEY::LBTN))
		{
			for (size_t index = 0; index < itemBoxs.size(); ++index)
			{
				if ((itemBoxs.begin() + index)->ClickEvent(mouse))
				{
					if (Inventory::GetInst()->GetCount() > index)
					{
						if (RecipeSO::GetInst()->GetGirl(Inventory::GetInst()->GetItemData(index)->GetKey()) != L"")
						{
							wstring str = RecipeSO::GetInst()->GetGirl(Inventory::GetInst()->GetItemData(index)->GetKey());

							if (str == L"미소녀9_1")
							{
								SceneMgr::GetInst()->ChangeScene(SCENE_TYPE::SCENE_ENDING);
								break;
							}
							SoundMgr::GetInst()->Play(L"MIXEFF");
							Inventory::GetInst()->ChangeItem(str, index);
							break;
						}
						else
						{
							SoundMgr::GetInst()->Play(L"CANCLEEFF");
						}
					}
				}
			}
			InventoryFetch();
		}
		break;
	case ItemMode::DELETEMODE:

		if (KEY_TAP(KEY::LBTN))
		{
			for (size_t index = 0; index < itemBoxs.size(); ++index)
			{
				if ((itemBoxs.begin() + index)->ClickEvent(mouse))
				{
					if (Inventory::GetInst()->GetCount() > index)
					{
						SoundMgr::GetInst()->Play(L"CANCLEEFF");
						Inventory::GetInst()->RemoveItem(index);
						break;
					}
				}
			}
			InventoryFetch();
		}
		break;
	case ItemMode::ITEMTREEMODE:
		itemTree->Update();
		break;
	}

	if (itemMode == ItemMode::ITEMTREEMODE)
	{
		static bool isPreviousTouch = false;
		bool isTouch = false;
		if (itemTree->ClickEventGetItemKey(mouse) != L"")
		{
			isTouch = true;
			itemCaptionWindow->SetItemData(itemTree->ClickEventGetItemKey(mouse));

		}
		else
		{
			itemCaptionWindow->SetItemData(L"");
		}
		if (isTouch && !isPreviousTouch)
		{
			SoundMgr::GetInst()->Play(L"ITEMHIGHEFF");
		}
		isPreviousTouch = isTouch;
	}
	else
	{
		static bool isPreviousTouch = false;
		bool isTouch = false;
		for (size_t index = 0; index < itemBoxs.size(); ++index)
		{
			if ((itemBoxs.begin() + index)->ClickEvent(mouse))
			{
				if (Inventory::GetInst()->GetCount() > index)
				{
					isTouch = true;
					itemCaptionWindow->SetItemData(Inventory::GetInst()->GetItemData(index)->GetKey());
					break;
				}
				else
				{
					isTouch = false;
					itemCaptionWindow->SetItemData(L"");
				}
			}
		}
		if (!isTouch)
		{

			itemCaptionWindow->SetItemData(L"");
		}
		else if (!isPreviousTouch)
		{
			SoundMgr::GetInst()->Play(L"ITEMHIGHEFF");
		}

		isPreviousTouch = isTouch;
	}
}

void ItemTestScene::Render(HDC _dc)
{
	SetBkMode(_dc, TRANSPARENT);

	HFONT s_hFont = (HFONT)NULL;
	HFONT s_oldHFont = (HFONT)NULL;
	LOGFONT logFont;
	ZeroMemory(&logFont, sizeof(LOGFONT));

	logFont.lfHeight = -MulDiv(10, GetDeviceCaps(_dc, LOGPIXELSY), 72);
	logFont.lfWeight = FW_NORMAL;
	SetTextColor(_dc, RGB(255, 255, 255));
	wcscpy_s(logFont.lfFaceName, TEXT("DungGeunMo"));
	s_hFont = CreateFontIndirect(&logFont);
	s_oldHFont = (HFONT)SelectObject(_dc, s_hFont);

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


	switch (itemMode)
	{
	case ItemMode::MIXMODE:
		inventoryWindow->Render(_dc);
		itemMix->Render(_dc);
		mixButton->Render(_dc);
		cancleButton->Render(_dc);
		for (int i = 0; i < 8; i++)
		{
			itemBoxs.at(i).Render(_dc);
		}

		TextOutW(_dc, 10, 10, L"합성", 2);
		break;
	case ItemMode::EXCHANGEMODE:
		inventoryWindow->Render(_dc);
		for (int i = 0; i < 8; i++)
		{
			itemBoxs.at(i).Render(_dc);
		}
		TextOutW(_dc, 10, 10, L"등가 교환", 5);
		break;
	case ItemMode::DELETEMODE:
		inventoryWindow->Render(_dc);
		for (int i = 0; i < 8; i++)
		{
			itemBoxs.at(i).Render(_dc);
		}
		TextOutW(_dc, 10, 10, L"제거", 2);
		break;
	case ItemMode::DEFAULTMODE:
		woodObject->Render(_dc);
		inventoryWindow->Render(_dc);
		for (int i = 0; i < 8; i++)
		{
			itemBoxs.at(i).Render(_dc);
		}

		TextOutW(_dc, 10, 10, L"벌목", 2);
		break;
	case ItemMode::ITEMTREEMODE:
		itemTree->Render(_dc);
		TextOutW(_dc, 10, 10, L"아이템 트리", 6);
		TextOutW(_dc, 10, 30, L"검정 : 다른 두 가지 아이템 합성", 19);
		TextOutW(_dc, 10, 50, L"빨강 : 등가교환", 9);
		TextOutW(_dc, 10, 70, L"파랑 : 같은 아이템 두 개 합성", 18);
		break;
	}
	itemCaptionWindow->Render(_dc);

	DeleteObject(s_hFont);
}