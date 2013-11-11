#include "GameScene.h"
#include "scenes_manager.h"

using namespace cocos2d;
using namespace extension;

static GameScene* sSharedScene = NULL;

GameScene::GameScene()
: levelLayer(NULL)
, scoreLabel(NULL)
, level(NULL)
, score(0)
{}

GameScene::~GameScene()
{
    CC_SAFE_RELEASE(levelLayer);
    CC_SAFE_RELEASE(scoreLabel);
};

GameScene* GameScene::sharedScene(void) {
    return sSharedScene;
};

void GameScene::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    CCLOG("game scene node loaded");
    sSharedScene = this;
    
    this->setScore(this->score);
    this->level = loadLevel();
    levelLayer->addChild(level);
    
    CCLOG("create bomb");
};

void GameScene::increaseScore()
{
    setScore(score+1);
}

void GameScene::setScore(int score)
{
    this->score = score;
    CCString *val = CCString::createWithFormat("%d", this->score);
    scoreLabel->setString(val->getCString());
}

void GameScene::onGameOver()
{
    CCLOG("game over");
    goToMainMenu();
};

void GameScene::onLevelComplete()
{
    CCLOG("level complete");
    goToMainMenu();
};

void GameScene::goToMainMenu()
{
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->replaceScene(loadMainMenu());
}

bool GameScene::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scoreLabel", CCLabelTTF *, this->scoreLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "levelLayer", CCLayer *, this->levelLayer);
    return false;
};

SEL_MenuHandler GameScene::onResolveCCBCCMenuItemSelector(CCObject *pTarget, const char* pSelectorName)
{
    //  CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onPressButton", GameScene::onPressButton);
    return NULL;
};

SEL_CCControlHandler GameScene::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char* pSelectorName)
{
    //  CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressButton", MainMenuScene::onPressButton);
    return NULL;
};