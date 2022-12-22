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
	m_index = 1;

	m_tutorialBtn = new Button();
	m_tutorialBtn->SetScale(Vec2(Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y));
	m_tutorialBtn->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));

	m_tutorialImage_1 = new Background(L"Intro_1", L"Image\\Tutorial\\Intro1.bmp");
	m_tutorialImage_2 = new Background(L"Intro_2", L"Image\\Tutorial\\Intro2.bmp");
	m_tutorialImage_3 = new Background(L"Intro_3", L"Image\\Tutorial\\Intro3.bmp");
	m_tutorialImage_4 = new Background(L"Intro_4", L"Image\\Tutorial\\Intro4.bmp");
	m_tutorialImage_5 = new Background(L"Intro_5", L"Image\\Tutorial\\Intro5.bmp");
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
			m_index++;

			if (m_index == 6) {
				ChangeScene(SCENE_TYPE::SCENE_MAIN);
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
	m_tutorialBtn->SetBackground(m_tutorialImage_1->GetImage());

	switch (m_index) {
	case 1:
		m_tutorialBtn->SetBackground(m_tutorialImage_1->GetImage());
		break;
	case 2:
		m_tutorialBtn->SetBackground(m_tutorialImage_2->GetImage());
		break;
	case 3:
		m_tutorialBtn->SetBackground(m_tutorialImage_3->GetImage());
		break;
	case 4:
		m_tutorialBtn->SetBackground(m_tutorialImage_4->GetImage());
		break;
	case 5:
		m_tutorialBtn->SetBackground(m_tutorialImage_5->GetImage());
		break;
	}
	m_tutorialBtn->Render(_dc);
}

