#include "GameObject.h"

USING_NS_CC;
USING_NS_CC_EXT;

GameObject::GameObject():
_radius(0),
_isScheduledForRemove(false)
{
};


bool GameObject::init()
{
    if(!CCNode::init())
        return false;
    
    return true;
}

SEL_MenuHandler GameObject::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

SEL_CCControlHandler GameObject::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

bool GameObject::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}

void GameObject::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
}

void GameObject::completedAnimationSequenceNamed(const char *name)
{
    
}

void GameObject::update()
{
};

void GameObject::handleCollisionWith(GameObject* gameObject)
{
};

bool GameObject::onAssignCCBCustomProperty(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::extension::CCBValue *pCCBValue)
{
    return false;
}