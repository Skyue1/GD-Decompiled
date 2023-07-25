#include "includes.h"

class GameStatsManager : public cocos2d::CCNode {
public:
		cocos2d::CCDictionary* m_pStars;

		static GameStatsManager* sharedState(AccountLayer* this);
		GameLevelManager* getStat(const char* stat);
};
