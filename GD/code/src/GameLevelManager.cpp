#include "../headers/includes.h"

const char *GameLevelManager::getTimeLeft(GameLevelManager *this, const char *key, float defaultValue)
{
	float timeLeft = GameLevelManager::getFloatValue(this, key, defaultValue);
	GameLevelManager::getTotalTimePlayed(this);
	if (timeLeft < 0.0)
			timeLeft = 0.0;

	char* buffer = new char[16];
	sprintf(buffer, "%.0f", timeLeft);
	const char* result = buffer;

	delete[] buffer;
	return result;
}

float GameLevelManager::getFloatValue(GameLevelManager *this, const char *key, float defaultValue)
{
	const char* value = GameLevelManager::getValue(this, key);
	if (value != nullptr)
			return atof(value);
	else
			return defaultValue;
}

float GameLevelManager::getTotalTimePlayed(GameLevelManager *this)
{
	return GameLevelManager::getFloatValue(this, "total_time_played", 0.0);
}

const char *GameLevelManager::getValue(GameLevelManager *this, const char *key)
{
	cocos2d::CCDictionary* levelData = GameLevelManager::getLevelData(this);
	cocos2d::CCString* value = dynamic_cast<cocos2d::CCString*>(levelData->objectForKey(key));
	 if (value != nullptr)
    return value->getCString();
  else
    return nullptr;
}

cocos2d::CCDictionary *GameLevelManager::getLevelData(GameLevelManager *this)
{
	return dynamic_cast<cocos2d::CCDictionary*>(this->m_pLevels->objectForKey(this->m_nCurrentLevel));
}
