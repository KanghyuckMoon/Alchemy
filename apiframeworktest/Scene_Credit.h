#pragma once
#include "Scene.h"

class TextObject;

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

private:
	float time = 0.f;

private:
	TextObject* textObj;

};
