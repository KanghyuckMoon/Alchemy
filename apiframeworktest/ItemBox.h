#pragma once
#include "Object.h"
class ItemData;
class Image;

class ItemBox : public Object
{
public:
	~ItemBox();
	ItemBox(const wstring& str);

private:
	shared_ptr<ItemData> itemData = nullptr;
	Image* m_itemImage = nullptr;
	Image* m_templateImage = nullptr;
	wstring m_name;

private:
	CLONE(ItemBox);

public:
	wstring GetItemData();
	void SetItemData(const wstring& str);
	virtual void Update() override;
	virtual void Render(HDC _dc) override;

public:
	bool ClickEvent(POINT ps);
};

