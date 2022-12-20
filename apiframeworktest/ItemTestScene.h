#pragma once
#include "Scene.h"

class ItemBox;
class Background;
class ItemTestScene :
    public Scene
{
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
public:
    ItemTestScene();
    virtual ~ItemTestScene();

    vector<ItemBox> itemBoxs;
    Background* m_Background;
};

