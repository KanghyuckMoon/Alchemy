#include "pch.h"
#include "Scene_Tutorial.h"
#include "Background.h"
#include "ResMgr.h"
#include "Core.h"

Scene_Tutorial::Scene_Tutorial()
{
}

Scene_Tutorial::~Scene_Tutorial()
{
}

void Scene_Tutorial::Enter()
{
	m_tutorial = new Background(L"Background_tutorial", L"Image\\Background\\background1.bmp");
}

void Scene_Tutorial::Exit()
{
}

void Scene_Tutorial::Update()
{
	
}

void Scene_Tutorial::Render(HDC _dc)
{
	m_tutorial->Render(_dc);
}

