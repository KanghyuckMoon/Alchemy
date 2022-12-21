#include "pch.h"
#include "ItemBox.h"
#include "ItemData.h"
#include "Core.h"
#include "Image.h"
#include "ItemSO.h"
#include "ResMgr.h"

ItemBox::~ItemBox()
{
}

ItemBox::ItemBox(const wstring& str)
{
	SetItemData(str);
}

wstring ItemBox::GetItemData()
{
	// TODO: insert return statement here
	if (itemData)
	{
		return itemData->GetKey();
	}
	return L"";
}

void ItemBox::SetItemData(const wstring& str)
{
	m_templateImage = ResMgr::GetInst()->ImgLoad(L"ItemBox1", L"Image\\UIImage\\ItemBox1.bmp");
	if (str != L"")
	{
		itemData = ItemSO::GetInst()->GetItemData(str);
		m_itemImage = itemData->GetSprite();
		m_name = itemData->GetText();
	}
	else
	{
		itemData = nullptr;
		m_itemImage = nullptr;
		m_name = L"¾øÀ½";
	}
}

void ItemBox::Update()
{
}

void ItemBox::Render(HDC _dc)
{
	Component_Render(_dc);

	//·»´õ
	TextOutW(_dc, GetPos().x - (GetScale().x / 2), GetPos().y - (GetScale().y / 2) + 50, m_name.c_str(), m_name.length());
	TransparentBlt(_dc, GetPos().x - (GetScale().x / 2) - 9, GetPos().y - (GetScale().y / 2) - 10, GetScale().x / 2, GetScale().y / 2, m_templateImage->GetDC(), 0, 0, m_templateImage->GetWidth(), m_templateImage->GetHeight(), RGB(255, 0, 255));
	if (m_itemImage)
	{
		BitBlt(_dc, GetPos().x - (GetScale().x / 2), GetPos().y - (GetScale().y / 2), GetScale().x, GetScale().y, m_itemImage->GetDC(), 0, 0, SRCCOPY);
	}
}

bool ItemBox::ClickEvent(POINT ps)
{
	RECT rt = {
	   GetPos().x - GetScale().x / 2,
	   GetPos().y - GetScale().y / 2,
	   GetPos().x + GetScale().x / 2,
	   GetPos().y + GetScale().y / 2,
	};

	if ((rt.left < ps.x && ps.x < rt.right && rt.top < ps.y && ps.y < rt.bottom)) {
		return true;
	}

	return false;
}
