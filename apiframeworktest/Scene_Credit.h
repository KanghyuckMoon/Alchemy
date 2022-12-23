#pragma once
#include "Scene.h"

class TutorialObject;

class Scene_Credit :
	public Scene
{
public:
	Scene_Credit();
	virtual ~Scene_Credit();
public:
	virtual void Enter() override;
	virtual void Exit() override;
	virtual void Update() override;
	virtual void Render(HDC _dc) override;

	void SetIsTutorial(bool _isTutorial) { isTutorial = _isTutorial; }

private:
	bool isTutorial;
	TutorialObject* tutorialObject;
};

