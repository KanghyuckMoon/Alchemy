#include "pch.h"
#include "ItemTestScene.h"
#include "Object.h"
#include "Player.h"
#include "Monster.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "ItemBox.h"
#include "SOManager.h"
#include "Background.h"

ItemTestScene::ItemTestScene()
{
}

ItemTestScene::~ItemTestScene()
{
}
void ItemTestScene::Enter()
{
	SOManager::GetInst()->Init();
	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\pianobgm.wav");
	SoundMgr::GetInst()->Play(L"BGM");
	m_Background = new Background(L"Background1", L"Image\\Background\\background1.bmp");

	Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));
	int iItem = 8;
	float fMoveDist = 10.f;
	float fObjScale = 100.f;
	float fTerm = (640 / iItem);
	ItemBox* itemObj = nullptr;
	for (int i = 0; i < iItem; i++)
	{
		itemObj = new ItemBox(L"³ª¹«");
		itemObj->SetName(L"ItemBox");
		itemObj->SetPos(Vec2((fMoveDist + fObjScale / 2.f) + (float)i * fTerm, 480 - fObjScale));
		itemObj->SetScale(Vec2(fObjScale, fObjScale));
		AddObject(itemObj, GROUP_TYPE::MONSTER);
	}

}

void ItemTestScene::Exit()
{
	DeleteAll();
}

void ItemTestScene::Update()
{
	Scene::Update();
}

void ItemTestScene::Render(HDC _dc)
{
	m_Background->Render(_dc);
	Scene::Render(_dc);
}