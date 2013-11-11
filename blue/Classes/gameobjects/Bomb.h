#ifndef blue_Bomb_h
#define blue_Bomb_h

#include "GameObject.h"

USING_NS_CC;
USING_NS_CC_EXT;


class Bomb : public GameObject
{
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Bomb, create);
  Bomb();
  virtual bool init();
public:
  
  virtual void handleCollisionWith(GameObject* gameObject);
};

class BombLoader : public cocos2d::extension::CCNodeLoader {
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BombLoader, loader);
  
protected:
  CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Bomb);
  
};


#endif
