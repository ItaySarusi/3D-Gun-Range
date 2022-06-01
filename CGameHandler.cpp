#include <iostream>
#include <math.h>
#include "glut.h"
#include "CGameHandler.h"
#include "stdio.h"
#include "Gun.h"
#include "Target.h"
#include "Bullet.h"
#include "GameState.h"

//defintion of the global variables:
GameState gs1;
int BulletShotTimer = 360;
char Level[128];
char HP[128];
char stages[128];
Gun gun1;
Bullet bullet;
Target target;
//Bullet Hole Polygon Number is 22.


extern void renderBitmapString(float x, float y, void *font, char *string);
extern void renderVerticalBitmapString(float x, float y, int bitmapHeight, void *font, char *string);

void CGameHandler::StartOfGame()
{
	//variables for game handling
	font = def_font = (int)GLUT_BITMAP_HELVETICA_18;
	ChangeBackgroundColors(0, 0, 0);

	//settings of the objects:
	gun1.MoveModel(3.25, -3, -10); // -0.55 X is screen middle.
	gun1.MoveModel(Z_AXIS, 2.5);
	gun1.MoveModel(Y_AXIS, 1);
	gun1.RotateSelfModel(X_AXIS, 3);
	bullet.ScaleModel(0.125, 0.125, 0.125);
	bullet.MoveModel(gun1.GetPolygon(22).GetPolygonCenter());
	bullet.SetBallColors(0, 0.5, 0, 0.3, 0, 0);
	target.GetPolygon(0).MovePolygonCenter(-0.142, 0.7, -15);
}

void CGameHandler::DrawScene()
{
	gun1.DrawModel();
	bullet.DrawModel();
	target.DrawModel();
}
//on each frame:
void CGameHandler::LogicPart()
{
	if (gs1.GetGameStarted() == true && gs1.GetGameOver() == false && gs1.GetCongratz() == false)
	{
		//Target Movement Right To Left:
		if (gs1.GetGameStarted() == true)
		{
			target.TargetMovement(gs1);
		}
		//Bullet Shot:
		if (gs1.GetBBS() == true && BulletShotTimer > 0)
		{
			gs1.SetFirstShotBeenShot(true);
			bullet.BulletShot();
			BulletShotTimer -= 1;
		}
		//Bullet Hit Check:
		if (gs1.GetBBS() == true && BulletShotTimer == 0)
		{
			bullet.BulletHitCheck(gs1, target);
			BulletShotTimer = 360;
			gs1.SetBBS(false);
		}
	}
	//Game Over:
	if (gs1.GetLives() == 0)
	{
		gs1.Gameover();
	}
	//Bring The StageUp bool back for Ready.
	if (gs1.GetStage() == 2 && gs1.GetLevelNum() > 10)
	{
		gs1.SetStageUp(false);
	}
	//Stage Change:
	if ((gs1.GetStage() == 1 || gs1.GetStage() == 2) && gs1.GetLevelNum() > 10)
	{
		gs1.StageChange();
	}
	//Game Finished:
	if (gs1.GetStage() == 3 && gs1.GetLevelNum() > 10)
	{
		gs1.GameFinished();
	}
	//Stage 2 Live +1:
	if (gs1.GetStage() == 2 && gs1.GetStageUp() == false)
	{
		gs1.Stage2LivePlus1();
	}
	//Stage 3 Live +3:
	if (gs1.GetStage() == 3 && gs1.GetStageUp() == false)
	{
		gs1.Stage3LivePlus3();
	}
	//To Check Gun is perfect:
	//gun1.RotateSelfModel(Y_AXIS, 1);
	//gun1.MoveModel(Y_AXIS, 0.003);
}

