#include "pch.h"
#include "ItemSO.h"
#include "ItemData.h"

void ItemSO::Init()
{
	//아이템
	AddItemData(L"나무", shared_ptr<ItemData>(new ItemData(L"나무", L"나무_N", L"나무_T", L"Wood")));
	AddItemData(L"돌", shared_ptr<ItemData>(new ItemData(L"돌", L"돌_N", L"돌_T", L"Rune Stone")));
	AddItemData(L"가죽", shared_ptr<ItemData>(new ItemData(L"가죽", L"가죽_N", L"가죽_T", L"Leather")));
	AddItemData(L"양피지", shared_ptr<ItemData>(new ItemData(L"양피지", L"양피지_N", L"양피지_T", L"Paper")));
	AddItemData(L"목재", shared_ptr<ItemData>(new ItemData(L"목재", L"목재_N", L"목재_T", L"Wooden Plank")));
	AddItemData(L"구리 주괴", shared_ptr<ItemData>(new ItemData(L"구리 주괴", L"구리 주괴_N", L"구리 주괴_T", L"Copper Ingot")));
	AddItemData(L"구리", shared_ptr<ItemData>(new ItemData(L"구리", L"구리_N", L"구리_T", L"Copper Nugget")));
	AddItemData(L"가죽 모자", shared_ptr<ItemData>(new ItemData(L"가죽 모자", L"가죽 모자_N", L"가죽 모자_T", L"Leather Helmet")));
	AddItemData(L"책", shared_ptr<ItemData>(new ItemData(L"책", L"책_N", L"책_T", L"Book")));
	AddItemData(L"횃불", shared_ptr<ItemData>(new ItemData(L"횃불", L"횃불_N", L"횃불_T", L"Torch")));
	AddItemData(L"박스", shared_ptr<ItemData>(new ItemData(L"박스", L"박스_N", L"박스_T", L"Crate")));
	AddItemData(L"고기", shared_ptr<ItemData>(new ItemData(L"고기", L"고기_N", L"고기_T", L"Meat")));
	AddItemData(L"은괴", shared_ptr<ItemData>(new ItemData(L"은괴", L"은괴_N", L"은괴_T", L"Silver Ingot")));
	AddItemData(L"은", shared_ptr<ItemData>(new ItemData(L"은", L"은_N", L"은_T", L"Silver Nugget")));
	AddItemData(L"램프", shared_ptr<ItemData>(new ItemData(L"램프", L"램프_N", L"램프_T", L"Lantern")));
	AddItemData(L"키", shared_ptr<ItemData>(new ItemData(L"키", L"키_N", L"키_T", L"Silver Key")));
	AddItemData(L"나이프", shared_ptr<ItemData>(new ItemData(L"나이프", L"나이프_N", L"나이프_T", L"Knife")));
	AddItemData(L"구운 고기", shared_ptr<ItemData>(new ItemData(L"구운 고기", L"구운 고기_N", L"구운 고기_T", L"Ham")));
	AddItemData(L"철 헬멧", shared_ptr<ItemData>(new ItemData(L"철 헬멧", L"철 헬멧_N", L"철 헬멧_T", L"Iron Helmet")));
	AddItemData(L"헬멧", shared_ptr<ItemData>(new ItemData(L"헬멧", L"헬멧_N", L"헬멧_T", L"Helm")));
	AddItemData(L"금 열쇠", shared_ptr<ItemData>(new ItemData(L"금 열쇠", L"금 열쇠_N", L"금 열쇠_T", L"Golden Key")));
	AddItemData(L"금괴", shared_ptr<ItemData>(new ItemData(L"금괴", L"금괴_N", L"금괴_T", L"Golden Ingot")));
	AddItemData(L"상자", shared_ptr<ItemData>(new ItemData(L"상자", L"상자_N", L"상자_T", L"Chest")));
	AddItemData(L"뼈", shared_ptr<ItemData>(new ItemData(L"뼈", L"뼈_N", L"뼈_T", L"Bone")));
	AddItemData(L"루비", shared_ptr<ItemData>(new ItemData(L"루비", L"루비_N", L"루비_T", L"Cut Ruby")));
	AddItemData(L"포션", shared_ptr<ItemData>(new ItemData(L"포션", L"포션_N", L"포션_T", L"Red Potion 2")));
	AddItemData(L"사파이어", shared_ptr<ItemData>(new ItemData(L"사파이어", L"사파이어_N", L"사파이어_T", L"Cut Sapphire")));
	AddItemData(L"해골", shared_ptr<ItemData>(new ItemData(L"해골", L"해골_N", L"해골_T", L"Skull")));
	AddItemData(L"생명", shared_ptr<ItemData>(new ItemData(L"생명", L"생명_N", L"생명_T", L"Heart")));
	AddItemData(L"다이아몬드", shared_ptr<ItemData>(new ItemData(L"다이아몬드", L"다이아몬드_N", L"다이아몬드_T", L"Diamond")));

	//미소녀
	AddItemData(L"미소녀1", shared_ptr<ItemData>(new ItemData(L"미소녀1", L"미소녀1_N", L"미소녀1_T", L"Diamond")));
	AddItemData(L"미소녀2", shared_ptr<ItemData>(new ItemData(L"미소녀2", L"미소녀2_N", L"미소녀2_T", L"Diamond")));
	AddItemData(L"미소녀3", shared_ptr<ItemData>(new ItemData(L"미소녀3", L"미소녀3_N", L"미소녀3_T", L"Diamond")));
	AddItemData(L"미소녀4", shared_ptr<ItemData>(new ItemData(L"미소녀4", L"미소녀4_N", L"미소녀4_T", L"Diamond")));
	AddItemData(L"미소녀5", shared_ptr<ItemData>(new ItemData(L"미소녀5", L"미소녀5_N", L"미소녀5_T", L"Diamond")));
	AddItemData(L"미소녀6", shared_ptr<ItemData>(new ItemData(L"미소녀6", L"미소녀6_N", L"미소녀6_T", L"Diamond")));
	AddItemData(L"미소녀7", shared_ptr<ItemData>(new ItemData(L"미소녀7", L"미소녀7_N", L"미소녀7_T", L"Diamond")));
	AddItemData(L"미소녀8", shared_ptr<ItemData>(new ItemData(L"미소녀8", L"미소녀8_N", L"미소녀8_T", L"Diamond")));

}
	