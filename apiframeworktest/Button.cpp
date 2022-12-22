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
	TransparentBlt(_dc,
		GetPos().x - GetScale().x / 2,
		GetPos().x - GetScale().x / 2,
		GetScale().x,
		GetScale().y,
		backgroundImage->GetDC(), 0, 0, GetScale().x, GetScale().y, RGB(255, 0, 255));
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
