#pragma once
#include "Scene.h"
class Scene_Tutorial :
    public Scene
{
private:
public:
    Scene_Tutorial();
    virtual ~Scene_Tutorial();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};

