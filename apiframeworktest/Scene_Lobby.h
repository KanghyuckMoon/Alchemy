#pragma once
#include "Scene.h"
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
	Button* button_1;
	Button* button_2;
};
