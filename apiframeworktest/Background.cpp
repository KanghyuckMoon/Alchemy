#include "pch.h"
#include "Background.h"
#include "Image.h"
#include "ResMgr.h"

Background::Background(const wstring& str, const wstring& path)
{
	SetPos(Vec2(320, 240));
	SetScale(Vec2(640, 480));
	SetImage(str, path);
}

void Background::Update()
{
}

void Background::Render(HDC _dc)
{
	TransparentBlt(_dc, 0, 0, 640, 480, backgroundImage->GetDC(), 0, 0, 640, 480, RGB(255, 0, 255));
}

void Background::SetImage(const wstring& str, const wstring& path)
{
	backgroundImage = ResMgr::GetInst()->ImgLoad(str, path);
}

void Background::SetImageSize(Vec2 vec2)
{
    imageSize = vec2;
}

Image* Background::GetImage()
{
	if (nullptr != this->backgroundImage)
		return this->backgroundImage;

	return nullptr;
}
