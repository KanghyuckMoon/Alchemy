#pragma once
#include "ScriptableObject.h"
class ItemData;
class Inventory : public ScriptableObject
{
public:
	SINGLE(Inventory);

public:
	vector<shared_ptr<ItemData>> itemData;

	void Init();
	void RemoveItem(const wstring& str);
	void AddItem(const wstring& str);
};

