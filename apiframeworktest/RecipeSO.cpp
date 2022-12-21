#include "pch.h"
#include "RecipeSO.h"

void RecipeSO::Init()
{
	//Recipe

	//2
	AddRecipe(L"나무돌", L"가죽");
	AddRecipe(L"돌나무", L"가죽");
	AddRecipe(L"나무나무", L"목재");
	AddRecipe(L"돌돌", L"구리 주괴");

	//3
	AddRecipe(L"가죽양피지", L"책");
	AddRecipe(L"양피지가죽", L"책");
	AddRecipe(L"가죽가죽", L"가죽 모자");
	AddRecipe(L"목재목재", L"박스");
	AddRecipe(L"구리 주괴구리", L"은괴");
	AddRecipe(L"구리구리 주괴", L"은괴");

	//4
	AddRecipe(L"책횃불", L"램프");
	AddRecipe(L"횃불책", L"램프");
	AddRecipe(L"가죽 모자구리 주괴", L"헬멧");
	AddRecipe(L"구리 주괴가죽 모자", L"헬멧");
	AddRecipe(L"은괴은괴", L"키");

	//5
	AddRecipe(L"은괴가죽", L"나이프");
	AddRecipe(L"가죽은괴", L"나이프");
	AddRecipe(L"고기램프", L"구운 고기");
	AddRecipe(L"램프고기", L"구운 고기");
	AddRecipe(L"헬멧은괴", L"철 헬멧");
	AddRecipe(L"은괴헬멧", L"철 헬멧");
	AddRecipe(L"은은괴", L"금괴");
	AddRecipe(L"은괴은", L"금괴");
	AddRecipe(L"키박스", L"상자");
	AddRecipe(L"박스키", L"상자");

	//6
	AddRecipe(L"나이프구운 고기", L"뼈");
	AddRecipe(L"구운 고기나이프", L"뼈");
	AddRecipe(L"금 열쇠상자", L"루비");
	AddRecipe(L"상자금 열쇠", L"루비");

	//7
	AddRecipe(L"뼈철 헬멧", L"해골");
	AddRecipe(L"철 헬멧뼈", L"해골");
	AddRecipe(L"루비금괴", L"사파이어");
	AddRecipe(L"금괴루비", L"사파이어");

	//8
	AddRecipe(L"해골포션", L"생명");
	AddRecipe(L"포션해골", L"생명");

	//9
	AddRecipe(L"생명사파이어", L"다이아몬드");
	AddRecipe(L"사파이어생명", L"다이아몬드");


	//Exchange
	
	//1
	AddExchange(L"나무", L"미소녀1_1");
	AddExchange(L"미소녀1_1", L"돌");
	AddExchange(L"돌", L"미소녀1_2");
	AddExchange(L"미소녀1_2", L"나무");

	//2
	AddExchange(L"가죽", L"미소녀2_1");
	AddExchange(L"미소녀2_1", L"양피지");
	AddExchange(L"양피지", L"미소녀2_2");
	AddExchange(L"미소녀2_2", L"가죽");

	AddExchange(L"구리 주괴", L"미소녀3_1");
	AddExchange(L"미소녀3_1", L"구리");
	AddExchange(L"구리", L"미소녀3_2");
	AddExchange(L"미소녀3_2", L"구리 주괴");

	//3
	AddExchange(L"책", L"미소녀4_1");
	AddExchange(L"미소녀4_1", L"횃불");
	AddExchange(L"횃불", L"미소녀4_2");
	AddExchange(L"미소녀4_2", L"책");

	AddExchange(L"은괴", L"미소녀5_1");
	AddExchange(L"미소녀5_1", L"은");
	AddExchange(L"은", L"미소녀5_2");
	AddExchange(L"미소녀5_2", L"은괴");

	AddExchange(L"박스", L"미소녀6_1");
	AddExchange(L"미소녀6_1", L"고기");
	AddExchange(L"고기", L"미소녀6_2");
	AddExchange(L"미소녀6_2", L"박스");

	//4
	
	//5
	AddExchange(L"금괴", L"미소녀7_1");
	AddExchange(L"미소녀7_1", L"금 열쇠");
	AddExchange(L"금 열쇠", L"미소녀7_2");
	AddExchange(L"미소녀7_2", L"금괴");

	//6
	AddExchange(L"루비", L"미소녀8_1");
	AddExchange(L"미소녀8_1", L"포션");
	AddExchange(L"포션", L"미소녀8_2");
	AddExchange(L"미소녀8_2", L"루비");

	//6
	AddExchange(L"다이아몬드", L"미소녀9_1");
	AddExchange(L"미소녀9_1", L"다이아몬드");
	AddExchange(L"다이아몬드", L"미소녀9_2");
	AddExchange(L"미소녀9_2", L"다이아몬드");
}

void RecipeSO::AddRecipe(const wstring& str, const wstring& value)
{
	mixMap.insert({ str, value });
}

void RecipeSO::AddExchange(const wstring& str, const wstring& value)
{
	girlMap.insert({ str, value });
}

const wstring& RecipeSO::GetRecipe(const wstring& str)
{
	if (mixMap.count(str))
	{
		return mixMap[str];
	}
	else
	{
		return L"";
	}
}

const wstring& RecipeSO::GetGirl(const wstring& str)
{
	if (girlMap.count(str))
	{
		return girlMap[str];
	}
	else
	{
		return L"";
	}
}
