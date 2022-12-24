#include "pch.h"
#include "TextObject.h"
#include "Core.h"

TextObject::TextObject()
{

	SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y));
	SetScale(Vec2(200, 200));
}

TextObject::~TextObject()
{
}

void TextObject::Update()
{
	SetPos(Vec2(GetPos().x + x, GetPos().y + y));
}

void TextObject::Render(HDC _dc)
{
	SetBkMode(_dc, TRANSPARENT);

	HFONT s_hFont = (HFONT)NULL;
	HFONT s_oldHFont = (HFONT)NULL;
	LOGFONT logFont;
	ZeroMemory(&logFont, sizeof(LOGFONT));

	logFont.lfHeight = -MulDiv(10, GetDeviceCaps(_dc, LOGPIXELSY), 50);
	logFont.lfWeight = FW_NORMAL;
	SetTextColor(_dc, RGB(255, 255, 255));
	wcscpy_s(logFont.lfFaceName, TEXT("DungGeunMo"));
	s_hFont = CreateFontIndirect(&logFont);
	s_oldHFont = (HFONT)SelectObject(_dc, s_hFont);

	SetTextAlign(_dc, TA_CENTER | TA_TOP);
	TextOut(_dc, GetPos().x, GetPos().y - 10, creditText.c_str(), creditText.length());

	DeleteObject(s_hFont);
}
