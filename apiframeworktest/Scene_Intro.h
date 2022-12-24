#pragma once
#include "Scene.h"
class Button;

class Scene_Intro :
	public Scene
{
public:
	Scene_Intro();
	virtual ~Scene_Intro();

public:
	virtual void Enter() override;
	virtual void Exit() override;
	virtual void Update() override;
	virtual void Render(HDC _dc) override;
private:
	shared_ptr<Button> m_introBtn;

	int m_index;
};

