#include "MainMenuScene.h"
#include "scenes_manager.h"

using namespace cocos2d;
using namespace extension;

bool MainMenuScene::init()
{
    if(!CCLayer::init())
        return false;
    
    return true;
}

SEL_MenuHandler MainMenuScene::onResolveCCBCCMenuItemSelector(CCObject *pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onPressButton", MainMenuScene::onPressButton);
    return NULL;
};

void MainMenuScene::onPressButton(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCLOG("load game scene");
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->replaceScene(loadGameScene());
};


SEL_CCControlHandler MainMenuScene::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char* pSelectorName)
{
//    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressButton", MainMenuScene::onPressButton);
    
    return NULL;
};