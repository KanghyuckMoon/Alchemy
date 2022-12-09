#pragma once
#include "Scene.h"
class Scene_Main :
    public Scene
{
private:
public:
    Scene_Main();
    virtual ~Scene_Main();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};

