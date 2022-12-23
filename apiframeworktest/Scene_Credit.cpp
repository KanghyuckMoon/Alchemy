#include "pch.h"
#include "Scene_Credit.h"
#include "Core.h"
#include "TutorialObject.h"

Scene_Credit::Scene_Credit()
{
}

Scene_Credit::~Scene_Credit()
{
}

void Scene_Credit::Enter()
{
	// Å©·¹µ÷ 
	tutorialObject = new TutorialObject();
	tutorialObject->SetSceneCredit(this);
	isTutorial = true;
}

void Scene_Credit::Exit()
{
}

void Scene_Credit::Update()
{
	if (isTutorial) {
		tutorialObject->Update();
	}
}

void Scene_Credit::Render(HDC _dc)
{
	if (isTutorial) {
		tutorialObject->Render(_dc);
	}
}
