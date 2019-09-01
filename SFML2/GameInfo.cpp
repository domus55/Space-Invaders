#include "GameInfo.h"

int GameInfo::deltaTime = 0;

void GameInfo::setDeltaTime(int DeltaTime)
{
	if (DeltaTime >= 0 && DeltaTime <= 2000)
		GameInfo::deltaTime = DeltaTime;
}

int GameInfo::getDeltaTime()
{
	return deltaTime;
}
