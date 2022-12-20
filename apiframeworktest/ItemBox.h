#pragma once
#include "Object.h"
class ItemData;
class Image;

class ItemBox : public Object
{
public:
	ItemBox();
	~ItemBox();
	ItemBox(const wstring& str);


private:
	shared_ptr<ItemData> itemData;
	Image* m_itemImage;
	Image* m_templateImage;
	wstring m_name;

private:
	CLONE(ItemBox);

public:
	const wstring& GetItemData();
	void SetItemData(const wstring& str);
	virtual void Update() override;
	virtual void Render(HDC _dc) override;
};

