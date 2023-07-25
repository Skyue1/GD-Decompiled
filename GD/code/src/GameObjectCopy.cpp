#include "../headers/includes.h"

GameObjectCopy* GameObjectCopy::create(GameObject* obj)
{
	auto pRet = new GameObjectCopy;

	if (pRet && pRet->init(obj))
	{
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}
