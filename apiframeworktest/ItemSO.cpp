#include "pch.h"
#include "ItemSO.h"
#include "ItemData.h"

void ItemSO::Init()
{
	AddItemData("Postion", shared_ptr<ItemData>(new ItemData("Postion_n1", "Postion_t1", "Postion_1")));
}
