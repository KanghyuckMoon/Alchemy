#pragma once
#include "Object.h"
class Image;
class CharacterImage : public Object
{
public:
	CharacterImage();
	virtual ~CharacterImage();

private:
	CLONE(CharacterImage);
	
private:
	Vec2 originPos;
	Vec2 targetPos;
	Image* image;
	bool isSpot = false;
	float time = 0.f;
	int alpha = 255;
	
public:
	void SetOriginPos(Vec2 pos) { this->originPos = pos; }
	void SetTargetPos(Vec2 pos) { this->targetPos = pos; }
	void SetImage(Image* image) { this->image = image; }
	void SetIsSpot(bool spot);

public:
	virtual void Update() override;
	virtual void Render(HDC _dc) override;


};

