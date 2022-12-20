#pragma once
#include "ScriptableObject.h"

class SpriteSO : public ScriptableObject
{
public:
	SINGLE(SpriteSO);

public:
	void Init();

public:
	//Image* GetSpriteData(const wstring& key);
};

