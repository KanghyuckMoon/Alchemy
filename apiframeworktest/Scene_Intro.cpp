#include "pch.h"
#include "Scene_Intro.h"
#include "Background.h"
#include "ResMgr.h"
#include "Core.h"
#include "Button.h"
#include "KeyMgr.h"
#include "Image.h"
#include "SoundMgr.h"

Scene_Intro::Scene_Intro()
{
}

Scene_Intro::~Scene_Intro()
{
}

void Scene_Intro::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"INTROBGM", true, L"Sound\\FALLING-SLOWLY.wav");
	SoundMgr::GetInst()->Play(L"INTROBGM");

	m_introBtn = make_shared<Button>();
	m_introBtn->SetScale(Vec2(Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y));
	m_introBtn->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	m_introBtn->SetImageSize(Vec2(Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y));
	m_introBtn->SetImage(L"Intro_1", L"Image\\Intro\\Intro1.bmp");

	m_index = 1;
}

void Scene_Intro::Exit()
{
	SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
}

void Scene_Intro::Update()
{
	POINT mouse;
	GetCursorPos(&mouse);
	ScreenToClient(Core::GetInst()->GetWndHandle(), &mouse);
	KEY_STATE key = KeyMgr::GetInst()->GetKey(KEY::LBTN);

	if (m_introBtn->StayCollision(mouse)) {
		if (key == KEY_STATE::TAP) {
			switch (++m_index) {
			case 1:
				m_introBtn->SetImage(L"Intro_1", L"Image\\Intro\\Intro1.bmp");
				break;
			case 2:
				m_introBtn->SetImage(L"Intro_2", L"Image\\Intro\\Intro2.bmp");
				break;
			case 3:
				m_introBtn->SetImage(L"Intro_3", L"Image\\Intro\\Intro3.bmp");
				break;
			case 4:
				m_introBtn->SetImage(L"Intro_4", L"Image\\Intro\\Intro4.bmp");
				break;
			case 5:
				m_introBtn->SetImage(L"Intro_5", L"Image\\Intro\\Intro5.bmp");
				break;
			default:
				ChangeScene(SCENE_TYPE::SCENE_MAIN);
				break;
			}
		}
		else if (key == KEY_STATE::AWAY) {

		}
	}
	else {

	}
}

void Scene_Intro::Render(HDC _dc)
{
	m_introBtn->Render(_dc);
}
