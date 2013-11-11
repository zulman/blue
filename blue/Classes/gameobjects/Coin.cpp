#include "Coin.h"
#include "Dragon.h"
#include "cocos-ext.h"
#include "GameScene.h"

Coin::Coin()
: _isEndCoin(false)
{}

bool Coin::init()
{
  if (!GameObject::init()) {
    return false;
  }
  _radius = 25;
  return true;
}

void Coin::handleCollisionWith(GameObject* gameObject)
{
  Dragon *object = dynamic_cast<Dragon*>(gameObject);
  if (object) {
    if (_isEndCoin)
    {
      // Level is complete!
      GameScene::sharedScene()->onLevelComplete();
    }
    // Collided with the dragon, remove object and add an exposion instead
    this->setScheduledForRemove(true);
  }
}

bool Coin::onAssignCCBCustomProperty(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::extension::CCBValue *pCCBValue)
{
    bool ret = false;
    if (pTarget == this)
    {
        if ( 0  == strcmp(pMemberVariableName, "isEndCoin"))
        {
            this->_isEndCoin = pCCBValue->getBoolValue();
            ret = true;
        }
    }
    return ret;
}
