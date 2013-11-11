#ifndef blue_scenes_manager_h
#define blue_scenes_manager_h
#include "cocos2d.h"
#include "cocos-ext.h"
#include "ccb_loader.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "Level.h"
#include "Dragon.h"
#include "Explosion.h"
#include "Bomb.h"
#include "Coin.h"
#include "GB2ShapeCache-x.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

static CCScene* loadMainMenu()
{
    map<string, CCNodeLoader*> loader_map;
    loader_map.insert(make_pair("MainMenuScene", MainMenuSceneLoader::loader()));
    return (CCScene*)loadCCBFile("scenes/MainMenuScene.ccbi", loader_map);
}

static CCScene* loadGameScene()
{
    map<string, CCNodeLoader*> loader_map;
    loader_map.insert(make_pair("GameScene", GameSceneLoader::loader()));
    return (CCScene*)loadCCBFile("scenes/GameScene.ccbi", loader_map);
}

static Level* loadLevel()
{
    map<string, CCNodeLoader*> loader_map;
    loader_map.insert(make_pair("Level", LevelLoader::loader()));
    loader_map.insert(make_pair("Dragon", DragonLoader::loader()));
    loader_map.insert(make_pair("Explosion", ExplosionLoader::loader()));
    loader_map.insert(make_pair("Bomb", BombLoader::loader()));
    loader_map.insert(make_pair("Coin", CoinLoader::loader()));
    GB2ShapeCache::sharedGB2ShapeCache()->addShapesWithFile("gift_phys.plist");
    return dynamic_cast<Level*>(loadCCBFile("scenes/Level.ccbi", loader_map));
}

static CCNode* loadExplosion()
{
    map<string, CCNodeLoader*> loader_map;
    loader_map.insert(make_pair("Explosion", ExplosionLoader::loader()));
    return loadCCBFile("gameobjects/explosion.ccbi", loader_map);
}
#endif
