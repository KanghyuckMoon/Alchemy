#pragma once
#include "Object.h"

class ItemData;
class Background;
class ItemCaptionWindow : public Object
{
public:
	ItemCaptionWindow();
	virtual ~ItemCaptionWindow();

public:
	void SetItemData(const wstring& key);
	
private:
	CLONE(ItemCaptionWindow);

private:
	Vec2 originBackgroundPos;

public:
	virtual void Update() override;
	virtual void Render(HDC _dc) override;

private:
	Background* background;
	wstring m_caption;
};

