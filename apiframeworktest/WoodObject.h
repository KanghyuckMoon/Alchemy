#pragma once
#include "Object.h"
class Image;
class AfterImage;
class ClickEffect;
class WoodObject : public Object
{
	// Object��(��) ���� ��ӵ�
public:
	WoodObject();
	virtual ~WoodObject();

public:
	virtual void Update() override;
	virtual void Render(HDC _dc) override;

private:
	CLONE(WoodObject);

private:
	Image* image;
	shared_ptr<ClickEffect> clickEffect;
	vector<shared_ptr<AfterImage>> afterImages;

public:
	bool	StayCollision(POINT ps);
};

