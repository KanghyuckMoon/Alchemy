#pragma once
#include "Object.h"
class Image;
class Background : public Object
{
public:
	Background(const wstring& str, const wstring& path);

private:
	Image* backgroundImage;

public:
	CLONE(Background);

public:
	virtual void Update() override;
	virtual void Render(HDC _dc) override;
	void SetImage(const wstring& str, const wstring& path);
};

