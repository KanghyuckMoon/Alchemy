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
#include "SOManager.h"
#include "ItemData.h"
#include "ItemSO.h"


ItemTestScene::ItemTestScene()
{
}

ItemTestScene::~ItemTestScene()
{
}
void ItemTestScene::Enter()
{
	SOManager::GetInst()->Init();
}

void ItemTestScene::Exit()
{
	//DeleteAll();
	//CollisionMgr::GetInst()->CheckReset();
}

void ItemTestScene::Update()
{
	//Scene::Update();
	//if (KEY_TAP(KEY::ENTER))
	//{
	//	ChangeScene(SCENE_TYPE::SCENE_01);
	//}
	shared_ptr<ItemData> itemData = ItemSO::GetInst()->GetItemData(L"Postion");
	wstring str = itemData->GetText();
	TextOutW(Core::GetInst()->GetMainDC(), 100, 100, str.c_str(), str.length());
}
