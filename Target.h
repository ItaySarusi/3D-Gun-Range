#if !defined( TARGET_H )
#define TARGET_H

#pragma once
#include "CCircle.h"
#include "CModel.h"
#include "GameState.h"

class Target : public CModel
{
public:
	Target();
	void TargetMovement(GameState &gs1);
	~Target();
};

#endif