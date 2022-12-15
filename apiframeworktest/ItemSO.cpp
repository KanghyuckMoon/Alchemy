#include "pch.h"
#include "ItemSO.h"
#include "ItemData.h"

void ItemSO::Init()
{
	//itemDatas = map<string, shared_ptr<ItemData>>();
	AddItemData(L"Postion", shared_ptr<ItemData>(new ItemData(L"Postion_n1", L"Postion_t1", L"Postion")));
}
	