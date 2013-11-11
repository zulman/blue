#include "Dragon.h"
#include "Explosion.h"

USING_NS_CC;
USING_NS_CC_EXT;

Explosion::Explosion()
{
}

bool Explosion::init()
{
  if (!GameObject::init()) {
    return false;
  }
  return true;
}

void Explosion::onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader)
{
  CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
  if (animationManager) {
    animationManager->setDelegate(this);
  }
}

void Explosion::completedAnimationSequenceNamed(const char *name)
{
  this->setScheduledForRemove(true);
}
