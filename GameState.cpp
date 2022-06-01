#include "GameState.h"



GameState::GameState()
{
	RESET();
	GameReboot = true;

}
void GameState::Gameover()
{
	xChange = 0;
	gunMove = 0;
	GameOver = true;
}
void GameState::StageChange()
{
	Stage++;
	Level_Number = 1;
	xChange_Multiplier = 1;
}
void GameState::GameFinished()
{
	Congratz = true;
	xChange = 0;
	gunMove = 0;
}
void GameState::Stage2LivePlus1()
{
	lives++;
	StageUp = true;
}
void GameState::Stage3LivePlus3()
{
	lives += 3;
	StageUp = true;
}

int GameState::GetLives()
{
	return lives;
}

void GameState::SetLives(int lives)
{
	this->lives = lives;
}

double GameState::GetXChange()
{
	return xChange;
}

void GameState::SetXChange(double x)
{
	this->xChange = x;
}

double GameState::GetGunMove()
{
	return gunMove;
}

void GameState::SetGunMove(double gm)
{
	this->gunMove = gm;
}

bool GameState::GetGameOver()
{
	return GameOver;
}

void GameState::SetGameOver(bool GO)
{
	this->GameOver = GO;
}

int GameState::GetStage()
{
	return Stage;
}

void GameState::SetStage(int St)
{
	this->Stage = St;
}

int GameState::GetLevelNum()
{
	return Level_Number;
}

void GameState::SetLevelNum(int LN)
{
	this->Level_Number = LN;
	AdvanceLevel();
}

void GameState::AdvanceLevel()
{
	if (GetStage() < 3)
		SetXCMulti(GetXCMulti() + 4);
	else if (GetStage() == 3)
		SetXCMulti(GetXCMulti() * 1.5);
}

double GameState::GetXCMulti()
{
	return xChange_Multiplier;
}

void GameState::SetXCMulti(double xCM)
{
	this->xChange_Multiplier = xCM;
}

bool GameState::GetCongratz()
{
	return Congratz;
}

void GameState::SetCongratz(bool C)
{
	this->Congratz = C;
}

bool GameState::GetStageUp()
{
	return StageUp;
}

void GameState::SetStageUp(bool SU)
{
	this->StageUp = SU;
}

bool GameState::GetShotMissed()
{
	return ShotMissed;
}

void GameState::SetShotMissed(bool SM)
{
	this->ShotMissed = SM;
}

bool GameState::GetBulletHitTarget()
{
	return BulletHitTarget;
}

void GameState::SetBulletHitTarget(bool BHT)
{
	this->BulletHitTarget = BHT;
}

bool GameState::GetBullsEye()
{
	return BullsEye;
}

void GameState::SetBullsEye(bool BE)
{
	this->BullsEye = BE;
}

bool GameState::GetGameStarted()
{
	return GameStarted;
}

void GameState::SetGameStarted(bool GS)
{
	this->GameStarted = GS;
}

bool GameState::GetFirstShotBeenShot()
{
	return FirstShotBeenShot;
}

void GameState::SetFirstShotBeenShot(bool FSBS)
{
	this->FirstShotBeenShot = FSBS;
}

bool GameState::GetGameReboot()
{
	return GameReboot;
}

void GameState::SetGameReboot(bool GGR)
{
	this->GameReboot = GGR;
}

bool GameState::GetBBS()
{
	return BULLETbeenSHOT;
}

void GameState::SetBBS(bool BULLETBS)
{
	this->BULLETbeenSHOT = BULLETBS;
}

void GameState::ShootingHandler()
{
	SetGameStarted(true);
	if (GetLevelNum() >= 1)
	{
		SetBBS(true);
	}
	if (GetLevelNum() == 0)
	{
		SetLevelNum(GetLevelNum() + 1);
	}
	// on stage 3 target changes direction with each shot
	if (GetStage() == 3)
	{
		SetXCMulti(GetXCMulti() * -1);
	}
}

void GameState::RESET()
{
	if (xChange < 0)
	{
		xChange *= -1;
	}
	GameOver = false;
	Congratz = false;
	Stage = 1;
	lives = 10;
	GameStarted = false;
	FirstShotBeenShot = false;
	Level_Number = 0;
	xChange_Multiplier = 1;
	gunMove = 1;
	ShotMissed = false;
	BulletHitTarget = false;
	BullsEye = false;
	StageUp = false;
	GameReboot = false;
}