#include "pch.h"
#include "CharacterImage.h"
#include "Image.h"
#include "Core.h"
#include "TimeMgr.h"

CharacterImage::CharacterImage()
{
}

CharacterImage::~CharacterImage()
{
}

void CharacterImage::SetIsSpot(bool spot)
{
	if (isSpot != spot)
	{
		time = 0.f;
	}

	this->isSpot = spot;
	if (isSpot)
	{
		alpha = 255;
	}
	else
	{
		alpha = 100;
	}
}

void CharacterImage::Update()
{
	float multiple = 0.5f;
	if (time < multiple)
	{
		time += TimeMgr::GetInst()->GetDT();
	}
	else
	{
		return;
	}

	if (isSpot)
	{
		SetScale(Vec2(LERP(128, 256, time / multiple), LERP(128, 256, time / multiple)));
		SetPos(Vec2(LERP(targetPos.x, originPos.x, time / multiple), LERP(targetPos.y, originPos.y, time / multiple)));
	}
	else
	{
		SetScale(Vec2(LERP(256, 128, time / multiple), LERP(256, 128, time / multiple)));
		SetPos(Vec2(LERP(originPos.x, targetPos.x, time / multiple), LERP(originPos.y, targetPos.y, time / multiple)));
	}
}

void CharacterImage::Render(HDC _dc)
{
	if (image)
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
}
