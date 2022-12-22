#pragma once
#include "Scene.h"

class Button;

class Scene_Tutorial :
	public Scene
{
private:
public:
	Scene_Tutorial();
	virtual ~Scene_Tutorial();
public:
	virtual void Enter() override;
	virtual void Exit() override;
	virtual void Update() override;
	virtual void Render(HDC _dc) override;
private:
	Button* m_tutorialBtn;

	int m_index;
};

