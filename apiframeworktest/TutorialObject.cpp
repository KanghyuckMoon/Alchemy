#include "pch.h"
#include "TutorialObject.h"
#include "Image.h"
#include "ResMgr.h"
#include "Core.h"
#include "KeyMgr.h"
#include "ItemTestScene.h"

TutorialObject::TutorialObject()
{
	tutorialImages.push_back(ResMgr::GetInst()->ImgLoad(L"Tutorial_0", L"Image\\Tutorial\\Tutorial0.bmp"));
	tutorialImages.push_back(ResMgr::GetInst()->ImgLoad(L"Tutorial_1", L"Image\\Tutorial\\Tutorial1.bmp"));
	tutorialImages.push_back(ResMgr::GetInst()->ImgLoad(L"Tutorial_2", L"Image\\Tutorial\\Tutorial2.bmp"));
	tutorialImages.push_back(ResMgr::GetInst()->ImgLoad(L"Tutorial_3", L"Image\\Tutorial\\Tutorial3.bmp"));
	tutorialImages.push_back(ResMgr::GetInst()->ImgLoad(L"Tutorial_4", L"Image\\Tutorial\\Tutorial4.bmp"));
	tutorialImages.push_back(ResMgr::GetInst()->ImgLoad(L"Tutorial_5", L"Image\\Tutorial\\Tutorial5.bmp"));
	tutorialImages.push_back(ResMgr::GetInst()->ImgLoad(L"Tutorial_6", L"Image\\Tutorial\\Tutorial6.bmp"));
	tutorialImages.push_back(ResMgr::GetInst()->ImgLoad(L"Tutorial_7", L"Image\\Tutorial\\Tutorial7.bmp"));
	tutorialImages.push_back(ResMgr::GetInst()->ImgLoad(L"Tutorial_8", L"Image\\Tutorial\\Tutorial8.bmp"));
	tutorialImages.push_back(ResMgr::GetInst()->ImgLoad(L"Tutorial_9", L"Image\\Tutorial\\Tutorial9.bmp"));
	tutorialImages.push_back(ResMgr::GetInst()->ImgLoad(L"Tutorial_10", L"Image\\Tutorial\\Tutorial10.bmp"));
	tutorialImages.push_back(ResMgr::GetInst()->ImgLoad(L"Tutorial_11", L"Image\\Tutorial\\Tutorial11.bmp"));
	tutorialImages.push_back(ResMgr::GetInst()->ImgLoad(L"Tutorial_12", L"Image\\Tutorial\\Tutorial12.bmp"));

	m_index = 0;
	maxIndex = 12;

	image = tutorialImages[m_index];

	SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	SetScale(Vec2(500, 300));

	leftBtn = make_shared<Button>();
	leftBtn->SetScale(Vec2(40, 40));
	leftBtn->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + 90, Core::GetInst()->GetResolution().y / 2 + 160));
	leftBtn->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");
	leftBtn->SetImageSize(Vec2(40, 40));
	leftBtn->SetCaption(L"이전");
	leftBtn->CreateCollider();

	rightBtn = make_shared<Button>();
	rightBtn->SetScale(Vec2(40, 40));
	rightBtn->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + 150, Core::GetInst()->GetResolution().y / 2 + 160));
	rightBtn->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");
	rightBtn->SetImageSize(Vec2(40, 40));
	rightBtn->SetCaption(L"다음");
	rightBtn->CreateCollider();

	closeBtn = make_shared<Button>();
	closeBtn->SetScale(Vec2(40, 40));
	closeBtn->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + 210, Core::GetInst()->GetResolution().y / 2 + 160));
	closeBtn->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");
	closeBtn->SetImageSize(Vec2(40, 40));
	closeBtn->SetCaption(L"닫기");
	closeBtn->CreateCollider();

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
			if (m_index-- == 0) {
				m_index = maxIndex;
			}
			image = tutorialImages[m_index];
		}
	}

	if (rightBtn->StayCollision(mouse)) {
		if (KEY_TAP(KEY::LBTN)) {
			// 다음 튜토리얼
			if (m_index++ == maxIndex) {
				m_index = 0;
			}
			image = tutorialImages[m_index];
		}
	}

	if (closeBtn->StayCollision(mouse)) {
		if (KEY_TAP(KEY::LBTN)) {
			itemTestScene->SetIsTutorial(false);
		}
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
