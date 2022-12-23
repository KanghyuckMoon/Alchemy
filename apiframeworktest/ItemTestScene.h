#pragma once
#include "Scene.h"

class ItemBox;
class Background;
class Inventory;
class ItemMix;
class ItemTree;
class Button;
class Image;
class ItemCaptionWindow;
class WoodObject;
class CutScene;
class ItemMoveEffect;
class CauldronObject;

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
    shared_ptr<ItemTree> itemTree;

    //Left Right
    shared_ptr<Button> leftSceneButton;
    shared_ptr<Button> rightSceneButton;

    //Tutorial
    shared_ptr<Button> tutorialButton;

    //CutScene
    shared_ptr<CutScene> cutScene;

    //Default
    shared_ptr<WoodObject> woodObject;
    shared_ptr<CauldronObject> cauldronObject;

    //ItemMix
    shared_ptr<ItemMix> itemMix;
    shared_ptr<Button> mixButton;
    shared_ptr<Button> cancleButton;

    shared_ptr<Background> inventoryWindow;
    shared_ptr<ItemCaptionWindow> itemCaptionWindow;

    vector<ItemBox> itemBoxs;
    shared_ptr<vector<shared_ptr<ItemMoveEffect>>> itemMoveEffects;
    shared_ptr<Background> m_Background_DefaultMode;
    shared_ptr<Background> m_Background_MixMode;
    shared_ptr<Background> m_Background_ExchangeMode;
    shared_ptr<Background> m_Background_ItemTreeMode;
    shared_ptr<Background> m_Background_DeleteMode;
};

