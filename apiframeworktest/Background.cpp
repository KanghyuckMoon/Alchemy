#include "pch.h"
#include "Background.h"
#include "Image.h"
#include "ResMgr.h"


Background::Background(const wstring& str, const wstring& path)
{
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
