#include "Gun.h"
#include <math.h>
#include "CModel.h"
#include "CPolygon.h"
#include "CCircle.h"



Gun::Gun(void)
{
	SetNumberOfPolygons(31);

	CPolygon square_in_cube;
	square_in_cube.SetNumberOfPoints(4);
	square_in_cube.SetOnePointCoordinates(0, 0, 0, 1);
	square_in_cube.SetOnePointCoordinates(1, 0.75, 0, 1);
	square_in_cube.SetOnePointCoordinates(2, 0.75, 0, 0);
	square_in_cube.SetOnePointCoordinates(3, 0, 0, 0);
	square_in_cube.SetPolygonColor(1, 0, 0);
	SetOnePolygon(0, square_in_cube);

	CPolygon square_in_cubeA;
	square_in_cubeA.SetNumberOfPoints(4);
	square_in_cubeA.SetOnePointCoordinates(0, 0, 1, 0);
	square_in_cubeA.SetOnePointCoordinates(1, 0, 0, 0);
	square_in_cubeA.SetOnePointCoordinates(2, 0, 0, 1);
	square_in_cubeA.SetOnePointCoordinates(3, 0, 1, 1);
	square_in_cubeA.SetPolygonColor(1, 0, 0);
	SetOnePolygon(1, square_in_cubeA);

	CPolygon square_in_cubeB;
	square_in_cubeB.SetNumberOfPoints(4);
	square_in_cubeB.SetOnePointCoordinates(3, 0, 0, 1);
	square_in_cubeB.SetOnePointCoordinates(2, 0, 1, 1);
	square_in_cubeB.SetOnePointCoordinates(1, 0.75, 1, 1);
	square_in_cubeB.SetOnePointCoordinates(0, 0.75, 0, 1);
	square_in_cubeB.SetPolygonColor(1, 0, 0);
	SetOnePolygon(2, square_in_cubeB);

	CPolygon square_in_cubeC;
	square_in_cubeC.SetNumberOfPoints(4);
	square_in_cubeC.SetOnePointCoordinates(0, 0, 0, 0);
	square_in_cubeC.SetOnePointCoordinates(1, 0, 1, 0);
	square_in_cubeC.SetOnePointCoordinates(2, 0.75, 1, 0);
	square_in_cubeC.SetOnePointCoordinates(3, 0.75, 0, 0);
	square_in_cubeC.SetPolygonColor(1, 0, 0);
	SetOnePolygon(3, square_in_cubeC);

	CPolygon square_in_cubeD;
	square_in_cubeD.SetNumberOfPoints(4);
	square_in_cubeD.SetOnePointCoordinates(3, 0.75, 1, 0);
	square_in_cubeD.SetOnePointCoordinates(2, 0.75, 0, 0);
	square_in_cubeD.SetOnePointCoordinates(1, 0.75, 0, 1);
	square_in_cubeD.SetOnePointCoordinates(0, 0.75, 1, 1);
	square_in_cubeD.SetPolygonColor(1, 0, 0);
	SetOnePolygon(4, square_in_cubeD);

	CPolygon Trigger;
	Trigger.SetNumberOfPoints(4);
	Trigger.SetOnePointCoordinates(3, 0.2, 1.75, -0.375);
	Trigger.SetOnePointCoordinates(2, 0.55, 1.75, -0.375);
	Trigger.SetOnePointCoordinates(1, 0.55, 1.35, -0.375);
	Trigger.SetOnePointCoordinates(0, 0.2, 1.35, -0.375);
	Trigger.SetPolygonColor(1, 1, 1);
	SetOnePolygon(5, Trigger);
	
	CPolygon square_in_cube1;
	square_in_cube1.SetNumberOfPoints(4);
	square_in_cube1.SetOnePointCoordinates(3, 0, 1, 0);
	square_in_cube1.SetOnePointCoordinates(2, 0.75, 1, 0);
	square_in_cube1.SetOnePointCoordinates(1, 0.75, 2, 0);
	square_in_cube1.SetOnePointCoordinates(0, 0, 2, 0);
	square_in_cube1.SetPolygonColor(1, 0, 0);
	SetOnePolygon(6, square_in_cube1);

	CPolygon square_in_cube2;
	square_in_cube2.SetNumberOfPoints(4);
	square_in_cube2.SetOnePointCoordinates(0, 0, 1, 1);
	square_in_cube2.SetOnePointCoordinates(1, 0.75, 1, 1);
	square_in_cube2.SetOnePointCoordinates(2, 0.75, 1.75, 1);
	square_in_cube2.SetOnePointCoordinates(3, 0, 1.75, 1);
	square_in_cube2.SetPolygonColor(0.4, 0.4, 0.4);
	SetOnePolygon(7, square_in_cube2);

	CPolygon square_in_cube3;
	square_in_cube3.SetNumberOfPoints(4);
	square_in_cube3.SetOnePointCoordinates(0, 0, 1.33, 0);
	square_in_cube3.SetOnePointCoordinates(1, 0.75, 1.33, 0);
	square_in_cube3.SetOnePointCoordinates(2, 0.75, 1.33, -0.75);
	square_in_cube3.SetOnePointCoordinates(3, 0, 1.33, -0.75);
	square_in_cube3.SetPolygonColor(1, 0, 0);
	SetOnePolygon(8, square_in_cube3);

	CPolygon square_in_cube4;
	square_in_cube4.SetNumberOfPoints(4);
	square_in_cube4.SetOnePointCoordinates(3, 0, 1, 0);
	square_in_cube4.SetOnePointCoordinates(2, 0, 1.75, 0);
	square_in_cube4.SetOnePointCoordinates(1, 0, 1.75, 1);
	square_in_cube4.SetOnePointCoordinates(0, 0, 1, 1);
	square_in_cube4.SetPolygonColor(0.4,0.4,0.4);
	SetOnePolygon(9, square_in_cube4);

	CPolygon square_in_cube6;
	square_in_cube6.SetNumberOfPoints(4);
	square_in_cube6.SetOnePointCoordinates(0, 0.75, 1, 0);
	square_in_cube6.SetOnePointCoordinates(1, 0.75, 1.75, 0);
	square_in_cube6.SetOnePointCoordinates(2, 0.75, 1.75, 1);
	square_in_cube6.SetOnePointCoordinates(3, 0.75, 1, 1);
	square_in_cube6.SetPolygonColor(0.4,0.4,0.4);
	SetOnePolygon(10, square_in_cube6);

	CPolygon square_in_cube7;
	square_in_cube7.SetNumberOfPoints(4);
	square_in_cube7.SetOnePointCoordinates(3, 0, 1.33, -0.75);
	square_in_cube7.SetOnePointCoordinates(2, 0.75, 1.33, -0.75);
	square_in_cube7.SetOnePointCoordinates(1, 0.75, 1.75, -0.75);
	square_in_cube7.SetOnePointCoordinates(0, 0, 1.75, -0.75);
	square_in_cube7.SetPolygonColor(1, 0, 0);
	SetOnePolygon(11, square_in_cube7);

	CPolygon square_in_cube8;
	square_in_cube8.SetNumberOfPoints(4);
	square_in_cube8.SetOnePointCoordinates(0, 0, 1.75, 0);
	square_in_cube8.SetOnePointCoordinates(1, 0.75, 1.75, 0);
	square_in_cube8.SetOnePointCoordinates(2, 0.75, 1.75, -1.5);
	square_in_cube8.SetOnePointCoordinates(3, 0, 1.75, -1.5);
	square_in_cube8.SetPolygonColor(0.4,0.4,0.4);
	SetOnePolygon(12, square_in_cube8);

	CPolygon Trigger_Other_Side;
	Trigger_Other_Side.SetNumberOfPoints(4);
	Trigger_Other_Side.SetOnePointCoordinates(0, 0.2, 1.75, -0.375);
	Trigger_Other_Side.SetOnePointCoordinates(1, 0.55, 1.75, -0.375);
	Trigger_Other_Side.SetOnePointCoordinates(2, 0.55, 1.35, -0.375);
	Trigger_Other_Side.SetOnePointCoordinates(3, 0.2, 1.35, -0.375);
	Trigger_Other_Side.SetPolygonColor(1, 1, 1);
	SetOnePolygon(13, Trigger_Other_Side);

	CPolygon square_in_cube9;
	square_in_cube9.SetNumberOfPoints(4);
	square_in_cube9.SetOnePointCoordinates(0, 0, 2, 1);
	square_in_cube9.SetOnePointCoordinates(1, 0.75, 2, 1);
	square_in_cube9.SetOnePointCoordinates(2, 0.75, 2, -1.5);
	square_in_cube9.SetOnePointCoordinates(3, 0, 2, -1.5);
	square_in_cube9.SetPolygonColor(0.4, 0.4, 0.4);
	SetOnePolygon(14, square_in_cube9);

	CPolygon square_in_cube_7_OtherSide;
	square_in_cube_7_OtherSide.SetNumberOfPoints(4);
	square_in_cube_7_OtherSide.SetOnePointCoordinates(0, 0, 1.33, -0.75);
	square_in_cube_7_OtherSide.SetOnePointCoordinates(1, 0.75, 1.33, -0.75);
	square_in_cube_7_OtherSide.SetOnePointCoordinates(2, 0.75, 1.75, -0.75);
	square_in_cube_7_OtherSide.SetOnePointCoordinates(3, 0, 1.75, -0.75);
	square_in_cube_7_OtherSide.SetPolygonColor(1, 0, 0);
	SetOnePolygon(15, square_in_cube_7_OtherSide);

	CPolygon square_in_cube10;
	square_in_cube10.SetNumberOfPoints(4);
	square_in_cube10.SetOnePointCoordinates(3, 0, 1.75, -1.5);
	square_in_cube10.SetOnePointCoordinates(2, 0, 2, -1.5);
	square_in_cube10.SetOnePointCoordinates(1, 0, 2, 1);
	square_in_cube10.SetOnePointCoordinates(0, 0, 1.75, 1);
	square_in_cube10.SetPolygonColor(0.4, 0.4, 0.4);
	SetOnePolygon(16, square_in_cube10);

	CPolygon square_in_cube11;
	square_in_cube11.SetNumberOfPoints(4);
	square_in_cube11.SetOnePointCoordinates(0, 0.75, 1.75, -1.5);
	square_in_cube11.SetOnePointCoordinates(1, 0.75, 2, -1.5);
	square_in_cube11.SetOnePointCoordinates(2, 0.75, 2, 1);
	square_in_cube11.SetOnePointCoordinates(3, 0.75, 1.75, 1);
	square_in_cube11.SetPolygonColor(0.4, 0.4, 0.4);
	SetOnePolygon(17, square_in_cube11);

	CPolygon square_in_cube12;
	square_in_cube12.SetNumberOfPoints(4);
	square_in_cube12.SetOnePointCoordinates(3, 0, 1.75, 1);
	square_in_cube12.SetOnePointCoordinates(2, 0, 2, 1);
	square_in_cube12.SetOnePointCoordinates(1, 0.75, 2, 1);
	square_in_cube12.SetOnePointCoordinates(0, 0.75, 1.75, 1);
	square_in_cube12.SetPolygonColor(0.4, 0.4, 0.4);
	SetOnePolygon(18, square_in_cube12);

	CPolygon square_in_cube13;
	square_in_cube13.SetNumberOfPoints(4);
	square_in_cube13.SetOnePointCoordinates(0, 0, 1.75, -1.5);
	square_in_cube13.SetOnePointCoordinates(1, 0, 2, -1.5);
	square_in_cube13.SetOnePointCoordinates(2, 0.75, 2, -1.5);
	square_in_cube13.SetOnePointCoordinates(3, 0.75, 1.75, -1.5);
	square_in_cube13.SetPolygonColor(0.4, 0.4, 0.4);
	SetOnePolygon(19, square_in_cube13);
	//Sight
	CPolygon square_in_cube14;
	square_in_cube14.SetNumberOfPoints(4);
	square_in_cube14.SetOnePointCoordinates(0, 0.3, 2.1, -1.5);
	square_in_cube14.SetOnePointCoordinates(1, 0.3, 2, -1.5);
	square_in_cube14.SetOnePointCoordinates(2, 0.45, 2, -1.5);
	square_in_cube14.SetOnePointCoordinates(3, 0.45, 2.1, -1.5);
	square_in_cube14.SetPolygonColor(0, 1, 0);
	SetOnePolygon(20, square_in_cube14);

	CPolygon square_in_cube14_OtherSide;
	square_in_cube14_OtherSide.SetNumberOfPoints(4);
	square_in_cube14_OtherSide.SetOnePointCoordinates(3, 0.3, 2.1, -1.5);
	square_in_cube14_OtherSide.SetOnePointCoordinates(2, 0.3, 2, -1.5);
	square_in_cube14_OtherSide.SetOnePointCoordinates(1, 0.45, 2, -1.5);
	square_in_cube14_OtherSide.SetOnePointCoordinates(0, 0.45, 2.1, -1.5);
	square_in_cube14_OtherSide.SetPolygonColor(0, 1, 0);
	SetOnePolygon(21, square_in_cube14_OtherSide);

	CCircle bullet_hole;
	bullet_hole.SetNumberOfPoints(4);
	bullet_hole.MovePolygonCenter(3.7, 18.65, -15.1);
	bullet_hole.SetPolygonColor(0, 0, 0);
	bullet_hole.ScalePolygon(0.1,0.1,0.1);
	bullet_hole.RotateSelfPolygon(Y_AXIS, 180);
	SetOnePolygon(22, bullet_hole);

	CCircle bullet_hole_OtherSide;
	bullet_hole_OtherSide.SetNumberOfPoints(4);
	bullet_hole_OtherSide.MovePolygonCenter(3.7, 18.65, -15.1);
	bullet_hole_OtherSide.SetPolygonColor(0, 0, 0);
	bullet_hole_OtherSide.ScalePolygon(0.1, 0.1, 0.1);
	SetOnePolygon(23, bullet_hole_OtherSide);
	//Nitzra
	CPolygon square_in_cube15;
	square_in_cube15.SetNumberOfPoints(4);
	square_in_cube15.SetOnePointCoordinates(0, 0.3, 2.1, 1);
	square_in_cube15.SetOnePointCoordinates(1, 0.3, 2, 1);
	square_in_cube15.SetOnePointCoordinates(2, 0.45, 2, 1);
	square_in_cube15.SetOnePointCoordinates(3, 0.45, 2.1, 1);
	square_in_cube15.SetPolygonColor(0.2,0.3,0.4);
	SetOnePolygon(24, square_in_cube15);

	CPolygon square_in_cube16;
	square_in_cube16.SetNumberOfPoints(4);
	square_in_cube16.SetOnePointCoordinates(0, 0.3, 2.1, 1);
	square_in_cube16.SetOnePointCoordinates(1, 0.45, 2.1, 1);
	square_in_cube16.SetOnePointCoordinates(2, 0.45, 2, 0.95);
	square_in_cube16.SetOnePointCoordinates(3, 0.3, 2, 0.95);
	square_in_cube16.SetPolygonColor(0.2,0.3,0.4);
	SetOnePolygon(25, square_in_cube16);

	CPolygon Triangle_Left;
	Triangle_Left.SetNumberOfPoints(4);
	Triangle_Left.SetOnePointCoordinates(3, 0.3, 2.1, 1);
	Triangle_Left.SetOnePointCoordinates(2, 0.3, 2, 1);
	Triangle_Left.SetOnePointCoordinates(1, 0.3, 2, 0.95);
	Triangle_Left.SetOnePointCoordinates(0, 0.3, 2, 0.95);
	Triangle_Left.SetPolygonColor(0.2,0.3,0.4);
	SetOnePolygon(26, Triangle_Left);

	CPolygon Triangle_Right;
	Triangle_Right.SetNumberOfPoints(4);
	Triangle_Right.SetOnePointCoordinates(0, 0.45, 2.1, 1);
	Triangle_Right.SetOnePointCoordinates(1, 0.45, 2, 1);
	Triangle_Right.SetOnePointCoordinates(2, 0.45, 2, 0.95);
	Triangle_Right.SetOnePointCoordinates(3, 0.45, 2, 0.95);
	Triangle_Right.SetPolygonColor(0.2,0.3,0.4);
	SetOnePolygon(27, Triangle_Right);

	CPolygon square_in_cube17;
	square_in_cube17.SetNumberOfPoints(4);
	square_in_cube17.SetOnePointCoordinates(3, 0, 1.75, 1);
	square_in_cube17.SetOnePointCoordinates(2, 0.75, 1.75, 1);
	square_in_cube17.SetOnePointCoordinates(1, 0.75, 1.75, -1.5);
	square_in_cube17.SetOnePointCoordinates(0, 0, 1.75, -1.5);
	square_in_cube17.SetPolygonColor(0.4, 0.4, 0.4);
	SetOnePolygon(28, square_in_cube17);

	CPolygon Bottom_Of_Gun;
	Bottom_Of_Gun.SetNumberOfPoints(4);
	Bottom_Of_Gun.SetOnePointCoordinates(0, 0, 0, 0);
	Bottom_Of_Gun.SetOnePointCoordinates(1, 0.75, 0, 0);
	Bottom_Of_Gun.SetOnePointCoordinates(2, 0.75, 0, 1);
	Bottom_Of_Gun.SetOnePointCoordinates(3, 0, 0, 1);
	Bottom_Of_Gun.SetPolygonColor(1,0,0);
	SetOnePolygon(29, Bottom_Of_Gun);

	CPolygon Bottom_Of_Trigger;
	Bottom_Of_Trigger.SetNumberOfPoints(4);
	Bottom_Of_Trigger.SetOnePointCoordinates(3, 0, 1.33, 0);
	Bottom_Of_Trigger.SetOnePointCoordinates(2, 0.75, 1.33, 0);
	Bottom_Of_Trigger.SetOnePointCoordinates(1, 0.75, 1.33, -0.75);
	Bottom_Of_Trigger.SetOnePointCoordinates(0, 0, 1.33, -0.75);
	Bottom_Of_Trigger.SetPolygonColor(1, 0, 0);
	SetOnePolygon(30, Bottom_Of_Trigger);
}

