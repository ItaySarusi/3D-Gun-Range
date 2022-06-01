#pragma once
#include "CBall.h"
#include "Target.h"
#include "GameState.h"
class Bullet :
	public CBall
{
public:
	Bullet();
	void BulletShot();
	void BulletComeBack();
	void BulletHitCheck(GameState &gs1, Target &target);
};

