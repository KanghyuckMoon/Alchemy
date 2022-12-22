#pragma once
#include "Scene.h"

class Button;

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
	virtual void Render(HDC _dc) override;
private:
	Button* m_endingBtn;
	int m_index;
};

