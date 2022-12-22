#pragma once
#include "Object.h"
class Image;
class AfterImage : public Object
{
public:
	AfterImage(Object* object);
	~AfterImage();

private:
	CLONE(AfterImage);

private:
	Object* object;
	float delay = 0.f;
	float time = 0.f;

public:
	void SetDelay(float delay);
	void Render(HDC _dc, Image* image, int alpha);
	void Render(HDC _dc) override;
	void Update() override;
};

