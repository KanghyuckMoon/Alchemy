#include "pch.h"
#include "AfterImage.h"
#include "Object.h"
#include "Image.h"
#include "Core.h"
#include "TimeMgr.h"


AfterImage::AfterImage(Object* object)
{
	this->object = object;
}

AfterImage::~AfterImage()
{
}

void AfterImage::Render(HDC _dc, Image* image, int alpha)
{
	RECT rect;
	GetClientRect(Core::GetInst()->GetWndHandle(), &rect);

	BLENDFUNCTION _bf;
	memset(&_bf, 0, sizeof(_bf));
	_bf.SourceConstantAlpha = alpha;

	HDC MemDC = CreateCompatibleDC(_dc); 
	HDC AlphaDC = CreateCompatibleDC(_dc);
	HBITMAP hBitmap = CreateCompatibleBitmap(_dc, 640, 480);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(MemDC, hBitmap);

	HBITMAP hBitmap2 = CreateCompatibleBitmap(_dc, 640, 480);
	HBITMAP hOldBitmap2 = (HBITMAP)SelectObject(AlphaDC, hBitmap2);
	
	FillRect(MemDC, &rect, GetSysColorBrush(COLOR_BACKGROUND));
	BitBlt(MemDC, 0, 0, rect.right, rect.bottom, _dc, 0, 0, SRCCOPY);
	BitBlt(AlphaDC, 0, 0, rect.right, rect.bottom, MemDC, 0, 0, SRCCOPY);
	TransparentBlt(AlphaDC, GetPos().x - (GetScale().x / 2), GetPos().y - (GetScale().y / 2), GetScale().x, GetScale().y, image->GetDC(), 0, 0, image->GetWidth(), image->GetHeight(), RGB(255, 0, 255));
	AlphaBlend(MemDC, GetPos().x - (GetScale().x / 2), GetPos().y - (GetScale().y / 2), GetScale().x, GetScale().y, AlphaDC, GetPos().x - (GetScale().x / 2), GetPos().y - (GetScale().y / 2), GetScale().x, GetScale().y, _bf);
	BitBlt(_dc, 0, 0, rect.right, rect.bottom, MemDC, 0, 0, SRCCOPY);


	SelectObject(MemDC, hOldBitmap);
	SelectObject(AlphaDC, hOldBitmap2);
	DeleteObject(hBitmap);
	DeleteObject(hBitmap2);
	DeleteDC(MemDC);
	DeleteDC(AlphaDC);
}
void AfterImage::Render(HDC _dc)
{
}
void AfterImage::Update()
{
	if (time < delay)
	{
		time += TimeMgr::GetInst()->GetDT();
	}
	else
	{
		time = 0.f;
		Vec2 vec = object->GetPos();
		SetPos(vec);
	}
}

void AfterImage::SetDelay(float delay)
{
	this->delay = delay;
}