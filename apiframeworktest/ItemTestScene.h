#pragma once
#include "Scene.h"
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
};

