#pragma once
#include "pch.h"
#include "ScriptableObject.h"

static class TextSO : public ScriptableObject
{
private:
	static map<string, string> textDatas;

public:
	static void Init();

public:
	static string GetTextData(string key) { return textDatas.at(key); }
	static void AddTextData(string key, string text) { textDatas.insert({ key, text }); }
};

