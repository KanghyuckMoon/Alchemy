#pragma once
#include "ScriptableObject.h"
class ItemData;
class Inventory : public ScriptableObject
{
public:
	SINGLE(Inventory);

private:
	vector<shared_ptr<ItemData>> itemData;
	int count = 0;

public:
	void Init();
	void RemoveItem(const wstring& str);
	void RemoveItem(int index);
	void AddItem(const wstring& str);
	int GetCount() { return count; }
	shared_ptr<ItemData> GetItemData(int index);
};

