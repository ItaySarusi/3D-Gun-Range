#include "Target.h"
#include <stdio.h>


Target::Target()
{
	SetNumberOfPolygons(5);

	CCircle circle5(360);
	circle5.ScaleSelfPolygon(1.3, 1.3, 1.3);
	circle5.SetPolygonColor(1, 0, 0);
	circle5.MovePolygonCenter(-0.142, 0.7, -15);
	SetOnePolygon(0, circle5);
	circle5.ScaleSelfPolygon(0.8, 0.8, 0.8);
	circle5.SetPolygonColor(1, 1, 1);
	circle5.MovePolygon(0, 0, 0.0001);
	SetOnePolygon(1, circle5);
	circle5.ScaleSelfPolygon(0.7, 0.7, 0.7);
	circle5.SetPolygonColor(1, 0, 0);
	circle5.MovePolygon(0, 0, 0.0001);
	SetOnePolygon(2, circle5);
	circle5.ScaleSelfPolygon(0.6, 0.6, 0.6);
	circle5.SetPolygonColor(1, 1, 1);
	circle5.MovePolygon(0, 0, 0.0001);
	SetOnePolygon(3, circle5);
	circle5.ScaleSelfPolygon(0.5, 0.5, 0.5);
	circle5.SetPolygonColor(0.4, 0.4, 0.4);
	circle5.MovePolygon(0, 0, 0.0001);
	SetOnePolygon(4, circle5);

}

void Target::TargetMovement(GameState &gs1)
{
	if (gs1.GetGameReboot() == true)
	{
		gs1.SetXChange(0.0025);
		gs1.SetGameReboot(false);
	}
	if (gs1.GetStage() == 1 && gs1.GetBBS() == false)
	{
		if (GetPolygon(0).GetPolygonCenter().GetCoordinate(X_AXIS) > 10.4)
		{
			gs1.SetXChange(gs1.GetXChange() * -1);
		}
		if (GetPolygon(0).GetPolygonCenter().GetCoordinate(X_AXIS) < -10.4)
		{
			gs1.SetXChange(gs1.GetXChange() * -1);
		}
		MoveModel(gs1.GetXChange() * gs1.GetXCMulti(), 0, 0);
	}
	//Target Movement While The Bullet is Being shot:
	if (gs1.GetStage() > 1)
	{
		if (GetPolygon(0).GetPolygonCenter().GetCoordinate(X_AXIS) > 10.4)
		{
			gs1.SetXChange(gs1.GetXChange() * -1);
		}
		if (GetPolygon(0).GetPolygonCenter().GetCoordinate(X_AXIS) < -10.4)
		{
			gs1.SetXChange(gs1.GetXChange() * -1);
		}
		MoveModel(gs1.GetXChange() * gs1.GetXCMulti(), 0, 0);
	}

}



Target::~Target()
{
}
