#pragma once
class Image;
class ItemData
{
public:
	ItemData(wstring key, wstring nameAddress, wstring textAddress, wstring spriteAddress);

private:
	wstring key;
	wstring nameAddress;
	wstring textAddress;
	wstring spriteAddress;

public:
	wstring GetKey();
	wstring GetName();
	wstring GetText();
	Image* GetSprite();

};

