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
#include "SpriteSO.h"
#include "Image.h"
#include "Inventory.h"
#include "RecipeSO.h"


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
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		//ChangeScene(SCENE_TYPE::SCENE_01);
		Inventory::GetInst()->RemoveItem(L"나무");
		Inventory::GetInst()->RemoveItem(L"돌");
		Inventory::GetInst()->AddItem(RecipeSO::GetInst()->GetRecipe(L"나무돌"));
	}
	shared_ptr<ItemData> itemData = ItemSO::GetInst()->GetItemData(L"다이아몬드");

	int x = 1;
	for (auto itemData : Inventory::GetInst()->itemData)
	{
		wstring str = itemData->GetText();
		TextOutW(Core::GetInst()->GetMainDC(), 100 * x, 100, str.c_str(), str.length());
		Image* image = itemData->GetSprite();
		BitBlt(Core::GetInst()->GetMainDC(), 100 * x, 150, 100, 100, image->GetDC(), 0, 0, SRCCOPY);
		x++;
	}
}
