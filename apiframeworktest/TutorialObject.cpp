#include "pch.h"
#include "TutorialObject.h"
#include "Image.h"
#include "ResMgr.h"
#include "Core.h"
#include "KeyMgr.h"
#include "ItemTestScene.h"

TutorialObject::TutorialObject()
{
	tutorialImage_0 = ResMgr::GetInst()->ImgLoad(L"Tutorial_0", L"Image\\Tutorial\\Tutorial0.bmp");
	tutorialImage_1 = ResMgr::GetInst()->ImgLoad(L"Tutorial_1", L"Image\\Tutorial\\Tutorial1.bmp");
	tutorialImage_2 = ResMgr::GetInst()->ImgLoad(L"Tutorial_2", L"Image\\Tutorial\\Tutorial2.bmp");
	tutorialImage_3 = ResMgr::GetInst()->ImgLoad(L"Tutorial_3", L"Image\\Tutorial\\Tutorial3.bmp");
	tutorialImage_4 = ResMgr::GetInst()->ImgLoad(L"Tutorial_4", L"Image\\Tutorial\\Tutorial4.bmp");
	tutorialImage_5 = ResMgr::GetInst()->ImgLoad(L"Tutorial_5", L"Image\\Tutorial\\Tutorial5.bmp");
	tutorialImage_6 = ResMgr::GetInst()->ImgLoad(L"Tutorial_6", L"Image\\Tutorial\\Tutorial6.bmp");
	tutorialImage_7 = ResMgr::GetInst()->ImgLoad(L"Tutorial_7", L"Image\\Tutorial\\Tutorial7.bmp");
	tutorialImage_8 = ResMgr::GetInst()->ImgLoad(L"Tutorial_8", L"Image\\Tutorial\\Tutorial8.bmp");
	tutorialImage_9 = ResMgr::GetInst()->ImgLoad(L"Tutorial_9", L"Image\\Tutorial\\Tutorial9.bmp");
	tutorialImage_10 = ResMgr::GetInst()->ImgLoad(L"Tutorial_10", L"Image\\Tutorial\\Tutorial10.bmp");
	tutorialImage_11 = ResMgr::GetInst()->ImgLoad(L"Tutorial_11", L"Image\\Tutorial\\Tutorial11.bmp");
	tutorialImage_12 = ResMgr::GetInst()->ImgLoad(L"Tutorial_12", L"Image\\Tutorial\\Tutorial12.bmp");
	image = tutorialImage_0;

	SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	SetScale(Vec2(500, 300));

	leftBtn = new Button();
	leftBtn->SetScale(Vec2(40, 40));
	leftBtn->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + 90, Core::GetInst()->GetResolution().y / 2 + 160));
	leftBtn->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");
	leftBtn->SetImageSize(Vec2(40, 40));
	leftBtn->SetCaption(L"이전");
	leftBtn->CreateCollider();

	rightBtn = new Button();
	rightBtn->SetScale(Vec2(40, 40));
	rightBtn->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + 150, Core::GetInst()->GetResolution().y / 2 + 160));
	rightBtn->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");
	rightBtn->SetImageSize(Vec2(40, 40));
	rightBtn->SetCaption(L"다음");
	rightBtn->CreateCollider();

	closeBtn = new Button();
	closeBtn->SetScale(Vec2(40, 40));
	closeBtn->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + 210, Core::GetInst()->GetResolution().y / 2 + 160));
	closeBtn->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");
	closeBtn->SetImageSize(Vec2(40, 40));
	closeBtn->SetCaption(L"닫기");
	closeBtn->CreateCollider();

	m_index = 0;
	maxIndex = 12;
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

	if (leftBtn->StayCollision(mouse)) {
		if (KEY_TAP(KEY::LBTN)) {
			// 이전 튜토리얼
			if (m_index-- == -1) {
				m_index = maxIndex;
			}
		}
	}

	if (rightBtn->StayCollision(mouse)) {
		if (KEY_TAP(KEY::LBTN)) {
			// 다음 튜토리얼
			if (m_index++ == maxIndex) {
				m_index = 0;
			}
		}
	}

	if (closeBtn->StayCollision(mouse)) {
		if (KEY_TAP(KEY::LBTN)) {
			itemTestScene->SetIsTutorial(false);
		}
	}

	switch (m_index) {
	case 0:
		image = tutorialImage_0;
		break;
	case 1:
		image = tutorialImage_1;
		break;
	case 2:
		image = tutorialImage_2;
		break;
	case 3:
		image = tutorialImage_3;
		break;
	case 4:
		image = tutorialImage_4;
		break;
	case 5:
		image = tutorialImage_5;
		break;
	case 6:
		image = tutorialImage_6;
		break;
	case 7:
		image = tutorialImage_7;
		break;
	case 8:
		image = tutorialImage_8;
		break;
	case 9:
		image = tutorialImage_9;
		break;
	case 10:
		image = tutorialImage_10;
		break;
	case 11:
		image = tutorialImage_11;
		break;
	case 12:
		image = tutorialImage_12;
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
