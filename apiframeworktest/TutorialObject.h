#pragma once
#include"Object.h"
#include "Button.h"

class ItemTestScene;

class TutorialObject : public Object
{
public:
	TutorialObject();
	virtual ~TutorialObject();

public:
	virtual void Update() override;
	virtual void Render(HDC _dc) override;

	void SetScene(ItemTestScene* _itemTestScene) { itemTestScene = _itemTestScene; }


private:
	CLONE(TutorialObject);

private:
	Image* image;
	Image* tutorialImage_0;
	Image* tutorialImage_1;
	Image* tutorialImage_2;
	Image* tutorialImage_3;
	Image* tutorialImage_4;
	Image* tutorialImage_5;
	Image* tutorialImage_6;
	Image* tutorialImage_7;
	Image* tutorialImage_8;
	Image* tutorialImage_9;
	Image* tutorialImage_10;
	Image* tutorialImage_11;
	Image* tutorialImage_12;



	Button* leftBtn;
	Button* rightBtn;
	Button* closeBtn;

	ItemTestScene* itemTestScene;

	int m_index;
	int maxIndex;
};

