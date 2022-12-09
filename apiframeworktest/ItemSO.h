#pragma once
#include "pch.h"
#include "ScriptableObject.h"
class ItemData;

static class ItemSO : public ScriptableObject
{
private:
	static map<string, shared_ptr<ItemData>> itemDatas;

public:
	 static void Init();

public:
	static shared_ptr<ItemData> GetItemData(string key) { return itemDatas.at(key); }
	static void AddItemData(string key, shared_ptr<ItemData> itemData) { itemDatas.insert({ key, itemData }); }
};

