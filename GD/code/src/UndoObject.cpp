#include "../headers/includes.h"

int UndoObject::initWithTransformObjects(cocos2d::CCArray* transformObjects)
{
  unsigned int index = 0;

  auto newArray = cocos2d::CCArray::create();

  while (index < transformObjects->count())
  {
    GameObjectCopy* gameObjectCopy = (GameObjectCopy*)transformObjects->objectAtIndex(index++);
    cocos2d::CCObject* gameObject = (cocos2d::CCObject*)GameObjectCopy::create(gameObjectCopy);
    newArray->addObject(gameObject);
  }

  newArray->retain();
  return 1;
}

int UndoObject::createWithTransformObjects()
{
  int* newObj = new int[12]();

	if (initWithTransformObjects(reinterpret_cast<cocos2d::CCArray*>(newObj)))
	{
		newObj = reinterpret_cast<int*>(CCObject::autorelease(reinterpret_cast<CCObject*>(newObj)));
	}
	else
	{
		delete[] newObj;
		newObj = nullptr;
	}

	return newObj;
}
