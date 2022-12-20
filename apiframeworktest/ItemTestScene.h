#pragma once
#include "Scene.h"

class ItemBox;
class Background;
class Inventory;
class ItemMix;
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

public:
    void InventoryFetch();

    ItemMix* itemMix;
    vector<ItemBox> itemBoxs;
    Background* m_Background;
};

