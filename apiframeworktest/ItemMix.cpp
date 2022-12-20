#include "pch.h"
#include "ItemMix.h"
#include "ItemBox.h"
#include "Inventory.h"

ItemMix::ItemMix()
{
	itemBox1 = make_shared<ItemBox>(L"");
	itemBox2 = make_shared<ItemBox>(L"");

	itemBox1->SetName(L"ItemBox");
	itemBox2->SetName(L"ItemBox");
	itemBox1->SetPos(Vec2(100, 100));
	itemBox2->SetPos(Vec2(200, 100));
	itemBox1->SetScale(Vec2(100.0f, 100.0f));
	itemBox2->SetScale(Vec2(100.0f, 100.0f));

}

ItemMix::~ItemMix()
{
}

wstring ItemMix::MixItem()
{
	wstring s1 = itemBox1->GetItemData();
	wstring s2 = itemBox2->GetItemData();
	if (s1 != L"" && s2 != L"")
	{
		s1 = s1.append(s2);
		return s1;
	}
	return L"";
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
		if (itemBox1->GetItemData() != L"")
		{
			itemBox1->SetItemData(L"");
		}
	}

	if (itemBox2)
	{
		if (itemBox2->GetItemData() != L"")
		{
			itemBox2->SetItemData(L"");
		}
	}
	isSelecItemBox1 = false;
}

void ItemMix::ReturnItems()
{
	if (itemBox1)
	{
		if (itemBox1->GetItemData() != L"")
		{
			Inventory::GetInst()->AddItem(itemBox1->GetItemData());
		}
	}

	if (itemBox2)
	{
		if (itemBox2->GetItemData() != L"")
		{
			Inventory::GetInst()->AddItem(itemBox2->GetItemData());
		}
	}
	isSelecItemBox1 = false;
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
