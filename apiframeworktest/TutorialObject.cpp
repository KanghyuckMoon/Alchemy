#include "pch.h"
#include "TutorialObject.h"
#include "Image.h"
#include "ResMgr.h"
#include "Core.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "Scene_Credit.h"

TutorialObject::TutorialObject()
{
	image = ResMgr::GetInst()->ImgLoad(L"Intro_1", L"Image\\Intro\\Intro1.bmp");
	SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	SetScale(Vec2(500, 300));

	leftBtn = new Button();
	leftBtn->SetScale(Vec2(40, 40));
	leftBtn->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 - 200, Core::GetInst()->GetResolution().y / 2 + 100));
	leftBtn->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");
	leftBtn->SetImageSize(Vec2(40, 40));
	leftBtn->SetCaption(L"Left");
	leftBtn->CreateCollider();

	rightBtn = new Button();
	rightBtn->SetScale(Vec2(40, 40));
	rightBtn->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + 200, Core::GetInst()->GetResolution().y / 2 + 100));
	rightBtn->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");
	rightBtn->SetImageSize(Vec2(40, 40));
	rightBtn->SetCaption(L"Right");
	rightBtn->CreateCollider();

	closeBtn = new Button();
	closeBtn->SetScale(Vec2(40, 40));
	closeBtn->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + 200, Core::GetInst()->GetResolution().y / 2 - 100));
	closeBtn->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");
	closeBtn->SetImageSize(Vec2(40, 40));
	closeBtn->SetCaption(L"Close");
	closeBtn->CreateCollider();

	m_index = 1;
	maxIndex = 5;
}

TutorialObject::~TutorialObject()
{
}

void TutorialObject::Update()
{
	// 여기서 버튼 관리
	POINT mouse;
	GetCursorPos(&mouse);
	ScreenToClient(Core::GetInst()->GetWndHandle(), &mouse);

	KEY_STATE key = KeyMgr::GetInst()->GetKey(KEY::LBTN);

	if (leftBtn->StayCollision(mouse)) {
		if (key == KEY_STATE::TAP) {
			// 이전 튜토리얼
			if (m_index-- == 0) {
				m_index = maxIndex;
			}
		}
	}

	if (rightBtn->StayCollision(mouse)) {
		if (key == KEY_STATE::TAP) {
			// 다음 튜토리얼
			if (m_index++ == maxIndex) {
				m_index = 1;
			}
		}
	}

	if (closeBtn->StayCollision(mouse)) {
		if (key == KEY_STATE::TAP) {
			scene_credit->SetIsTutorial(false);
		}
	}

	switch (m_index) {
	case 1:
		image = ResMgr::GetInst()->ImgLoad(L"Intro_1", L"Image\\Intro\\Intro1.bmp");;
		break;
	case 2:
		image = ResMgr::GetInst()->ImgLoad(L"Intro_2", L"Image\\Intro\\Intro2.bmp");;
		break;
	case 3:
		image = ResMgr::GetInst()->ImgLoad(L"Intro_3", L"Image\\Intro\\Intro3.bmp");;
		break;
	case 4:
		image = ResMgr::GetInst()->ImgLoad(L"Intro_4", L"Image\\Intro\\Intro4.bmp");;
		break;
	case 5:
		image = ResMgr::GetInst()->ImgLoad(L"Intro_5", L"Image\\Intro\\Intro5.bmp");;
		break;
	}
}

void TutorialObject::Render(HDC _dc)
{
	SetBkMode(_dc, TRANSPARENT);

	HFONT s_hFont = (HFONT)NULL;
	HFONT s_oldHFont = (HFONT)NULL;
	LOGFONT logFont;
	ZeroMemory(&logFont, sizeof(LOGFONT));

	logFont.lfHeight = -MulDiv(10, GetDeviceCaps(_dc, LOGPIXELSY), 50);
	logFont.lfWeight = FW_NORMAL;
	SetTextColor(_dc, RGB(255, 255, 255));
	wcscpy_s(logFont.lfFaceName, TEXT("DungGeunMo"));
	s_hFont = CreateFontIndirect(&logFont);
	s_oldHFont = (HFONT)SelectObject(_dc, s_hFont);

	TransparentBlt(_dc, GetPos().x - (GetScale().x / 2), GetPos().y - (GetScale().y / 2), GetScale().x, GetScale().y, image->GetDC(), 0, 0, image->GetWidth(), image->GetHeight(), RGB(255, 0, 255));

	leftBtn->Render(_dc);
	rightBtn->Render(_dc);
	closeBtn->Render(_dc);

	DeleteObject(s_hFont);
}
