#include "pch.h"
#include "Scene_Ending.h"
#include "Background.h"
#include "ResMgr.h"
#include "Core.h"
#include "Button.h"
#include "KeyMgr.h"
#include "Image.h"

Scene_Ending::Scene_Ending() : m_index(0)
{
}

Scene_Ending::~Scene_Ending()
{
}

void Scene_Ending::Enter()
{
	m_endingBtn = new Button();
	m_endingBtn->SetScale(Vec2(Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y));
	m_endingBtn->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	m_endingBtn->SetImageSize(Vec2(Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y));
	m_endingBtn->SetImage(L"Ending_1", L"Image\\Ending\\Ending1.bmp");

	m_index = 1;
}

void Scene_Ending::Exit()
{
}

void Scene_Ending::Update()
{
	POINT mouse;
	GetCursorPos(&mouse);
	ScreenToClient(Core::GetInst()->GetWndHandle(), &mouse);
	KEY_STATE key = KeyMgr::GetInst()->GetKey(KEY::LBTN);


	if (m_endingBtn->StayCollision(mouse)) {
		if (key == KEY_STATE::TAP) {
			switch (++m_index) {
			case 1:
				m_endingBtn->SetImage(L"Ending_1", L"Image\\Ending\\Ending1.bmp");
				break;
			case 2:
				m_endingBtn->SetImage(L"Ending_2", L"Image\\Ending\\Ending2.bmp");
				break;
			case 3:
				m_endingBtn->SetImage(L"Ending_3", L"Image\\Ending\\Ending3.bmp");
				break;
			case 4:
				m_endingBtn->SetImage(L"Ending_4", L"Image\\Ending\\Ending4.bmp");
				break;
			case 5:
				m_endingBtn->SetImage(L"Ending_5", L"Image\\Ending\\Ending5.bmp");
				break;
			case 6:
				m_endingBtn->SetImage(L"Ending_6", L"Image\\Ending\\Ending6.bmp");
				break;
			case 7:
				m_endingBtn->SetImage(L"Ending_7", L"Image\\Ending\\Ending7.bmp");
				break;
			case 8:
				m_endingBtn->SetImage(L"Ending_8", L"Image\\Ending\\Ending8.bmp");
				break;
			default:
				
				break;
			}
		}
		else if (key == KEY_STATE::AWAY) {

		}
	}
	else {

	}
}

void Scene_Ending::Render(HDC _dc)
{
	m_endingBtn->Render(_dc);
}
