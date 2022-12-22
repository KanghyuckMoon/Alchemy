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
	AddRecipe(L"Ű�ڽ�", L"����");
	AddRecipe(L"�ڽ�Ű", L"����");

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
	AddExchange(L"����", L"�̼ҳ�1_1");
	AddExchange(L"�̼ҳ�1_1", L"��");
	AddExchange(L"��", L"�̼ҳ�1_2");
	AddExchange(L"�̼ҳ�1_2", L"����");

	//2
	AddExchange(L"����", L"�̼ҳ�2_1");
	AddExchange(L"�̼ҳ�2_1", L"������");
	AddExchange(L"������", L"�̼ҳ�2_2");
	AddExchange(L"�̼ҳ�2_2", L"����");

	AddExchange(L"���� �ֱ�", L"�̼ҳ�3_1");
	AddExchange(L"�̼ҳ�3_1", L"����");
	AddExchange(L"����", L"�̼ҳ�3_2");
	AddExchange(L"�̼ҳ�3_2", L"���� �ֱ�");

	//3
	AddExchange(L"å", L"�̼ҳ�4_1");
	AddExchange(L"�̼ҳ�4_1", L"ȶ��");
	AddExchange(L"ȶ��", L"�̼ҳ�4_2");
	AddExchange(L"�̼ҳ�4_2", L"å");

	AddExchange(L"����", L"�̼ҳ�5_1");
	AddExchange(L"�̼ҳ�5_1", L"��");
	AddExchange(L"��", L"�̼ҳ�5_2");
	AddExchange(L"�̼ҳ�5_2", L"����");

	AddExchange(L"�ڽ�", L"�̼ҳ�6_1");
	AddExchange(L"�̼ҳ�6_1", L"���");
	AddExchange(L"���", L"�̼ҳ�6_2");
	AddExchange(L"�̼ҳ�6_2", L"�ڽ�");

	//4
	
	//5
	AddExchange(L"�ݱ�", L"�̼ҳ�7_1");
	AddExchange(L"�̼ҳ�7_1", L"�� ����");
	AddExchange(L"�� ����", L"�̼ҳ�7_2");
	AddExchange(L"�̼ҳ�7_2", L"�ݱ�");

	//6
	AddExchange(L"���", L"�̼ҳ�8_1");
	AddExchange(L"�̼ҳ�8_1", L"����");
	AddExchange(L"����", L"�̼ҳ�8_2");
	AddExchange(L"�̼ҳ�8_2", L"���");

	//6
	AddExchange(L"���̾Ƹ��", L"�̼ҳ�9_1");
	AddExchange(L"�̼ҳ�9_1", L"���̾Ƹ��");
	AddExchange(L"���̾Ƹ��", L"�̼ҳ�9_2");
	AddExchange(L"�̼ҳ�9_2", L"���̾Ƹ��");
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
