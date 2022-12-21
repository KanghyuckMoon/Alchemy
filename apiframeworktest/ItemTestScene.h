#pragma once
#include "Scene.h"

class ItemBox;
class Background;
class Inventory;
class ItemMix;
class ItemTree;
//class Button;

enum class ItemMode : int
{
    DEFAULTMODE,
    MIXMODE,
    EXCHANGEMODE,
    ITEMTREEMODE,
    DELETEMODE,
};

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

private:
    ItemMode itemMode;
    ItemTree* itemTree;

    //ItemMix
    ItemMix* itemMix;
    //Button* mixButton;
    //Button* cancleButton;

    vector<ItemBox> itemBoxs;
    Background* m_Background_DefaultMode;
    Background* m_Background_MixMode;
    Background* m_Background_ExchangeMode;
    Background* m_Background_ItemTreeMode;
    Background* m_Background_DeleteMode;
};

