#include "pch.h"
#include "Scene_Tutorial.h"
#include "Background.h"
#include "ResMgr.h"
#include "Core.h"
#include "Button.h"
#include "KeyMgr.h"
#include "Image.h"

Scene_Tutorial::Scene_Tutorial() : m_index(0)
{
}

Scene_Tutorial::~Scene_Tutorial()
{
}

void Scene_Tutorial::Enter()
{
	m_tutorialBtn = new Button();
	m_tutorialBtn->SetScale(Vec2(Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y));
	m_tutorialBtn->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	m_tutorialBtn->SetImageSize(Vec2(Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y));
	m_tutorialBtn->SetImage(L"Intro_1", L"Image\\Tutorial\\Intro1.bmp");

	m_index = 1;
}

void Scene_Tutorial::Exit()
{
}

void Scene_Tutorial::Update()
{
	POINT mouse;
	GetCursorPos(&mouse);
	ScreenToClient(Core::GetInst()->GetWndHandle(), &mouse);
	KEY_STATE key = KeyMgr::GetInst()->GetKey(KEY::LBTN);

	if (m_tutorialBtn->StayCollision(mouse)) {
		if (key == KEY_STATE::TAP) {
			switch (++m_index) {
			case 1:
				m_tutorialBtn->SetImage(L"Intro_1", L"Image\\Tutorial\\Intro1.bmp");
				break;
			case 2:
				m_tutorialBtn->SetImage(L"Intro_2", L"Image\\Tutorial\\Intro2.bmp");
				break;
			case 3:
				m_tutorialBtn->SetImage(L"Intro_3", L"Image\\Tutorial\\Intro3.bmp");
				break;
			case 4:
				m_tutorialBtn->SetImage(L"Intro_4", L"Image\\Tutorial\\Intro4.bmp");
				break;
			case 5:
				m_tutorialBtn->SetImage(L"Intro_5", L"Image\\Tutorial\\Intro5.bmp");
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

void Scene_Tutorial::Render(HDC _dc)
{
	m_tutorialBtn->Render(_dc);
}

