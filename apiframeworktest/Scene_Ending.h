#pragma once
#include "Scene.h"
class Scene_Ending :
    public Scene
{
private:
public:
    Scene_Ending();
    virtual ~Scene_Ending();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};

