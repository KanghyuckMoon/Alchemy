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
	AddItemData(L"�̼ҳ�1_1", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�1_1", L"�̼ҳ�1_N", L"�̼ҳ�1_T", L"Diamond")));
	AddItemData(L"�̼ҳ�2_1", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�2_1", L"�̼ҳ�2_N", L"�̼ҳ�2_T", L"Diamond")));
	AddItemData(L"�̼ҳ�3_1", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�3_1", L"�̼ҳ�3_N", L"�̼ҳ�3_T", L"Diamond")));
	AddItemData(L"�̼ҳ�4_1", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�4_1", L"�̼ҳ�4_N", L"�̼ҳ�4_T", L"Diamond")));
	AddItemData(L"�̼ҳ�5_1", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�5_1", L"�̼ҳ�5_N", L"�̼ҳ�5_T", L"Diamond")));
	AddItemData(L"�̼ҳ�6_1", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�6_1", L"�̼ҳ�6_N", L"�̼ҳ�6_T", L"Diamond")));
	AddItemData(L"�̼ҳ�7_1", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�7_1", L"�̼ҳ�7_N", L"�̼ҳ�7_T", L"Diamond")));
	AddItemData(L"�̼ҳ�8_1", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�8_1", L"�̼ҳ�8_N", L"�̼ҳ�8_T", L"Diamond")));

	AddItemData(L"�̼ҳ�1_2", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�1_2", L"�̼ҳ�1_N", L"�̼ҳ�1_T", L"Diamond")));
	AddItemData(L"�̼ҳ�2_2", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�2_2", L"�̼ҳ�2_N", L"�̼ҳ�2_T", L"Diamond")));
	AddItemData(L"�̼ҳ�3_2", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�3_2", L"�̼ҳ�3_N", L"�̼ҳ�3_T", L"Diamond")));
	AddItemData(L"�̼ҳ�4_2", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�4_2", L"�̼ҳ�4_N", L"�̼ҳ�4_T", L"Diamond")));
	AddItemData(L"�̼ҳ�5_2", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�5_2", L"�̼ҳ�5_N", L"�̼ҳ�5_T", L"Diamond")));
	AddItemData(L"�̼ҳ�6_2", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�6_2", L"�̼ҳ�6_N", L"�̼ҳ�6_T", L"Diamond")));
	AddItemData(L"�̼ҳ�7_2", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�7_2", L"�̼ҳ�7_N", L"�̼ҳ�7_T", L"Diamond")));
	AddItemData(L"�̼ҳ�8_2", shared_ptr<ItemData>(new ItemData(L"�̼ҳ�8_2", L"�̼ҳ�8_N", L"�̼ҳ�8_T", L"Diamond")));

	//��Ʈ
	AddItemData(L"������Ʈ", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"������Ʈ_T", L"Wood")));
	AddItemData(L"����Ʈ", shared_ptr<ItemData>(new ItemData(L"��", L"��_N", L"����Ʈ_T", L"Rune Stone")));
	AddItemData(L"������Ʈ", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"������Ʈ_T", L"Leather")));
	AddItemData(L"��������Ʈ", shared_ptr<ItemData>(new ItemData(L"������", L"������_N", L"��������Ʈ_T", L"Paper")));
	AddItemData(L"������Ʈ", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"������Ʈ_T", L"Wooden Plank")));
	AddItemData(L"���� �ֱ���Ʈ", shared_ptr<ItemData>(new ItemData(L"���� �ֱ�", L"���� �ֱ���Ʈ_N", L"���� �ֱ�_T", L"Copper Ingot")));
	AddItemData(L"������Ʈ", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"������Ʈ_T", L"Copper Nugget")));
	AddItemData(L"���� ������Ʈ", shared_ptr<ItemData>(new ItemData(L"���� ����", L"���� ����_N", L"���� ������Ʈ_T", L"Leather Helmet")));
	AddItemData(L"å��Ʈ", shared_ptr<ItemData>(new ItemData(L"å", L"å_N", L"å��Ʈ_T", L"Book")));
	AddItemData(L"ȶ����Ʈ", shared_ptr<ItemData>(new ItemData(L"ȶ��", L"ȶ��_N", L"ȶ����Ʈ_T", L"Torch")));
	AddItemData(L"�ڽ���Ʈ", shared_ptr<ItemData>(new ItemData(L"�ڽ�", L"�ڽ�_N", L"�ڽ���Ʈ_T", L"Crate")));
	AddItemData(L"�����Ʈ", shared_ptr<ItemData>(new ItemData(L"���", L"���_N", L"�����Ʈ_T", L"Meat")));
	AddItemData(L"������Ʈ", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"������Ʈ_T", L"Silver Ingot")));
	AddItemData(L"����Ʈ", shared_ptr<ItemData>(new ItemData(L"��", L"��_N", L"����Ʈ_T", L"Silver Nugget")));
	AddItemData(L"������Ʈ", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"������Ʈ_T", L"Lantern")));
	AddItemData(L"Ű��Ʈ", shared_ptr<ItemData>(new ItemData(L"Ű", L"Ű_N", L"Ű��Ʈ_T", L"Silver Key")));
	AddItemData(L"��������Ʈ", shared_ptr<ItemData>(new ItemData(L"������", L"������_N", L"��������Ʈ_T", L"Knife")));
	AddItemData(L"���� �����Ʈ", shared_ptr<ItemData>(new ItemData(L"���� ���", L"���� ���_N", L"���� �����Ʈ_T", L"Ham")));
	AddItemData(L"ö �����Ʈ", shared_ptr<ItemData>(new ItemData(L"ö ���", L"ö ���_N", L"ö �����Ʈ_T", L"Iron Helmet")));
	AddItemData(L"�����Ʈ", shared_ptr<ItemData>(new ItemData(L"���", L"���_N", L"�����Ʈ_T", L"Helm")));
	AddItemData(L"�� ������Ʈ", shared_ptr<ItemData>(new ItemData(L"�� ����", L"�� ����_N", L"�� ������Ʈ_T", L"Golden Key")));
	AddItemData(L"�ݱ���Ʈ", shared_ptr<ItemData>(new ItemData(L"�ݱ�", L"�ݱ�_N", L"�ݱ���Ʈ_T", L"Golden Ingot")));
	AddItemData(L"������Ʈ", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"������Ʈ_T", L"Chest")));
	AddItemData(L"����Ʈ", shared_ptr<ItemData>(new ItemData(L"��", L"��_N", L"����Ʈ_T", L"Bone")));
	AddItemData(L"�����Ʈ", shared_ptr<ItemData>(new ItemData(L"���", L"���_N", L"�����Ʈ_T", L"Cut Ruby")));
	AddItemData(L"������Ʈ", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"������Ʈ_T", L"Red Potion 2")));
	AddItemData(L"�����̾���Ʈ", shared_ptr<ItemData>(new ItemData(L"�����̾�", L"�����̾�_N", L"�����̾���Ʈ_T", L"Cut Sapphire")));
	AddItemData(L"�ذ���Ʈ", shared_ptr<ItemData>(new ItemData(L"�ذ�", L"�ذ�_N", L"�ذ���Ʈ_T", L"Skull")));
	AddItemData(L"������Ʈ", shared_ptr<ItemData>(new ItemData(L"����", L"����_N", L"������Ʈ_T", L"Heart")));
	AddItemData(L"���̾Ƹ����Ʈ", shared_ptr<ItemData>(new ItemData(L"���̾Ƹ��", L"���̾Ƹ��_N", L"���̾Ƹ����Ʈ_T", L"Diamond")));
}
	