#pragma once
#include "Object.h"
class Image;
class Background : public Object
{
public:
	Background() {}
	Background(const wstring& str, const wstring& path);

private:
	Image* backgroundImage;

public:
	CLONE(Background);

private:
	Vec2 imageSize = { 640, 480 };

public:
	virtual void Update() override;
	virtual void Render(HDC _dc) override;
	void SetImage(const wstring& str, const wstring& path);
	void SetImage(Image* image);
	Image* GetImage();
	void SetImageSize(Vec2 vec2);
};

