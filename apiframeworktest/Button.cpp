#include "pch.h"
#include "Button.h"
#include "Image.h"
#include "ResMgr.h"
#include "Background.h"

void Button::Update()
{
}

Object* Button::Clone()
{
	return nullptr;
}

void Button::Render(HDC _dc)
{
	if (backgroundImage)
	{
		TransparentBlt(_dc,
			GetPos().x - GetScale().x / 2,
			GetPos().y - GetScale().y / 2,
			GetScale().x,
			GetScale().y,
			backgroundImage->GetDC(), 0, 0, imageSize.x, imageSize.y, RGB(255, 0, 255));
	}

	if (m_caption != L"") {
		SetTextAlign(_dc, TA_CENTER | TA_TOP);
		TextOut(_dc, GetPos().x, GetPos().y -10, m_caption.c_str(), m_caption.length());
	}
}

bool Button::StayCollision(POINT ps)
{
	RECT rt = {
		GetPos().x - GetScale().x / 2,
		GetPos().y - GetScale().y / 2,
		GetPos().x + GetScale().x / 2,
		GetPos().y + GetScale().y / 2,
	};

	if ((rt.left < ps.x && ps.x < rt.right && rt.top < ps.y && ps.y < rt.bottom)) {
		return true;
	}

	return false;
}

void Button::SetImage(const wstring& str, const wstring& path)
{
	backgroundImage = ResMgr::GetInst()->ImgLoad(str, path);
}

void Button::SetImageSize(Vec2 vec2)
{
	imageSize = vec2;
}
