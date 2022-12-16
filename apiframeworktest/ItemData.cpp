#include "pch.h"
#include "ItemData.h"
#include "TextSO.h"
#include "SpriteSO.h"
#include "Image.h"
#include "ResMgr.h"

ItemData::ItemData(wstring nameAddress, wstring textAddress, wstring spriteAddress)
{
	this->nameAddress = nameAddress;
	this->textAddress = textAddress;
	this->spriteAddress = spriteAddress;
}

wstring ItemData::GetName()
{
	return TextSO::GetInst()->GetTextData(nameAddress);
}

wstring ItemData::GetText()
{
	return TextSO::GetInst()->GetTextData(textAddress);
}

Image* ItemData::GetSprite()
{
	return ResMgr::GetInst()->ImgFind(spriteAddress);
}
