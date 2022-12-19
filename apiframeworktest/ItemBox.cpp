#include "pch.h"
#include "ItemBox.h"
#include "ItemData.h"
#include "Core.h"
#include "Image.h"
#include "ItemSO.h"

ItemBox::ItemBox()
{
}

ItemBox::~ItemBox()
{
}

ItemBox::ItemBox(const wstring& str)
{
	SetItemData(str);
}

void ItemBox::SetItemData(const wstring& str)
{
	itemData = ItemSO::GetInst()->GetItemData(str);
	m_pImage = itemData->GetSprite();
	m_name = itemData->GetText();
}

void ItemBox::Update()
{
}

void ItemBox::Render(HDC _dc)
{
	Component_Render(_dc);

	//·»´õ
	TextOutW(_dc, GetPos().x - (GetScale().x / 2), GetPos().y - (GetScale().y / 2) + 50, m_name.c_str(), m_name.length());
	BitBlt(_dc, GetPos().x - (GetScale().x / 2), GetPos().y - (GetScale().y / 2), GetScale().x, GetScale().y, m_pImage->GetDC(), 0, 0, SRCCOPY);
}
