#pragma once
#include "Object.h"
#include "Collider.h"
class Button :
	public Object
{
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual Object* Clone() override;
public:
	bool	StayCollision(POINT ps);
};

