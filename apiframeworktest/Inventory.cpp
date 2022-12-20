#include "pch.h"
#include "Inventory.h"
#include "ItemSO.h"
#include "ItemData.h"

void Inventory::Init()
{
	AddItem(L"³ª¹«");
	AddItem(L"µ¹");
}

void Inventory::AddItem(const wstring& str)
{
	if (count == 8)
	{
		return;
	}

	auto data = ItemSO::GetInst()->GetItemData(str);
	itemData.push_back(data);
	++count;
}
void Inventory::RemoveItem(const wstring& str)
{
	for (int i = 0; i < itemData.size(); ++i)
	{
		if (itemData.at(i)->GetKey() == str)
		{
			itemData.erase(itemData.begin() + i);
			break;
		}
	}
}

shared_ptr<ItemData> Inventory::GetItemData(int index)
{
	if (count <= index)
	{
		return nullptr;
	}

	return itemData.at(index);
}
