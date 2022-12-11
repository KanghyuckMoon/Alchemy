#pragma once
#include "ScriptableObject.h"

class SpriteSO : public ScriptableObject
{
public:
	SINGLE(SpriteSO);

public:
map<wstring, int> spriteDatas;

public:
	void Init();

public:
	const int GetSpriteData(const wstring& key) { return spriteDatas.at(key); }
	void AddSpriteData(const wstring& key, int index) { spriteDatas.insert({ key, index }); }
};

