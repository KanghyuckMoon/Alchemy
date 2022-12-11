#pragma once
#include "ScriptableObject.h"
class ItemData;

class ItemSO : public ScriptableObject
{
public:
	SINGLE(ItemSO);

private:
	map<wstring, shared_ptr<ItemData>> itemDatas;

public:
	void Init();

public:
	shared_ptr<ItemData> GetItemData(const wstring& key) { return itemDatas.at(key); }
	void AddItemData(const wstring& key, shared_ptr<ItemData> itemData) { itemDatas.insert({ key, itemData }); }
};

