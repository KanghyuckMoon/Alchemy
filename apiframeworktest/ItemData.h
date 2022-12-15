#pragma once
class Image;
class ItemData
{
public:
	ItemData(wstring nameAddress, wstring textAddress, wstring spriteAddress);

public:
	wstring nameAddress;
	wstring textAddress;
	wstring spriteAddress;

public:
	wstring GetName();
	wstring GetText();
	const Image* GetSprite();

};

