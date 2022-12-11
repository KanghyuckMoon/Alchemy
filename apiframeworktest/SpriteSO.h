#pragma once
#include "ScriptableObject.h"

class SpriteSO : public ScriptableObject
{
static map<string, int> spriteDatas;

public:
	static void Init();

public:
	static int GetSpriteData(string key) { return spriteDatas.at(key); }
	static void AddSpriteData(string key, int index) { spriteDatas.insert({ key, index }); }
};

