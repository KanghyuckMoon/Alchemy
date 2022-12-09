#include "pch.h"
#include "ItemSO.h"
#include "ItemData.h"

void ItemSO::Init()
{
	AddItemData("Postion", shared_ptr<ItemData>(new ItemData(100, 101, 102)));
}
