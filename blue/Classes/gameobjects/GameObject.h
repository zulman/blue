#ifndef blue_GameObject_h
#define blue_GameObject_h

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class GameObject : public CCNode,
  public CCBAnimationManagerDelegate
, public CCBMemberVariableAssigner
, public CCNodeLoaderListener
, public CCBSelectorResolver

{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(GameObject, create);
    GameObject();
    
    virtual bool init();
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    virtual void completedAnimationSequenceNamed(const char *name);
    
    virtual void update();
    virtual void handleCollisionWith(GameObject* gameObject);
    
    CC_SYNTHESIZE(bool, _isScheduledForRemove, ScheduledForRemove);

    float getRadius()
    {
        return _radius;
    }
private:
protected:
    float _radius;
};


class GameObjectLoader : public CCNodeLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GameObjectLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GameObject);
    
};
#endif