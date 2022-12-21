#pragma once

class ItemBox;
class ItemData;

class ItemMix
{
public:
	ItemMix();
	~ItemMix();

private:
	int count = 0;
	shared_ptr<ItemBox> itemBox1;
	shared_ptr<ItemBox> itemBox2;
	
public:
	wstring MixItem();
	void SelectItem(const wstring& str);
	void Clear();
	void ReturnItems();
	int GetCount();

private:
	void SelectItem1(const wstring& str);
	void SelectItem2(const wstring& str);

public:
	virtual void Update();
	virtual void Render(HDC _dc);


};

