#include "pch.h"
#include "ItemData.h"
#include "TextSO.h"
#include "SpriteSO.h"
#include "Image.h"
#include "ResMgr.h"

ItemData::ItemData(wstring key, wstring nameAddress, wstring textAddress, wstring spriteAddress)
{
	this->key = key;
	this->nameAddress = nameAddress;
	this->textAddress = textAddress;
	this->spriteAddress = spriteAddress;
}

wstring ItemData::GetKey()
{
	return this->key;
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

wstring ItemData::GetNameAddress()
{
	return this->nameAddress;
}

wstring ItemData::GetTextAddress()
{
	return this->textAddress;
}

wstring ItemData::GetSpriteAddress()
{
	return this->spriteAddress;
}
