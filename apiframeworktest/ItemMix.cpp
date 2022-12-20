#include "pch.h"
#include "ItemMix.h"
#include "ItemBox.h"

ItemMix::ItemMix()
{
	itemBox1 = make_shared<ItemBox>(L"NULL");
	itemBox2 = make_shared<ItemBox>(L"NULL");

	itemBox1->SetPos(Vec2(100, 100));
	itemBox2->SetPos(Vec2(200, 100));
}

ItemMix::~ItemMix()
{
}

void ItemMix::SelectItem(const wstring& str)
{
	if (!isSelecItemBox1)
	{
		isSelecItemBox1 = true;
		SelectItem1(str);
	}
	else
	{
		SelectItem2(str);
	}
}

void ItemMix::Clear()
{
	if (itemBox1)
	{
		if (itemBox1->GetItemData() != L"NULL")
		{
			//인벤토리에 추가
		}
	}

	if (itemBox2)
	{
		if (itemBox2->GetItemData() != L"NULL")
		{
			//인벤토리에 추가
		}
	}
}

void ItemMix::SelectItem1(const wstring& str)
{
	itemBox1->SetItemData(str);
}

void ItemMix::SelectItem2(const wstring& str)
{
	itemBox2->SetItemData(str);
}

void ItemMix::Update()
{
}

void ItemMix::Render(HDC _dc)
{
	if (itemBox1)
	{
		itemBox1->Render(_dc);
	}

	if (itemBox2)
	{
		itemBox2->Render(_dc);
	}
}
