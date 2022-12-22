#pragma once
#include "ScriptableObject.h"
class ItemData;
class Inventory : public ScriptableObject
{
public:
	SINGLE(Inventory);

private:
	vector<shared_ptr<ItemData>> itemData;
	unordered_set<wstring> getItemDatas;
	int count = 0;

public:
	void Init();
	void RemoveItem(const wstring& str);
	void RemoveItem(int index);
	void AddItem(const wstring& str);
	void ChangeItem(const wstring& str, int index);
	int GetCount();
	shared_ptr<ItemData> GetItemData(int index);
	bool CheckGetItemWas(const wstring& str);
};

