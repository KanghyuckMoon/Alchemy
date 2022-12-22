#pragma once
#include "ItemData.h"

class Button;

class CutScene
{
public:
	CutScene();
	virtual ~CutScene();

private:
	unordered_set<wstring> cutSceneItems;
	wstring cutSceneItem;
	Button* button;
	bool isCutsing = false;
	int index = 0;

public:
	wstring GetText(const wstring& itemKey, int index);
	bool CheckCanCutSceneItem(const wstring& itemKey);
	bool CheckCutSing();
	void Render(HDC _dc);
	void Update();
};

