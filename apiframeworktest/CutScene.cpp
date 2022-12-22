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

	button = new Button();
	button->SetScale(Vec2(640, 64));
	button->SetImageSize(Vec2(640, 32));
	button->SetImage(L"ButtonImage640-32", L"Image\\Background\\ButtonImage640-32.bmp");
	button->SetPos(Vec2(320, 440 - 32));
	button->SetCaption(L"TEXT");

	SoundMgr::GetInst()->LoadSound(L"TEXTEFF", false, L"Sound\\270338__littlerobotsoundfactory__open-01.wav");
}

CutScene::~CutScene()
{
}

wstring CutScene::GetText(const wstring& itemKey, int index)
{
	wstring str = ItemSO::GetInst()->GetItemData(itemKey)->GetTextAddress();
	wstring str2 = std::to_wstring(index);
	str = str.append(str2);
	image = ItemSO::GetInst()->GetItemData(itemKey)->GetSprite();

	if (TextSO::GetInst()->GetTextData(str) != L"")
	{
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
	if (image)
	{
		TransparentBlt(_dc,
			192,
			50,
			256,
			256,
			image->GetDC(), 0, 0, 128, 128, RGB(255, 255, 255));
	}
	button->Render(_dc);

}

void CutScene::Update()
{
	POINT mouse;
	GetCursorPos(&mouse);
	ScreenToClient(Core::GetInst()->GetWndHandle(), &mouse);
	SetButtonText();

	if (isCutsing)
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
