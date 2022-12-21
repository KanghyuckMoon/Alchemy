#include "pch.h"
#include "ItemSO.h"
#include "ItemData.h"

void ItemSO::Init()
{
	//������
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"����_T", L"Wood")));
	AddItemData(L"��", shared_ptr<ItemData>(new ItemData(L"��", L"��_N", L"��_T", L"Rune Stone")));
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"����_T", L"Leather")));
	AddItemData(L"������", shared_ptr<ItemData>(new ItemData(L"������", L"������_N", L"������_T", L"Paper")));
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"����_T", L"Wooden Plank")));
	AddItemData(L"���� �ֱ�", shared_ptr<ItemData>(new ItemData(L"���� �ֱ�", L"���� �ֱ�_N", L"���� �ֱ�_T", L"Copper Ingot")));
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"����_T", L"Copper Nugget")));
	AddItemData(L"���� ����", shared_ptr<ItemData>(new ItemData(L"���� ����", L"���� ����_N", L"���� ����_T", L"Leather Helmet")));
	AddItemData(L"å", shared_ptr<ItemData>(new ItemData(L"å", L"å_N", L"å_T", L"Book")));
	AddItemData(L"ȶ��", shared_ptr<ItemData>(new ItemData(L"ȶ��", L"ȶ��_N", L"ȶ��_T", L"Torch")));
	AddItemData(L"�ڽ�", shared_ptr<ItemData>(new ItemData(L"�ڽ�", L"�ڽ�_N", L"�ڽ�_T", L"Crate")));
	AddItemData(L"���", shared_ptr<ItemData>(new ItemData(L"���", L"���_N", L"���_T", L"Meat")));
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"����_T", L"Silver Ingot")));
	AddItemData(L"��", shared_ptr<ItemData>(new ItemData(L"��", L"��_N", L"��_T", L"Silver Nugget")));
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"����_T", L"Lantern")));
	AddItemData(L"Ű", shared_ptr<ItemData>(new ItemData(L"Ű", L"Ű_N", L"Ű_T", L"Silver Key")));
	AddItemData(L"������", shared_ptr<ItemData>(new ItemData(L"������", L"������_N", L"������_T", L"Knife")));
	AddItemData(L"���� ���", shared_ptr<ItemData>(new ItemData(L"���� ���", L"���� ���_N", L"���� ���_T", L"Ham")));
	AddItemData(L"ö ���", shared_ptr<ItemData>(new ItemData(L"ö ���", L"ö ���_N", L"ö ���_T", L"Iron Helmet")));
	AddItemData(L"���", shared_ptr<ItemData>(new ItemData(L"���", L"���_N", L"���_T", L"Helm")));
	AddItemData(L"�� ����", shared_ptr<ItemData>(new ItemData(L"�� ����", L"�� ����_N", L"�� ����_T", L"Golden Key")));
	AddItemData(L"�ݱ�", shared_ptr<ItemData>(new ItemData(L"�ݱ�", L"�ݱ�_N", L"�ݱ�_T", L"Golden Ingot")));
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"����_T", L"Chest")));
	AddItemData(L"��", shared_ptr<ItemData>(new ItemData(L"��", L"��_N", L"��_T", L"Bone")));
	AddItemData(L"���", shared_ptr<ItemData>(new ItemData(L"���", L"���_N", L"���_T", L"Cut Ruby")));
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"����_T", L"Red Potion 2")));
	AddItemData(L"�����̾�", shared_ptr<ItemData>(new ItemData(L"�����̾�", L"�����̾�_N", L"�����̾�_T", L"Cut Sapphire")));
	AddItemData(L"�ذ�", shared_ptr<ItemData>(new ItemData(L"�ذ�", L"�ذ�_N", L"�ذ�_T", L"Skull")));
	AddItemData(L"����", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"����_T", L"Heart")));
	AddItemData(L"���̾Ƹ��", shared_ptr<ItemData>(new ItemData(L"���̾Ƹ��", L"���̾Ƹ��_N", L"���̾Ƹ��_T", L"Diamond")));

	//�̼ҳ�
	AddItemData(L"�̼ҳ�1", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�1", L"�̼ҳ�1_N", L"�̼ҳ�1_T", L"Diamond")));
	AddItemData(L"�̼ҳ�2", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�2", L"�̼ҳ�2_N", L"�̼ҳ�2_T", L"Diamond")));
	AddItemData(L"�̼ҳ�3", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�3", L"�̼ҳ�3_N", L"�̼ҳ�3_T", L"Diamond")));
	AddItemData(L"�̼ҳ�4", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�4", L"�̼ҳ�4_N", L"�̼ҳ�4_T", L"Diamond")));
	AddItemData(L"�̼ҳ�5", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�5", L"�̼ҳ�5_N", L"�̼ҳ�5_T", L"Diamond")));
	AddItemData(L"�̼ҳ�6", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�6", L"�̼ҳ�6_N", L"�̼ҳ�6_T", L"Diamond")));
	AddItemData(L"�̼ҳ�7", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�7", L"�̼ҳ�7_N", L"�̼ҳ�7_T", L"Diamond")));
	AddItemData(L"�̼ҳ�8", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�8", L"�̼ҳ�8_N", L"�̼ҳ�8_T", L"Diamond")));

}
	