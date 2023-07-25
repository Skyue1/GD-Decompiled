#include "../headers/includes.h"

void AccountLayer::onBackup(cocos2d::CCObject*)
{
    GameStatsManager* gameStatsManager = GameStatsManager::sharedState(this);
    GameLevelManager* gameLevelManager = GameStatsManager::getStat(gameStatsManager, "6");

    if (gameLevelManager > 9)
    {
        GameLevelManager* sharedGameLevelManager = GameLevelManager::sharedState(gameLevelManager);
        const char* timeLeft = GameLevelManager::getTimeLeft(sharedGameLevelManager, "bak_account", 30.0);

        if (timeLeft - 1 > 0x1D)
        {
          // play backup confirmation sound and create backup confirmation alert
          FMODAudioEngine::playSound("Do you want to <cg>save</c> your game data to the <cl>Cloud</c>?\n<cy>This will overwrite old clouddata");
          FLAlertLayer::create("Backup", "Are you sure you want to backup your account?", "Cancel", "Save", 300.0)->show();
        }
        else
        {
          // play waiting sound and create alert for waiting to backup again
          cocos2d::CCString* message = cocos2d::CCString::createWithFormat("Please wait %i seconds before attempting to backup your account again.", timeLeft);
          const char* cString = cocos2d::CCString::getCString(message);
          FMODAudioEngine::playSound(cString);
          FLAlertLayer::create("Too fast", "Please wait before attempting to backup your account again.", nullptr, "OK", 300.0)->show();
        }
    }
    else
    {
        // play sound and create alert for collecting more stars
        FMODAudioEngine::playSound("You need to <cl>collect</c> at least <cy>10 stars</c> to enable <cg>saving</c>.");
        FLAlertLayer::create("Collect more", "You need to collect at least 10 stars to enable saving.", nullptr, "OK", 300.0);
		}
}
