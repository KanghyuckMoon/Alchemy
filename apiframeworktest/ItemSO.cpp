#include "pch.h"
#include "ItemSO.h"
#include "ItemData.h"

void ItemSO::Init()
{
	//itemDatas = map<string, shared_ptr<ItemData>>();
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����_N", L"����_T", L"Wood")));
	AddItemData(L"��", shared_ptr<ItemData>(new ItemData(L"��_N", L"��_T", L"Rune Stone")));
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����_N", L"����_T", L"Leather")));
	AddItemData(L"������", shared_ptr<ItemData>(new ItemData(L"������_N", L"������_T", L"Paper")));
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����_N", L"����_T", L"Wooden Plank")));
	AddItemData(L"���� �ֱ�", shared_ptr<ItemData>(new ItemData(L"���� �ֱ�_N", L"���� �ֱ�_T", L"Copper Ingot")));
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����_N", L"����_T", L"Copper Nugget")));
	AddItemData(L"���� ����", shared_ptr<ItemData>(new ItemData(L"���� ����_N", L"���� ����_T", L"Leather Helmet")));
	AddItemData(L"å", shared_ptr<ItemData>(new ItemData(L"å_N", L"å_T", L"Book")));
	AddItemData(L"ȶ��", shared_ptr<ItemData>(new ItemData(L"ȶ��_N", L"ȶ��_T", L"Torch")));
	AddItemData(L"�ڽ�", shared_ptr<ItemData>(new ItemData(L"�ڽ�_N", L"�ڽ�_T", L"Crate")));
	AddItemData(L"���", shared_ptr<ItemData>(new ItemData(L"���_N", L"���_T", L"Meat")));
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����_N", L"����_T", L"Silver Ingot")));
	AddItemData(L"��", shared_ptr<ItemData>(new ItemData(L"��_N", L"��_T", L"Silver Key")));
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����_N", L"����_T", L"Lantern")));
	AddItemData(L"Ű", shared_ptr<ItemData>(new ItemData(L"Ű_N", L"Ű_T", L"Silver Key")));
	AddItemData(L"������", shared_ptr<ItemData>(new ItemData(L"������_N", L"������_T", L"Knife")));
	AddItemData(L"���� ���", shared_ptr<ItemData>(new ItemData(L"���� ���_N", L"���� ���_T", L"Ham")));
	AddItemData(L"ö ���", shared_ptr<ItemData>(new ItemData(L"ö ���_N", L"ö ���_T", L"Iron Helmet")));
	AddItemData(L"���", shared_ptr<ItemData>(new ItemData(L"���_N", L"���_T", L"Helm")));
	AddItemData(L"�� ����", shared_ptr<ItemData>(new ItemData(L"�� ����_N", L"�� ����_T", L"Golden Key")));
	AddItemData(L"�ݱ�", shared_ptr<ItemData>(new ItemData(L"�ݱ�_N", L"�ݱ�_T", L"Golden Ingot")));
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����_N", L"����_T", L"Chest")));
	AddItemData(L"��", shared_ptr<ItemData>(new ItemData(L"��_N", L"��_T", L"Bone")));
	AddItemData(L"���", shared_ptr<ItemData>(new ItemData(L"���_N", L"���_T", L"Cut Ruby")));
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����_N", L"����_T", L"Red Potion 2")));
	AddItemData(L"�����̾�", shared_ptr<ItemData>(new ItemData(L"�����̾�_N", L"�����̾�_T", L"Cut Sapphire")));
	AddItemData(L"�ذ�", shared_ptr<ItemData>(new ItemData(L"�ذ�_N", L"�ذ�_T", L"Skull")));
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����_N", L"����_T", L"Heart")));
	AddItemData(L"���̾Ƹ��", shared_ptr<ItemData>(new ItemData(L"���̾Ƹ��_N", L"���̾Ƹ��_T", L"Diamond")));
}
	