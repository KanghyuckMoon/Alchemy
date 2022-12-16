#include "pch.h"
#include "Core.h"
#include "Scene_Lobby.h"
#include "KeyMgr.h"

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
	RECT button_1 = {
		Core::GetInst()->GetResolution().x / 2 - 110,
		Core::GetInst()->GetResolution().y / 2 + 20,
		Core::GetInst()->GetResolution().x / 2 + 110,
		Core::GetInst()->GetResolution().y / 2 + 70
	};
	Rectangle(Core::GetInst()->GetMainDC(), button_1.left, button_1.top, button_1.right, button_1.bottom);

	RECT button_2 = {
		Core::GetInst()->GetResolution().x / 2 - 110,
		Core::GetInst()->GetResolution().y / 2 + 90,
		Core::GetInst()->GetResolution().x / 2 + 110,
		Core::GetInst()->GetResolution().y / 2 + 140
	};
	Rectangle(Core::GetInst()->GetMainDC(), button_2.left, button_2.top, button_2.right, button_2.bottom);

	POINT mouse;
	GetCursorPos(&mouse);
	ScreenToClient(Core::GetInst()->GetWndHandle(), &mouse);

	if (KeyMgr::GetInst()->GetKey(KEY::LBTN) == KEY_STATE::HOLD) {

		if ((button_1.left < mouse.x && mouse.x < button_1.right && button_1.top < mouse.y && mouse.y < button_1.bottom)) {
			ChangeScene(SCENE_TYPE::SCENE_MAIN);
		}
		else if ((button_2.left < mouse.x && mouse.x < button_2.right && button_2.top < mouse.y && mouse.y < button_2.bottom)) {
			Core::GetInst()->Close();
		}

	}
	else {
	}
}
