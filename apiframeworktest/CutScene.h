#pragma once
#include "ItemData.h"

class Button;
class Image;

class CutScene
{
public:
	CutScene();
	virtual ~CutScene();

private:
	unordered_set<wstring> cutSceneItems;
	wstring cutSceneItem;
	Button* button;
	Image* image;
	bool isCutsing = false;
	int index = 0;
	int textIndex = 0;
	wstring outText = L"";

public:
	wstring GetText(const wstring& itemKey, int index);
	bool CheckCanCutSceneItem(const wstring& itemKey);
	bool CheckCutSing();
	void Render(HDC _dc);
	void Update();
	void SetButtonText();
};

