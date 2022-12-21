#include "pch.h"
#include "Core.h"
#include "Scene_Lobby.h"
#include "KeyMgr.h"
#include "Button.h"

Scene_Lobby::Scene_Lobby()
{
}

Scene_Lobby::~Scene_Lobby()
{
}

void Scene_Lobby::Enter()
{

}

void Scene_Lobby::Exit()
{
}

void Scene_Lobby::Update()
{
	Button button_1;
	button_1.SetScale(Vec2(220, 50));
	button_1.SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 + 50));
	button_1.Render(Core::GetInst()->GetMainDC());
	button_1.CreateCollider();

	Button button_2;
	button_2.SetScale(Vec2(220, 50));
	button_2.SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 + 130));
	button_2.Render(Core::GetInst()->GetMainDC());
	button_2.CreateCollider();

	POINT mouse;
	GetCursorPos(&mouse);
	ScreenToClient(Core::GetInst()->GetWndHandle(), &mouse);

	KEY_STATE key = KeyMgr::GetInst()->GetKey(KEY::LBTN);

	if (button_1.StayCollision(mouse)) {
		if (key == KEY_STATE::TAP) {
			ChangeScene(SCENE_TYPE::SCENE_TUTORIAL);
		}
		else if (key == KEY_STATE::AWAY) {

		}
	}
	else {

	}

	if (button_2.StayCollision(mouse)) {
		if (key == KEY_STATE::TAP) {

		}
		else if (key == KEY_STATE::AWAY) {

		}
	}
	else {

	}
}
