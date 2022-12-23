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
#include "CutScene.h"
#include "ItemMoveEffect.h"
#include "ItemSO.h"
#include "CauldronObject.h"

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
	SoundMgr::GetInst()->Play(L"BGM");
	m_Background_DefaultMode = new Background(L"Background1", L"Image\\Background\\background1.bmp");
	m_Background_MixMode = new Background(L"Background2", L"Image\\Background\\background2.bmp");
	m_Background_ExchangeMode = new Background(L"Background3", L"Image\\Background\\background3.bmp");
	m_Background_ItemTreeMode = new Background(L"Background4", L"Image\\Background\\background4.bmp");
	m_Background_DeleteMode = new Background(L"Background5", L"Image\\Background\\background5.bmp");

	woodObject = new WoodObject();
	cauldronObject = new CauldronObject();

	inventoryWindow = new Background(L"ButtonImage640-32", L"Image\\Background\\ButtonImage640-32.bmp");
	inventoryWindow->SetScale(Vec2(640, 64));
	inventoryWindow->SetPos(Vec2(320, 440 - 32));
	inventoryWindow->SetImageSize(Vec2(640, 32));

	itemCaptionWindow = new ItemCaptionWindow();

	itemTree = new ItemTree();
	itemMix = new ItemMix();
	cutScene = new CutScene();

	tutorialButton = new Button();
	tutorialButton->SetPos(Vec2(600, 30));
	tutorialButton->SetScale(Vec2(32, 32));
	tutorialButton->SetImageSize(Vec2(32, 32));
	tutorialButton->SetImage(L"Gear", L"Image\\ItemImage\\Gear.bmp");
	tutorialButton->SetCaption(L"도움말");

	mixButton = new Button();
	mixButton->SetPos(Vec2(100, 270));
	mixButton->SetScale(Vec2(150, 40));
	mixButton->SetImageSize(Vec2(150, 40));
	mixButton->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");
	mixButton->SetCaption(L"합성");

	cancleButton = new Button();
	cancleButton->SetPos(Vec2(550, 270));
	cancleButton->SetScale(Vec2(150, 40));
	cancleButton->SetImageSize(Vec2(150, 40));
	cancleButton->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");
	cancleButton->SetCaption(L"취소");

	leftSceneButton = new Button();
	leftSceneButton->SetPos(Vec2(70, 320));
	leftSceneButton->SetScale(Vec2(100, 20));
	leftSceneButton->SetImageSize(Vec2(150, 40));
	leftSceneButton->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");
	leftSceneButton->SetCaption(L"제거");

	rightSceneButton = new Button();
	rightSceneButton->SetPos(Vec2(540, 320));
	rightSceneButton->SetScale(Vec2(100, 20));
	rightSceneButton->SetImageSize(Vec2(100, 20));
	rightSceneButton->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");
	rightSceneButton->SetCaption(L"합성");

	Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));
	int iItem = 8;
	float fMoveDist = 10.f;
	float fObjScale = 100.f;
	float fTerm = (640 / iItem);
	for (int i = 0; i < iItem; i++)
	{
		itemBoxs.push_back(ItemBox(L""));
		itemBoxs.at(i).SetName(L"ItemBox");
		itemBoxs.at(i).SetPos(Vec2((fMoveDist + fObjScale / 2.f) + (float)i * fTerm, 435.f));
		itemBoxs.at(i).SetScale(Vec2(fObjScale, fObjScale));
	}

	itemMoveEffects = make_shared<vector<ItemMoveEffect*>>();
}

void ItemTestScene::Exit()
{
	DeleteAll();
}

