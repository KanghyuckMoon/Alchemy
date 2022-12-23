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

	shared_ptr<Button> choiceButton1;
	shared_ptr<Button> choiceButton2;
	shared_ptr<Button> button;
	shared_ptr<CharacterImage> girlImage;
	shared_ptr<CharacterImage> boyImage;
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

