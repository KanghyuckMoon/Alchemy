#pragma once
#include "ScriptableObject.h"
class RecipeSO : public ScriptableObject
{
public:
	SINGLE(RecipeSO);

private:
	unordered_map<wstring, wstring> mixMap;
	unordered_map<wstring, wstring> girlMap;

public:
	void Init();
	void AddRecipe(const wstring& str, const wstring& value);
	void AddExchange(const wstring& str, const wstring& value);
	const wstring& GetRecipe(const wstring& str);
	const wstring& GetGirl(const wstring& str);

};

