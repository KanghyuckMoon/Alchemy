#pragma once
#include "Scene.h"

class ItemBox;
class ItemTestScene :
    public Scene
{
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
public:
    ItemTestScene();
    virtual ~ItemTestScene();

    vector<ItemBox> itemBoxs;
};

