#pragma once

class ItemBox;
class ItemData;

class ItemMix
{
public:
	ItemMix();
	~ItemMix();

private:
	bool isSelecItemBox1;
	shared_ptr<ItemBox> itemBox1;
	shared_ptr<ItemBox> itemBox2;
	
public:
	wstring MixItem();
	void SelectItem(const wstring& str);
	void Clear();
	void ReturnItems();

private:
	void SelectItem1(const wstring& str);
	void SelectItem2(const wstring& str);

public:
	virtual void Update();
	virtual void Render(HDC _dc);


};

