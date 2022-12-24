#pragma once
#include "Object.h"
class TextObject :
	public Object
{
public:
	TextObject();
	virtual ~TextObject();

public:
	virtual void Update() override;
	virtual void Render(HDC _dc) override;

public:
	void SetCreditText(wstring wstr) { creditText = wstr; }
	void SetMoveValue(float _x, float _y) { x = _x; y = _y; }
private:
	CLONE(TextObject);

private:
	wstring creditText;
	float x;
	float y;
};

