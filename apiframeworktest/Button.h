#pragma once
#include "Object.h"
#include "Collider.h"
class Button :
	public Object
{
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	virtual Object* Clone() override;
public:
	bool	StayCollision(POINT ps);
};

