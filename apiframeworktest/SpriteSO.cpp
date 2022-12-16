#include "pch.h"
#include "resource.h"
#include "SpriteSO.h"
#include "ResMgr.h"

void SpriteSO::Init()
{
	ResMgr::GetInst()->ImgLoad(L"Wood", L"Image\\ItemImage\\Wood Log.bmp");
	ResMgr::GetInst()->ImgLoad(L"Rune Stone", L"Image\\ItemImage\\Rune Stone.bmp");
	ResMgr::GetInst()->ImgLoad(L"Leather", L"Image\\ItemImage\\Leather.bmp");
	ResMgr::GetInst()->ImgLoad(L"Wooden Plank", L"Image\\ItemImage\\Wooden Plank.bmp");
	ResMgr::GetInst()->ImgLoad(L"Copper Ingot", L"Image\\ItemImage\\Copper Ingot.bmp");
	ResMgr::GetInst()->ImgLoad(L"Copper Nugget", L"Image\\ItemImage\\Copper Nugget.bmp");
	ResMgr::GetInst()->ImgLoad(L"Book", L"Image\\ItemImage\\Book.bmp");
	ResMgr::GetInst()->ImgLoad(L"Torch", L"Image\\ItemImage\\Torch.bmp");
	ResMgr::GetInst()->ImgLoad(L"Crate", L"Image\\ItemImage\\Crate.bmp");
	ResMgr::GetInst()->ImgLoad(L"Meat", L"Image\\ItemImage\\Meat.bmp");
	ResMgr::GetInst()->ImgLoad(L"Silver Ingot", L"Image\\ItemImage\\Silver Ingot.bmp");
	ResMgr::GetInst()->ImgLoad(L"Silver Key", L"Image\\ItemImage\\Silver Key.bmp");
	ResMgr::GetInst()->ImgLoad(L"Knife", L"Image\\ItemImage\\Knife.bmp");
	ResMgr::GetInst()->ImgLoad(L"Helm", L"Image\\ItemImage\\Helm.bmp");
	ResMgr::GetInst()->ImgLoad(L"Iron Helmet", L"Image\\ItemImage\\Iron Helmet.bmp");
	ResMgr::GetInst()->ImgLoad(L"Ham", L"Image\\ItemImage\\Ham.bmp");
	ResMgr::GetInst()->ImgLoad(L"Chest", L"Image\\ItemImage\\Chest.bmp");
	ResMgr::GetInst()->ImgLoad(L"Diamond", L"Image\\ItemImage\\Diamond.bmp");
	ResMgr::GetInst()->ImgLoad(L"Cut Ruby", L"Image\\ItemImage\\Cut Ruby.bmp");
	ResMgr::GetInst()->ImgLoad(L"Cut Sapphire", L"Image\\ItemImage\\Cut Sapphire.bmp");
	ResMgr::GetInst()->ImgLoad(L"Red Potion 2", L"Image\\ItemImage\\Red Potion 2.bmp");
	ResMgr::GetInst()->ImgLoad(L"Heart", L"Image\\ItemImage\\Heart.bmp");
	ResMgr::GetInst()->ImgLoad(L"Skull", L"Image\\ItemImage\\Skull.bmp");
	ResMgr::GetInst()->ImgLoad(L"Golden Ingot", L"Image\\ItemImage\\Golden Ingot.bmp");
	ResMgr::GetInst()->ImgLoad(L"Golden Key", L"Image\\ItemImage\\Golden Key.bmp");
	ResMgr::GetInst()->ImgLoad(L"Lantern", L"Image\\ItemImage\\Lantern.bmp");
	ResMgr::GetInst()->ImgLoad(L"Leather Helmet", L"Image\\ItemImage\\Leather Helmet.bmp");
	ResMgr::GetInst()->ImgLoad(L"Paper", L"Image\\ItemImage\\Paper.bmp");
	ResMgr::GetInst()->ImgLoad(L"Bone", L"Image\\ItemImage\\Bone.bmp");
}

//Image* SpriteSO::GetSpriteData(const wstring& key)
//{
//	return ResMgr::GetInst()->ImgFind(key);
//}