void ItemTestScene::Update()
{
	Scene::Update();

	if (cutScene->CheckCutSing())
	{
		cutScene->Update();
	}
	else
	{
		tutorialButton->Update();

		POINT mouse;
		GetCursorPos(&mouse);
		ScreenToClient(Core::GetInst()->GetWndHandle(), &mouse);


		if (KEY_TAP(KEY::LBTN))
		{
			if (leftSceneButton->StayCollision(mouse))
			{
				switch (itemMode)
				{
				case ItemMode::DEFAULTMODE:
					itemMode = ItemMode::DELETEMODE;
					leftSceneButton->SetCaption(L"아이템 트리");
					rightSceneButton->SetCaption(L"벌목");
					break;
				case ItemMode::MIXMODE:
					itemMix->ReturnItems();
					itemMix->Clear();
					InventoryFetch();
					itemMode = ItemMode::DEFAULTMODE;
					leftSceneButton->SetCaption(L"제거");
					rightSceneButton->SetCaption(L"합성");
					break;
				case ItemMode::EXCHANGEMODE:
					itemMode = ItemMode::MIXMODE;
					leftSceneButton->SetCaption(L"벌목");
					rightSceneButton->SetCaption(L"등가 교환");
					break;
				case ItemMode::ITEMTREEMODE:
					itemMode = ItemMode::EXCHANGEMODE;
					leftSceneButton->SetCaption(L"합성");
					rightSceneButton->SetCaption(L"아이템 트리");
					break;
				case ItemMode::DELETEMODE:
					itemMode = ItemMode::ITEMTREEMODE;
					itemTree->ResetPosition();
					leftSceneButton->SetCaption(L"등가 교환");
					rightSceneButton->SetCaption(L"제거");
					break;
				}
			}

			if (rightSceneButton->StayCollision(mouse))
			{
				switch (itemMode)
				{
				case ItemMode::DEFAULTMODE:
					itemMode = ItemMode::MIXMODE;
					leftSceneButton->SetCaption(L"벌목");
					rightSceneButton->SetCaption(L"등가 교환");
					break;
				case ItemMode::MIXMODE:
					itemMix->ReturnItems();
					itemMix->Clear();
					InventoryFetch();
					itemMode = ItemMode::EXCHANGEMODE;
					leftSceneButton->SetCaption(L"합성");
					rightSceneButton->SetCaption(L"아이템 트리");
					break;
				case ItemMode::EXCHANGEMODE:
					itemMode = ItemMode::ITEMTREEMODE;
					itemTree->ResetPosition();
					leftSceneButton->SetCaption(L"등가 교환");
					rightSceneButton->SetCaption(L"제거");
					break;
				case ItemMode::ITEMTREEMODE:
					itemMode = ItemMode::DELETEMODE;
					leftSceneButton->SetCaption(L"아이템 트리");
					rightSceneButton->SetCaption(L"벌목");
					break;
				case ItemMode::DELETEMODE:
					itemMode = ItemMode::DEFAULTMODE;
					leftSceneButton->SetCaption(L"제거");
					rightSceneButton->SetCaption(L"합성");
					break;
				}
			}
		}

		switch (itemMode)
		{
		case ItemMode::DEFAULTMODE:
			woodObject->Update();
			if (KEY_TAP(KEY::LBTN))
			{
				if (woodObject->StayCollision(mouse))
				{
					SoundMgr::GetInst()->Play(L"DEFAULTEFF");
					if (Inventory::GetInst()->GetCount() < 8)
					{
						ItemMoveEffect::SetEffect(woodObject->GetPos(), Vec2(100.f, 100.f), itemBoxs.at(Inventory::GetInst()->GetCount()).GetPos(), ItemSO::GetInst()->GetItemData(L"나무")->GetSprite(), itemMoveEffects);
						Inventory::GetInst()->AddItem(L"나무");
					}
					InventoryFetch();
				}
			}
			break;
		case ItemMode::MIXMODE:
			cauldronObject->Update();
			{
				wstring str = itemMix->MixItem();
				if (str != L"")
				{
					if (RecipeSO::GetInst()->GetRecipe(str) != L"")
					{
						cauldronObject->SetIsCanMix(true);
					}
					else
					{
						cauldronObject->SetIsCanMix(false);
					}
				}
				else
				{
					cauldronObject->SetIsCanMix(false);
				}
			}
			if (KEY_TAP(KEY::LBTN))
			{
				for (size_t index = 0; index < itemBoxs.size(); ++index)
				{
					if ((itemBoxs.begin() + index)->ClickEvent(mouse))
					{
						if (itemMix->GetCount() < 2 && Inventory::GetInst()->GetCount() > index)
						{
							SoundMgr::GetInst()->Play(L"ITEMHCLICKEFF");
							ItemMoveEffect::SetEffect(&itemBoxs.at(index), itemMix->GetCurrentItemBox()->GetPos(), Inventory::GetInst()->GetItemData(index)->GetSprite(), itemMoveEffects);
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
							cauldronObject->SetMix();
							ItemMoveEffect::SetEffect(cauldronObject->GetPos(), Vec2(100.f, 100.f), itemBoxs.at(Inventory::GetInst()->GetCount()).GetPos(), ItemSO::GetInst()->GetItemData(RecipeSO::GetInst()->GetRecipe(str))->GetSprite(), itemMoveEffects);
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
					if (itemMix->ItemBox1()->GetItemData() != L"")
					{
						ItemMoveEffect::SetEffect(&(*itemMix->ItemBox1()), itemBoxs.at(Inventory::GetInst()->GetCount()).GetPos(), ItemSO::GetInst()->GetItemData(itemMix->ItemBox1()->GetItemData())->GetSprite(), itemMoveEffects);
					}
					if (itemMix->ItemBox2()->GetItemData() != L"")
					{
						ItemMoveEffect::SetEffect(&(*itemMix->ItemBox2()), itemBoxs.at(Inventory::GetInst()->GetCount() + 1).GetPos(), ItemSO::GetInst()->GetItemData(itemMix->ItemBox2()->GetItemData())->GetSprite(), itemMoveEffects);
					}
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
								ItemMoveEffect::SetEffect(&itemBoxs.at(index), Vec2(350, 260), Inventory::GetInst()->GetItemData(index)->GetSprite(), itemMoveEffects);
								Inventory::GetInst()->ChangeItem(str, index);
								cutScene->CheckCanCutSceneItem(str);
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
							ItemMoveEffect::SetEffect(&itemBoxs.at(index), Vec2(340, 150), Inventory::GetInst()->GetItemData(index)->GetSprite(), itemMoveEffects);
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

		for (const auto& effect : *itemMoveEffects)
		{
			if (effect->GetIsMove())
			{
				effect->Update();
			}
		}
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

	if (cutScene->CheckCutSing())
	{
		m_Background_ItemTreeMode->Render(_dc);
		Scene::Render(_dc);
		cutScene->Render(_dc);
	}
	else
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

		switch (itemMode)
		{
		case ItemMode::MIXMODE:
			cauldronObject->Render(_dc);
			inventoryWindow->Render(_dc);
			itemMix->Render(_dc);
			mixButton->Render(_dc);
			cancleButton->Render(_dc);

			for (int i = 0; i < 8; i++)
			{
				itemBoxs.at(i).Render(_dc);
			}

			TextOutW(_dc, 10, 10, L"합성", 2);
			TextOutW(_dc, 10, 449, L"← → : 장소 변경, 아이템 클릭 :  합성할 아이템 선택", 33);
			TextOutW(_dc, 10, 463, L"합성 버튼 : 두 아이템 합성하기, 취소 버튼 : 아이템 돌려받기", 36);

			break;
		case ItemMode::EXCHANGEMODE:
			inventoryWindow->Render(_dc);
			for (int i = 0; i < 8; i++)
			{
				itemBoxs.at(i).Render(_dc);
			}
			TextOutW(_dc, 10, 10, L"등가 교환", 5);
			TextOutW(_dc, 10, 460, L"← → : 장소 변경, 등가교환 가능한 아이템 클릭: 아이템 등가교환하기", 38);
			break;
		case ItemMode::DELETEMODE:
			inventoryWindow->Render(_dc);
			for (int i = 0; i < 8; i++)
			{
				itemBoxs.at(i).Render(_dc);
			}
			TextOutW(_dc, 10, 10, L"제거", 2);
			TextOutW(_dc, 10, 460, L"← → : 장소 변경, 아이템 클릭 : 아이템 버리기", 29);
			break;
		case ItemMode::DEFAULTMODE:
			woodObject->Render(_dc);
			inventoryWindow->Render(_dc);
			for (int i = 0; i < 8; i++)
			{
				itemBoxs.at(i).Render(_dc);
			}

			TextOutW(_dc, 10, 10, L"벌목", 2);
			TextOutW(_dc, 10, 460, L"← → : 장소 변경, 나무 클릭 : 나무 획득하기", 28);
			break;
		case ItemMode::ITEMTREEMODE:
			SetTextColor(_dc, RGB(0, 0, 0));
			itemTree->Render(_dc);
			SetTextColor(_dc, RGB(0, 0, 0));
			TextOutW(_dc, 10, 10, L"아이템 트리", 6);
			SetTextColor(_dc, RGB(0, 0, 0));
			TextOutW(_dc, 10, 30, L"검정 : 다른 두 가지 아이템 합성", 19);
			SetTextColor(_dc, RGB(255, 0, 0));
			TextOutW(_dc, 10, 50, L"빨강 : 등가교환", 9);
			SetTextColor(_dc, RGB(0, 0, 255));
			TextOutW(_dc, 10, 70, L"파랑 : 같은 아이템 두 개 합성", 18);
			SetTextColor(_dc, RGB(0, 0, 0));
			TextOutW(_dc, 10, 449, L"← → : 장소 변경, 아이템에 마우스 올리기 : 아이템 정보 확인", 37);
			TextOutW(_dc, 10, 463, L"드래그 : 아이템 트리 둘러보기", 17);
			SetTextColor(_dc, RGB(255, 255, 255));
			break;
		}
		itemCaptionWindow->Render(_dc);

		leftSceneButton->Render(_dc);
		rightSceneButton->Render(_dc);

		for (const auto& effect : *itemMoveEffects)
		{
			if (effect->GetIsMove())
			{
				effect->Render(_dc);
			}
		}


		tutorialButton->Render(_dc);
	}

	DeleteObject(s_hFont);
}