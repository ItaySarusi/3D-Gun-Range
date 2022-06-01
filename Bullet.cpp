#include "Bullet.h"


Bullet::Bullet()
{
}

void Bullet::BulletShot()
{
	MoveModel(Z_AXIS, -0.01667);
	MoveModel(Y_AXIS, 0.002);
}
void Bullet::BulletComeBack()
{
	MoveModel(Z_AXIS, 6.0012);
	MoveModel(Y_AXIS, -0.72);
}


void Bullet::BulletHitCheck(GameState &gs1, Target &target)
{
	if (GetModelCenter().GetCoordinate(X_AXIS) >= (target.GetPolygon(0).GetPolygonCenter().GetCoordinate(X_AXIS) - 1.3) && GetModelCenter().GetCoordinate(X_AXIS) <= (target.GetPolygon(0).GetPolygonCenter().GetCoordinate(X_AXIS) + 1.3))
	{
		gs1.SetBullsEye(false);
		gs1.SetShotMissed(false);
		gs1.SetBulletHitTarget(true);
		gs1.SetLevelNum(gs1.GetLevelNum() + 1);
		BulletComeBack();
		if (GetModelCenter().GetCoordinate(X_AXIS) >= (target.GetPolygon(0).GetPolygonCenter().GetCoordinate(X_AXIS) - 0.2184) && GetModelCenter().GetCoordinate(X_AXIS) <= (target.GetPolygon(0).GetPolygonCenter().GetCoordinate(X_AXIS) + 0.2184))
		{
			gs1.SetBullsEye(true);
		}
	}
	else
	{
		gs1.SetBullsEye(false);
		gs1.SetShotMissed(true);
		gs1.SetBulletHitTarget(false);
		BulletComeBack();
		gs1.SetLives(gs1.GetLives() - 1);
	}
}

