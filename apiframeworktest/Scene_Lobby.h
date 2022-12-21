#pragma once
#include "Scene.h"
class Scene_Lobby :
    public Scene
{
private:
public:
    Scene_Lobby();
    virtual ~Scene_Lobby();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};
    