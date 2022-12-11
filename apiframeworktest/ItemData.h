#pragma once
class ItemData
{
public:
	ItemData(string nameAddress, string textAddress, string spriteAddress);

public:
	string nameAddress;
	string textAddress;
	string spriteAddress;

public:
	string GetName();
	string GetText();
	int GetSprite();

};

