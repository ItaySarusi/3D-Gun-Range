#if !defined( GAMESTATE_H )
#define GAMESTATE_H

#pragma once


class GameState
{
public:
	GameState();
	void Gameover();
	void StageChange();
	void GameFinished();
	void Stage2LivePlus1();
	void Stage3LivePlus3();

	int GetLives();
	void SetLives(int lives);
	double GetXChange();
	void SetXChange(double x);
	double GetGunMove();
	void SetGunMove(double gm);
	bool GetGameOver();
	void SetGameOver(bool GO);
	int GetStage();
	void SetStage(int St);
	int GetLevelNum();
	void SetLevelNum(int LN);
	double GetXCMulti();
	void SetXCMulti(double xCM);
	bool GetCongratz();
	void SetCongratz(bool C);
	bool GetStageUp();
	void SetStageUp(bool SU);
	bool GetShotMissed();
	void SetShotMissed(bool SM);
	bool GetBulletHitTarget();
	void SetBulletHitTarget(bool BHT);
	bool GetBullsEye();
	void SetBullsEye(bool BE);
	bool GetGameStarted();
	void SetGameStarted(bool GS);
	bool GetFirstShotBeenShot();
	void SetFirstShotBeenShot(bool FSBS);
	bool GetGameReboot();
	void SetGameReboot(bool GGR);
	bool GetBBS();
	void SetBBS(bool BULLETBS);

	void RESET();

	void AdvanceLevel();
	void ShootingHandler();


private:
	int lives;
	double xChange;
	double gunMove;
	bool GameOver;
	int Stage;
	int Level_Number;
	double xChange_Multiplier;
	bool Congratz;
	bool StageUp;
	bool ShotMissed;
	bool BulletHitTarget;
	bool BullsEye;
	bool GameStarted;
	bool FirstShotBeenShot;
	bool GameReboot;
	bool BULLETbeenSHOT;
};

#endif