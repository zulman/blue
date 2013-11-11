#ifndef blue_GameScene_h
#define blue_GameScene_h

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class GameScene : public CCLayer, public CCBSelectorResolver, public CCBMemberVariableAssigner, public CCNodeLoaderListener
{
public:
    GameScene();
    virtual ~GameScene();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(GameScene, create);
//    virtual bool init();
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    static GameScene* sharedScene(void);
    void onGameOver();
    void onLevelComplete();
    void increaseScore();
private:
    CCLayer* levelLayer;
    CCLabelTTF* scoreLabel;
    CCNode* level;
    int score;
    void setScore(int score);
    void goToMainMenu();
};


class GameSceneLoader : public CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GameSceneLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GameScene);
};


#endif