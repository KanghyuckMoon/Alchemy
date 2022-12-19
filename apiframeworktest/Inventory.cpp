#include "pch.h"
#include "Inventory.h"
#include "ItemSO.h"
#include "ItemData.h"

void Inventory::Init()
{
	auto data1 = ItemSO::GetInst()->GetItemData(L"³ª¹«");
	auto data2 = ItemSO::GetInst()->GetItemData(L"µ¹");
	itemData.push_back(data1);
	itemData.push_back(data2);
}

void Inventory::AddItem(const wstring& str)
{
	auto data = ItemSO::GetInst()->GetItemData(str);
	itemData.push_back(data);
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
