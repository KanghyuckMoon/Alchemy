#include "pch.h"
#include "CutScene.h"
#include "TextSO.h"
#include "ItemSO.h"
#include "Button.h"
#include "Core.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Image.h"
#include "Object.h"
#include "SpriteSO.h"
#include "SoundMgr.h"
#include "ResMgr.h"
#include "CharacterImage.h"

CutScene::CutScene()
{
	cutSceneItems.insert(L"¹Ì¼Ò³à1_1");
	cutSceneItems.insert(L"¹Ì¼Ò³à2_1");
	cutSceneItems.insert(L"¹Ì¼Ò³à3_1");
	cutSceneItems.insert(L"¹Ì¼Ò³à4_1");
	cutSceneItems.insert(L"¹Ì¼Ò³à5_1");
	cutSceneItems.insert(L"¹Ì¼Ò³à6_1");
	cutSceneItems.insert(L"¹Ì¼Ò³à7_1");
	cutSceneItems.insert(L"¹Ì¼Ò³à8_1");

	button = make_shared<Button>();
	button->SetScale(Vec2(640, 64));
	button->SetImageSize(Vec2(640, 32));
	button->SetImage(L"ButtonImage640-32", L"Image\\Background\\ButtonImage640-32.bmp");
	button->SetPos(Vec2(320, 440 - 32));
	button->SetCaption(L"TEXT");

	choiceButton1 = make_shared<Button>();
	choiceButton1->SetScale(Vec2(150, 40));
	choiceButton1->SetImageSize(Vec2(150, 40));
	choiceButton1->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");
	choiceButton1->SetPos(Vec2(320, 100));
	choiceButton1->SetCaption(L"TEXT");

	choiceButton2 = make_shared<Button>();
	choiceButton2->SetScale(Vec2(150, 40));
	choiceButton2->SetImageSize(Vec2(150, 40));
	choiceButton2->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");
	choiceButton2->SetPos(Vec2(320, 250));
	choiceButton2->SetCaption(L"TEXT");

	SoundMgr::GetInst()->LoadSound(L"TEXTEFF", false, L"Sound\\270338__littlerobotsoundfactory__open-01.wav");
	
	girlImage = make_shared<CharacterImage>();
	girlImage->SetIsSpot(true);
	girlImage->SetOriginPos(Vec2(404, 190));
	girlImage->SetTargetPos(Vec2(490, 210));

	boyImage = make_shared<CharacterImage>();
	boyImage->SetIsSpot(false);
	boyImage->SetOriginPos(Vec2(236, 190));
	boyImage->SetTargetPos(Vec2(150, 210));

	boyImage->SetImage(ResMgr::GetInst()->ImgLoad(L"PeopleImage", L"Image\\Background\\People.bmp"));
}

CutScene::~CutScene()
{
}

wstring CutScene::GetText(const wstring& itemKey, int index)
{
	wstring str = ItemSO::GetInst()->GetItemData(itemKey)->GetTextAddress();
	wstring str2 = std::to_wstring(index);
	str = str.append(str2);
	girlImage->SetImage(ItemSO::GetInst()->GetItemData(itemKey)->GetSprite());

	if (TextSO::GetInst()->GetTextData(str) != L"")
	{
		wstring text = TextSO::GetInst()->GetTextData(str);
		if (text.at(0) == L'[')
		{
			girlImage->SetIsSpot(true);
			boyImage->SetIsSpot(false);
		}
		else if (text.at(0) == L'{')
		{
			girlImage->SetIsSpot(false);
			boyImage->SetIsSpot(true);
		}
		else if (text.at(0) == L'(')
		{
			girlImage->SetIsSpot(false);
			boyImage->SetIsSpot(false);
		}
		else if (text.at(0) == L'!')
		{
			isChoice = true;
			//Button1
			{
				wstring str = ItemSO::GetInst()->GetItemData(itemKey)->GetTextAddress();
				wstring str2 = std::to_wstring(index + 1);
				str = str.append(str2);
				wstring text = TextSO::GetInst()->GetTextData(str);
				choiceButton1->SetCaption(text);
			}
			//Button2
			{
				wstring str = ItemSO::GetInst()->GetItemData(itemKey)->GetTextAddress();
				wstring str2 = std::to_wstring(index + 2);
				str = str.append(str2);
				wstring text = TextSO::GetInst()->GetTextData(str);
				choiceButton2->SetCaption(text);
			}
		}
		else
		{
			girlImage->SetIsSpot(true);
			boyImage->SetIsSpot(true);
		}

		return TextSO::GetInst()->GetTextData(str);
	}
	return L"";
}

bool CutScene::CheckCanCutSceneItem(const wstring& itemKey)
{
	if (cutSceneItems.count(itemKey))
	{
		index = 0;
		textIndex = 0;
		cutSceneItem = itemKey;
		cutSceneItems.erase(itemKey);
		isCutsing = true;

		wstring text = GetText(cutSceneItem, index++);
		if (text != L"")
		{
			outText = text;
		}

		return true;
	}

	return false;
}

bool CutScene::CheckCutSing()
{
	return isCutsing;
}

void CutScene::Render(HDC _dc)
{
	girlImage->Render(_dc);
	boyImage->Render(_dc);
	button->Render(_dc);

	if (isChoice)
	{
		choiceButton1->Render(_dc);
		choiceButton2->Render(_dc);
	}
}

void CutScene::Update()
{
	girlImage->Update();
	boyImage->Update();

	POINT mouse;
	GetCursorPos(&mouse);
	ScreenToClient(Core::GetInst()->GetWndHandle(), &mouse);
	SetButtonText();

	if (isChoice)
	{
		if (KEY_TAP(KEY::LBTN))
		{
			bool isClick = false;
			if (choiceButton1->StayCollision(mouse))
			{
				index += 100;

				isChoice = false;
				isClick = true;
			}
			else if (choiceButton2->StayCollision(mouse))
			{
				index += 1000;
				
				isChoice = false;
				isClick = true;
			}

			if (isClick)
			{
				wstring text = GetText(cutSceneItem, index++);
				if (text != L"")
				{
					button->SetCaption(L"");
					textIndex = 0;
					outText = text;
				}
				else
				{
					isCutsing = false;
				}
			}
		}
	}
	else if (isCutsing)
	{
		//ÅØ½ºÆ® Ã¢ ´©¸¦ ½Ã
		if (KEY_TAP(KEY::LBTN))
		{
			if (button->StayCollision(mouse))
			{
				if (cutSceneItem != L"")
				{
					wstring text = GetText(cutSceneItem, index++);
					if (text != L"")
					{
						button->SetCaption(L"");
						textIndex = 0;
						outText = text;
					}
					else
					{
						isCutsing = false;
					}
				}
			}
		}
	}
}

void CutScene::SetButtonText()
{
	static float time = 0.f;
	if (time < 0.05f)
	{
		time += TimeMgr::GetInst()->GetDT();
		return;
	}
	else
	{
		time = 0.f;
	}

	static wstring str = L"";

	if (outText.length() >= textIndex)
	{
		SoundMgr::GetInst()->Play(L"TEXTEFF");
		str = outText.substr(0, textIndex++);
	}

	button->SetCaption(str);
}
