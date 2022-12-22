#pragma once
#include "Scene.h"

class Background;
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

	Background* m_tutorialImage_1 = {};
	Background* m_tutorialImage_2 = {};
	Background* m_tutorialImage_3 = {};
	Background* m_tutorialImage_4 = {};
	Background* m_tutorialImage_5 = {};

	int m_index;
};

