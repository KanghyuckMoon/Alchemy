#pragma once
#include "Object.h"
class Image;
class ClickEffect : public Object
{
public:
	ClickEffect();
	~ClickEffect();

private:
	CLONE(ClickEffect);

public:
	void SetClick(Vec2 click);

private:
	bool isClick = false;

public:
	void Render(HDC _dc, Image* image, int alpha);
	void Render(HDC _dc) override;
	void Update() override;
};
