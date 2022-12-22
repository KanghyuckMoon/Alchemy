#pragma once
#include "Object.h"
class ItemBox;
class ItemTree : public Object
{
public:
	ItemTree();
	~ItemTree();

private:
	CLONE(ItemTree);

private:
	vector<shared_ptr<ItemBox>> itemBoxs;
	
private:
	void DrawLines(HDC _dc, const wstring& key, shared_ptr<ItemBox> itemBox);

public:
	virtual void Update() override;
	virtual void Render(HDC _dc) override;
	void ResetPosition();

private:
	POINT previousMouse;
	POINT mouse;

public:
	bool ClickEvent(POINT ps);
	wstring ClickEventGetItemKey(POINT ps);
};

