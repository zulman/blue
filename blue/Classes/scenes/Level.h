#ifndef blue_Level_h
#define blue_Level_h

#include "Dragon.h"
#include "PhysGameScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Level
: public PhysGameScene
, public CCBMemberVariableAssigner
, public CCNodeLoaderListener
, public CCBSelectorResolver
{
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Level, create);
  
  Level();
  ~Level();
  
  virtual bool init();

    virtual bool ccTouchBegan(CCTouch *ptouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *ptouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *ptouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *ptouch, CCEvent *pEvent);
//  virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
//  virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
//  virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
//  virtual void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);

  virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
  virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
  virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
  virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
public:
  virtual void onEnter();
  virtual void onExit();
  
  void update(float delta);

private:
   Dragon* _dragon;
};

class LevelLoader : public CCLayerLoader {
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LevelLoader, loader);
  
protected:
  CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Level);
  
};

#endif
