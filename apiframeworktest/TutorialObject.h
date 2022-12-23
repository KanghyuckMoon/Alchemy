#pragma once
#include"Object.h"
#include "Button.h"

class Scene_Credit;

class TutorialObject : public Object
{
public:
	TutorialObject();
	virtual ~TutorialObject();

public:
	virtual void Update() override;
	virtual void Render(HDC _dc) override;

	void SetSceneCredit(Scene_Credit* _scene_credit) { scene_credit = _scene_credit; }


private:
	CLONE(TutorialObject);

private:
	Image* image;
	Button* leftBtn;
	Button* rightBtn;
	Button* closeBtn;

	Scene_Credit* scene_credit;

	int m_index;
	int maxIndex;
};

