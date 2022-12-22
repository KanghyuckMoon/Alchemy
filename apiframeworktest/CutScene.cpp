#include "pch.h"
#include "CutScene.h"
#include "TextSO.h"
#include "ItemSO.h"
#include "Button.h"
#include "Core.h"
#include "KeyMgr.h"

CutScene::CutScene()
{
	cutSceneItems.insert(L"�̼ҳ�1_1");
	cutSceneItems.insert(L"�̼ҳ�2_1");
	cutSceneItems.insert(L"�̼ҳ�3_1");
	cutSceneItems.insert(L"�̼ҳ�4_1");
	cutSceneItems.insert(L"�̼ҳ�5_1");
	cutSceneItems.insert(L"�̼ҳ�6_1");
	cutSceneItems.insert(L"�̼ҳ�7_1");
	cutSceneItems.insert(L"�̼ҳ�8_1");

	button = new Button();
	button->SetScale(Vec2(640, 64));
	button->SetImageSize(Vec2(640, 32));
	button->SetImage(L"ButtonImage640-32", L"Image\\Background\\ButtonImage640-32.bmp");
	button->SetPos(Vec2(320, 440 - 32));
	button->SetCaption(L"TEXT");
}

CutScene::~CutScene()
{
}

wstring CutScene::GetText(const wstring& itemKey, int index)
{
	wstring str = ItemSO::GetInst()->GetItemData(itemKey)->GetTextAddress();
	wstring str2 = std::to_wstring(index);
	str = str.append(str2);

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
		cutSceneItem = itemKey;
		cutSceneItems.erase(itemKey);
		isCutsing = true;

		wstring text = GetText(cutSceneItem, index++);
		if (text != L"")
		{
			button->SetCaption(text);
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
	button->Render(_dc);
}

void CutScene::Update()
{
	POINT mouse;
	GetCursorPos(&mouse);
	ScreenToClient(Core::GetInst()->GetWndHandle(), &mouse);

	if (isCutsing)
	{
		//�ؽ�Ʈ â ���� ��

		if (KEY_TAP(KEY::LBTN))
		{
			if (button->StayCollision(mouse))
			{
				if (cutSceneItem != L"")
				{
					wstring text = GetText(cutSceneItem, index++);
					if (text != L"")
					{
						button->SetCaption(text);
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
