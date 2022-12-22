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
	TransparentBlt(_dc, 
		GetPos().x - GetScale().x / 2,
		GetPos().y - GetScale().y / 2,
		GetScale().x,
		GetScale().y,
		backgroundImage->GetDC(), 0, 0, imageSize.x, imageSize.y, RGB(255, 0, 255));
}

void Background::SetImage(const wstring& str, const wstring& path)
{
	backgroundImage = ResMgr::GetInst()->ImgLoad(str, path);
}

void Background::SetImage(Image* image)
{
	backgroundImage = image;
}

Image* Background::GetImage()
{
	return backgroundImage;
}

void Background::SetImageSize(Vec2 vec2)
{
	imageSize = vec2;
}
