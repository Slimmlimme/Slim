#include "stdafx.h"
#include "Info.h"

Info::Info()
{
}

Info::Info(int score, int beginTime)
{
	score_ = score;
	beginTime_ = beginTime;
}

const int& 
Info::getScore() const
{
	return score_;
}

void 
Info::score(const int & score)
{
	score_ = score;
}

const int& 
Info::getPlayerHealth() const
{
	return playerHealth_;
}

void 
Info::playerHealth(const int & playerHealth)
{
	playerHealth_ = playerHealth;
}

void 
Info::currentTime(const int & currentTime)
{
	currentTime_ = currentTime;
}

const int& 
Info::getTime() const
{
	return currentTime_ - beginTime_;
}
