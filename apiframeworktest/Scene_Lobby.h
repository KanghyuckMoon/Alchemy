#pragma once
#include "Scene.h"
#include "Background.h"
class Button;

class Scene_Lobby :
	public Scene
{
private:
public:
	Scene_Lobby();
	virtual ~Scene_Lobby();
public:
	virtual void Enter() override;
	virtual void Exit() override;
	virtual void Update() override;
	virtual void Render(HDC _dc) override;

public:
	shared_ptr<Button> button_1;
	shared_ptr<Button> button_2;

	Background m_background;
};
