#include "../headers/includes.h"

GameStatsManager *GameStatsManager::sharedState(AccountLayer *this)
{
	static GameStatsManager* s_pSharedGameStatsManager = nullptr;

	if (!s_pSharedGameStatsManager)
	{
		s_pSharedGameStatsManager = new GameStatsManager();
		s_pSharedGameStatsManager->init();
	}

	return s_pSharedGameStatsManager;
}

GameLevelManager *GameStatsManager::getStat(const char *stat)
{
	return dynamic_cast<GameLevelManager*>(this->m_pStars->objectForKey(stat));
}
