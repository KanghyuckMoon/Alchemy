#pragma once
#include "Object.h"
class Image;
class ItemAfterImage;
class ItemMoveEffect : public Object  
{
public:
	ItemMoveEffect();
	virtual ~ItemMoveEffect();

public:
	static void SetEffect(Object* object, Vec2 target, Image* image, shared_ptr<vector<ItemMoveEffect*>> itemMoveEffects);
	static void SetEffect(Vec2 origin, Vec2 scale, Vec2 target, Image* image, shared_ptr<vector<ItemMoveEffect*>> itemMoveEffects);

public:
	void SetImage(Image* image);
	bool GetIsMove() { return isMove; }

public:
	virtual void Update() override;
	virtual void Render(HDC _dc) override;
	void SetMove(bool isbool);

private:
	CLONE(ItemMoveEffect);

private:
	bool isMove = false;
	Image* image;
	Vec2 target = {0,0};
	float time = 0.f;
	vector<shared_ptr<ItemAfterImage>> itemafterImages;

};

