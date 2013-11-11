#ifndef blue_Explosion_h
#define blue_Explosion_h

#include "GameObject.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Explosion : public GameObject
{
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Explosion, create);
 
  Explosion();
  virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
  virtual void completedAnimationSequenceNamed(const char *name);
  virtual bool init();
public:
  

};
class ExplosionLoader : public cocos2d::extension::CCNodeLoader {
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ExplosionLoader, loader);
  
protected:
  CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Explosion);
  
};

#endif
