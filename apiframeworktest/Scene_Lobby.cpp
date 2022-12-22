#include "pch.h"
#include "Core.h"
#include "Scene_Lobby.h"
#include "KeyMgr.h"
#include "Button.h"
#include "Background.h"

Scene_Lobby::Scene_Lobby()
{
}

Scene_Lobby::~Scene_Lobby()
{
}

void Scene_Lobby::Enter()
{
	m_background = Background(L"Title", L"Image\\Background\\Title.bmp");

	button_1 = new Button();
	button_1->SetScale(Vec2(150, 40));
	button_1->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 - 200, Core::GetInst()->GetResolution().y / 2 + 100));
	button_1->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");
	button_1->SetImageSize(Vec2(150, 40));
	button_1->SetCaption(L"Start");
	button_1->CreateCollider();

	button_2 = new Button();
	button_2->SetScale(Vec2(150, 40));
	button_2->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + 200, Core::GetInst()->GetResolution().y / 2 + 100));
	button_2->SetImage(L"ButtonBMP150-40", L"Image\\Background\\ButtonBMP150-40.bmp");
	button_2->SetImageSize(Vec2(150, 40));
	button_2->SetCaption(L"Close");
	button_2->CreateCollider();
}

void Scene_Lobby::Exit()
{
}

void Scene_Lobby::Update()
{
	POINT mouse;
	GetCursorPos(&mouse);
	ScreenToClient(Core::GetInst()->GetWndHandle(), &mouse);

	KEY_STATE key = KeyMgr::GetInst()->GetKey(KEY::LBTN);

	if (button_1->StayCollision(mouse)) {
		if (key == KEY_STATE::TAP) {
			ChangeScene(SCENE_TYPE::SCENE_TUTORIAL);
		}
		else if (key == KEY_STATE::AWAY) {

		}
	}
	else {

	}

	if (button_2->StayCollision(mouse)) {
		if (key == KEY_STATE::TAP) {
			Core::GetInst()->Close();
		}
		else if (key == KEY_STATE::AWAY) {

		}
	}
	else {

	}
}

void Scene_Lobby::Render(HDC _dc)
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


	m_background.Render(_dc);

	button_1->Render(_dc);
	button_2->Render(_dc);

	DeleteObject(s_hFont);
}
