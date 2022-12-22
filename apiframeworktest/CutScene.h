#pragma once
#include "ItemData.h"

class Button;
class Image;
class CharacterImage;
class CutScene
{
public:
	CutScene();
	virtual ~CutScene();

private:
	unordered_set<wstring> cutSceneItems;
	wstring cutSceneItem;

	Button* choiceButton1;
	Button* choiceButton2;
	Button* button;
	CharacterImage* girlImage;
	CharacterImage* boyImage;
	bool isCutsing = false;
	bool isChoice = false;
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

