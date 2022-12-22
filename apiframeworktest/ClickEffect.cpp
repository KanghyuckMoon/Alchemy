#include "pch.h"
#include "ClickEffect.h"
#include "Object.h"
#include "Image.h"
#include "Core.h"
#include "TimeMgr.h"


ClickEffect::ClickEffect()
{
}

ClickEffect::~ClickEffect()
{
}

void ClickEffect::SetClick(Vec2 click)
{
	SetScale(Vec2(0, 0));
	SetPos(click);
	isClick = true;
}

void ClickEffect::Render(HDC _dc, Image* image, int alpha)
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
void ClickEffect::Render(HDC _dc)
{
}
void ClickEffect::Update()
{
	if (isClick)
	{
		SetScale(Vec2(GetScale().x + 20, GetScale().y + 20));

		if (GetScale().x > 300)
		{
			isClick = false;
			SetScale(Vec2(0, 0));
		}
	}
}