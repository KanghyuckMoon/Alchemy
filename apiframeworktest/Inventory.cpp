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
	getItemDatas.insert(str);
	++count;
}

void Inventory::RemoveItem(int index)
{
	if (count <= index)
	{
		return;
	}

	itemData.erase(itemData.begin() + index);
	--count;
}

int Inventory::GetCount()
{
	return count;
}

void Inventory::RemoveItem(const wstring& str)
{
	for (int i = 0; i < itemData.size(); ++i)
	{
		if (itemData.at(i)->GetKey() == str)
		{
			itemData.erase(itemData.begin() + i);
			--count;
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

bool Inventory::CheckGetItemWas(const wstring& str)
{
	if (getItemDatas.count(str))
	{
		return true;
	}
	else
	{
		return false;
	}
}