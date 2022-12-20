#include "pch.h"
#include "RecipeSO.h"

void RecipeSO::Init()
{
	//Recipe

	//2
	AddRecipe(L"������", L"����");
	AddRecipe(L"������", L"����");
	AddRecipe(L"��������", L"����");
	AddRecipe(L"����", L"���� �ֱ�");

	//3
	AddRecipe(L"���׾�����", L"å");
	AddRecipe(L"����������", L"å");
	AddRecipe(L"���װ���", L"���� ����");
	AddRecipe(L"�������", L"�ڽ�");
	AddRecipe(L"���� �ֱ�����", L"����");
	AddRecipe(L"�������� �ֱ�", L"����");

	//4
	AddRecipe(L"åȶ��", L"����");
	AddRecipe(L"ȶ��å", L"����");
	AddRecipe(L"���� ���ڱ��� �ֱ�", L"���");
	AddRecipe(L"���� �ֱ����� ����", L"���");
	AddRecipe(L"��������", L"Ű");

	//5
	AddRecipe(L"��������", L"������");
	AddRecipe(L"��������", L"������");
	AddRecipe(L"��ⷥ��", L"���� ���");
	AddRecipe(L"�������", L"���� ���");
	AddRecipe(L"�������", L"ö ���");
	AddRecipe(L"�������", L"ö ���");
	AddRecipe(L"������", L"�ݱ�");
	AddRecipe(L"������", L"�ݱ�");
	AddRecipe(L"Ű����", L"����");
	AddRecipe(L"����Ű", L"����");

	//6
	AddRecipe(L"���������� ���", L"��");
	AddRecipe(L"���� ��⳪����", L"��");
	AddRecipe(L"�� �������", L"���");
	AddRecipe(L"���ڱ� ����", L"���");

	//7
	AddRecipe(L"��ö ���", L"�ذ�");
	AddRecipe(L"ö ����", L"�ذ�");
	AddRecipe(L"���ݱ�", L"�����̾�");
	AddRecipe(L"�ݱ����", L"�����̾�");

	//8
	AddRecipe(L"�ذ�����", L"����");
	AddRecipe(L"�����ذ�", L"����");

	//9
	AddRecipe(L"��������̾�", L"���̾Ƹ��");
	AddRecipe(L"�����̾����", L"���̾Ƹ��");


	//Exchange
	
	//1
	AddExchange(L"����", L"�̼ҳ�1");
	AddExchange(L"�̼ҳ�1", L"��");
	AddExchange(L"��", L"�̼ҳ�1");

	//2
	AddExchange(L"���� �ֱ�", L"�̼ҳ�2");
	AddExchange(L"�̼ҳ�2", L"����");
	AddExchange(L"����", L"�̼ҳ�2");

	//3
	AddExchange(L"å", L"�̼ҳ�3");
	AddExchange(L"�̼ҳ�3", L"ȶ��");
	AddExchange(L"ȶ��", L"�̼ҳ�3");

	AddExchange(L"����", L"�̼ҳ�4");
	AddExchange(L"�̼ҳ�4", L"��");
	AddExchange(L"��", L"�̼ҳ�4");

	AddExchange(L"����", L"�̼ҳ�5");
	AddExchange(L"�̼ҳ�5", L"���");
	AddExchange(L"���", L"�̼ҳ�5");

	//4
	
	//5
	AddExchange(L"�ݱ�", L"�̼ҳ�6");
	AddExchange(L"�̼ҳ�6", L"�� ����");
	AddExchange(L"�� ����", L"�̼ҳ�6");

	//6
	AddExchange(L"���", L"�̼ҳ�7");
	AddExchange(L"�̼ҳ�7", L"����");
	AddExchange(L"����", L"�̼ҳ�7");
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
