#pragma once
#include "Object.h"
#include "Collider.h"
class Image;
class Background;
class Button :
	public Object
{
	// Object을(를) 통해 상속됨
public:
	virtual void Update() override;
	virtual Object* Clone() override;
	virtual void Render(HDC _dc) override;
private:
	Image* backgroundImage;
public:
	bool	StayCollision(POINT ps);
	void	SetImage(const wstring& str, const wstring& path);
	void	SetBackground(Image* image) { backgroundImage = image; }
};

