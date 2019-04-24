#include "BWTP_Func.h"

class Bullet;

#pragma once
class Lava : public Sprite
{
public:
	Lava(Vec2 position, float scale, int tag, Layer* parent);
	~Lava();

	int getEnemyTag();

private:
	int _tag = 0;
};

