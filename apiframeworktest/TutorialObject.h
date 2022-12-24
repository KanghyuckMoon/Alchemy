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
	vector<Image*> tutorialImages;

	shared_ptr<	Button> leftBtn;
	shared_ptr<	Button> rightBtn;
	shared_ptr<	Button> closeBtn;

	ItemTestScene* itemTestScene;

	int m_index;
	int maxIndex;
};

