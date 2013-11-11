#ifndef blue_Coin_h
#define blue_Coin_h

#include "GameObject.h"

USING_NS_CC;
USING_NS_CC_EXT;


class Coin : public GameObject
{
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Coin, create);
  Coin();
  virtual bool init();
  CC_SYNTHESIZE(bool, _isEndCoin, IsEndCoin);
  virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
public:
  virtual void handleCollisionWith(GameObject* gameObject);

};
class CoinLoader : public CCNodeLoader {
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CoinLoader, loader);
  
protected:
  CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Coin);
  
};

#endif
