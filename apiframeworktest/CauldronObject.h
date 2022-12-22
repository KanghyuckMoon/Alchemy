#pragma once
#include "Object.h"
class Image;
class ClickEffect;
class AfterImage;
class CauldronObject : public Object
{
	// Object을(를) 통해 상속됨
public:
	CauldronObject();
	virtual ~CauldronObject();

public:
	virtual void Update() override;
	virtual void Render(HDC _dc) override;

private:
	CLONE(CauldronObject);

private:
	bool isCanMix;
	Image* image;
	shared_ptr<ClickEffect> clickEffect;
	vector<shared_ptr<AfterImage>> afterImages;

public:
	void SetMix();
	void SetIsCanMix(bool mix) { isCanMix = mix; }
};

