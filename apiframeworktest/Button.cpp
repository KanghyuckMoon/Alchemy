#include "pch.h"
#include "Button.h"

void Button::Update()
{
}

Object* Button::Clone()
{
    return nullptr;
}

bool Button::StayCollision(POINT ps)
{
    RECT rt = {
        GetPos().x - GetScale().x/2,
        GetPos().y - GetScale().y/2,
        GetPos().x + GetScale().x/2,
        GetPos().y + GetScale().y/2,
    };

    if ((rt.left < ps.x && ps.x < rt.right && rt.top < ps.y && ps.y < rt.bottom)) {
        return true;
    }

    return false;
}
