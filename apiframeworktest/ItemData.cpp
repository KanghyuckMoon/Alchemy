#include "pch.h"
#include "ItemData.h"
#include "TextSO.h"
#include "SpriteSO.h"

ItemData::ItemData(string nameAddress, string textAddress, string spriteAddress)
{
	this->nameAddress = nameAddress;
	this->textAddress = textAddress;
	this->spriteAddress = spriteAddress;
}

string ItemData::GetName()
{
	return TextSO::GetTextData(nameAddress);
}

string ItemData::GetText()
{
	return TextSO::GetTextData(textAddress);
}

int ItemData::GetSprite()
{
	return SpriteSO::GetSpriteData(spriteAddress);
}