void CGameHandler::WriteText()
{
	font = (int)GLUT_BITMAP_TIMES_ROMAN_24; // font type and size
	glColor3f(1, 1, 0);  // yellow color
	int x_pos = glutGet(GLUT_SCREEN_WIDTH) / 2 - 100; // to be at the center of the screen
	int y_pos = 30;
	renderBitmapString(x_pos, y_pos, (void *)font, "Target Shooting");
	glColor3f(0, 1, 0);
	if (gs1.GetCongratz() == false)
	{
		sprintf(Level, "Level: %d", gs1.GetLevelNum());
		if (gs1.GetLevelNum() >= 1)
			renderBitmapString(x_pos, y_pos + 60, (void *)font, Level);
		glColor3f(0, 0, 1);
		if (gs1.GetBulletHitTarget() == true && gs1.GetFirstShotBeenShot() == true && gs1.GetBullsEye() == false)
			renderBitmapString(x_pos, y_pos + 90, (void *)font, "Nice Shot!");
		if (gs1.GetShotMissed() == true && gs1.GetFirstShotBeenShot() == true && gs1.GetBullsEye() == false)
			renderBitmapString(x_pos, y_pos + 90, (void *)font, "Miss!");
		if (gs1.GetBullsEye() == true && gs1.GetFirstShotBeenShot() == true)
			renderBitmapString(x_pos, y_pos + 90, (void *)font, "BULLS EYE!");
		glColor3f(1, 0, 0);
		sprintf(HP, "Lives: %d", gs1.GetLives());
		if (gs1.GetLevelNum() >= 1)
			renderBitmapString(x_pos - 850, y_pos, (void *)font, HP);
		glColor3f(1, 0, 1);
		sprintf(stages, "Stage: %d", gs1.GetStage());
		if (gs1.GetLevelNum() >= 1)
			renderBitmapString(x_pos, y_pos + 30, (void *)font, stages);
		if (gs1.GetStage() == 2 && gs1.GetLevelNum() < 3)
			renderBitmapString(x_pos + 90, y_pos + 30, (void *)font, "The Target Will Now Keep Moving When You Shoot !");
		if (gs1.GetStage() == 3 && gs1.GetLevelNum() < 3)
		{
			renderBitmapString(x_pos + 90, y_pos + 30, (void *)font, "The Target Will Now Keep Moving When You Shoot,");
			renderBitmapString(x_pos + 90, y_pos + 60, (void *)font, "And Change Direction When You Shoot !");
		}

		glColor3f(1, 0, 0);
		if (gs1.GetLives() == 0)
		{
			renderBitmapString(x_pos + 425, y_pos + 200, (void *)font, "Game Over!");
			renderBitmapString(x_pos + 375, y_pos + 230, (void *)font, "Press 'R' To Start Again");
		}
		glColor3f(1, 1, 1);
		if (gs1.GetGameStarted() == false)
		{
			renderBitmapString(x_pos + 425, y_pos + 200, (void *)font, "Press Space To Start");
		}
		if (gs1.GetGameStarted() == true && gs1.GetLives() != 0)
		{
			renderBitmapString(x_pos + 425, y_pos + 100, (void *)font, "Press Space to Shoot");
			renderBitmapString(x_pos + 425, y_pos + 130, (void *)font, "<-- Button moves the gun left");
			renderBitmapString(x_pos + 425, y_pos + 160, (void *)font, "--> Button moves the gun right");
			glColor3f(1, 0, 0);
			renderBitmapString(x_pos + 425, y_pos + 190, (void *)font, "Press 'R' To Restart");
		}
	}
	if (gs1.GetCongratz() == true)
	{
		glColor3f(1, 1, 1);
		renderBitmapString(x_pos + 425, y_pos + 100, (void *)font, "Congratulations !");
		renderBitmapString(x_pos + 425, y_pos + 130, (void *)font, "You Finished The Game !");
		renderBitmapString(x_pos + 425, y_pos + 160, (void *)font, "Well Done !");
		glColor3f(1, 0, 0);
		renderBitmapString(x_pos + 425, y_pos + 190, (void *)font, "Press 'R' To Restart");
	}
	if (gs1.GetStageUp() == true && gs1.GetLevelNum() == 1)
	{
		if (gs1.GetStage() == 2)
		{
			renderBitmapString(x_pos - 600, y_pos + 160, (void *)font, "One Life Was Added");
			renderBitmapString(x_pos - 615, y_pos + 190, (void *)font, "For Getting To Stage 2 !");
		}
		if (gs1.GetStage() == 3)
		{
			renderBitmapString(x_pos - 600, y_pos + 160, (void *)font, "Three Lifes Were Added");
			renderBitmapString(x_pos - 615, y_pos + 190, (void *)font, "For Getting To Stage 3 !");
		}

	}
}

//keys:
void CGameHandler::KeyPressed(char key)
{
	switch (key)
	{
	case ' ':
	{
		gs1.ShootingHandler();
		break;
	}
	case 'r':
	{
		gs1.RESET();
		target.MoveModelCenter(-0.142, 0.7, -15);
		break;
	}
	}
}

void CGameHandler::SpecialKeyPressed(char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		if (gun1.GetModelCenter().GetCoordinate(X_AXIS) > -4 && gs1.GetBBS() == false)
		{
			gun1.MoveModel(X_AXIS, -1 * gs1.GetGunMove());
			bullet.MoveModel(X_AXIS, -1 * gs1.GetGunMove());
		}
		break;
	case GLUT_KEY_RIGHT:
		if (gun1.GetModelCenter().GetCoordinate(X_AXIS) < 4 && gs1.GetBBS() == false)
		{
			gun1.MoveModel(X_AXIS, gs1.GetGunMove());
			bullet.MoveModel(X_AXIS, gs1.GetGunMove());
		}
		break;
	case GLUT_KEY_UP:
		break;
	case GLUT_KEY_DOWN:
	default:
		break;
	}
}

//getting backgroundColor
float CGameHandler::GetBeckgroundColorR()
{
	return BGColor_R;
}

float CGameHandler::GetBeckgroundColorG()
{
	return BGColor_G;
}

float CGameHandler::GetBeckgroundColorB()
{
	return BGColor_B;
}

//internal procedures:
void CGameHandler::ChangeBackgroundColors(float R, float G, float B)
{
	BGColor_R = R;
	BGColor_G = G;
	BGColor_B = B;
}