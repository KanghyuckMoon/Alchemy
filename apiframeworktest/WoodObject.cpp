#include "pch.h"
#include "WoodObject.h"
#include "Image.h"
#include "ResMgr.h"
#include "AfterImage.h"
#include "TimeMgr.h"
#include "ClickEffect.h"

WoodObject::WoodObject()
{
    image = ResMgr::GetInst()->ImgLoad(L"WoodImage", L"Image\\Background\\woodImage.bmp");
    SetPos(Vec2(320, 240));
    SetScale(Vec2(200, 200));

    shared_ptr<AfterImage> afterImage;
    
    for (int i = 1; i < 6; ++i)
    {
        afterImage = make_shared<AfterImage>(this);
        afterImage->SetPos(Vec2(1000, 1000));
        afterImage->SetScale(Vec2(200, 200));
        afterImage->SetDelay((float)i * 0.15f);
        afterImages.push_back(afterImage);
    }

    clickEffect = make_shared<ClickEffect>();

}

WoodObject::~WoodObject()
{
}

void WoodObject::Update()
{
    static bool isLeftMove = true;

    for (auto& after : afterImages)
    {
        after->Update();
    }

    if (isLeftMove)
    {
        SetPos(Vec2(GetPos().x - 1.5f, GetPos().y));
        if (GetPos().x < 160)
        {
            isLeftMove = false;
        }
    }
    else
    {
        SetPos(Vec2(GetPos().x + 1.5f, GetPos().y));
        if (GetPos().x > 480)
        {
            isLeftMove = true;
        }
    }

    clickEffect->Update();
}

void WoodObject::Render(HDC _dc)
{
    for (auto& after : afterImages)
    {
        after->Render(_dc, image, 100);
    }
    TransparentBlt(_dc, GetPos().x - (GetScale().x / 2), GetPos().y - (GetScale().y / 2), GetScale().x, GetScale().y, image->GetDC(), 0, 0, image->GetWidth(), image->GetHeight(), RGB(255, 0, 255));
    clickEffect->Render(_dc, image, 100);
}

bool WoodObject::StayCollision(POINT ps)
{
    RECT rt = {
        GetPos().x - GetScale().x / 2,
        GetPos().y - GetScale().y / 2,
        GetPos().x + GetScale().x / 2,
        GetPos().y + GetScale().y / 2,
    };

    if ((rt.left < ps.x && ps.x < rt.right && rt.top < ps.y && ps.y < rt.bottom)) {
        clickEffect->SetClick(GetPos());
        return true;
    }

    return false;
}
