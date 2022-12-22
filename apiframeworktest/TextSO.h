#pragma once
#include "ScriptableObject.h"
class TextSO : public ScriptableObject
{
public:
	SINGLE(TextSO);

private:
	map<wstring, wstring> textDatas;

public:
	void Init();

public:
	const wstring GetTextData(const wstring& key);
	const void AddTextData(const wstring& key, const wstring& text) { textDatas.insert({ key, text }); }
};

