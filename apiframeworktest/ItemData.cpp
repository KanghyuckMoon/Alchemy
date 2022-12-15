#include "pch.h"
#include "ItemData.h"
#include "TextSO.h"
#include "SpriteSO.h"
#include "Image.h"

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

const Image* ItemData::GetSprite()
{
	return SpriteSO::GetInst()->GetSpriteData(spriteAddress);
}
