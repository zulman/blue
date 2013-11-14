#include "Level.h"
#include "Dragon.h"
#include "scenes_manager.h"

#define kCJScrollFilterFactor 0.1
#define kCJDragonTargetOffset 80

Level::Level()
: _dragon(NULL)
{
  
}

Level::~Level()
{
  CC_SAFE_RELEASE(_dragon);
}

bool Level::init()
{
  if (!CCLayer::init()) {
    return false;
  }
  return true;
}
SEL_MenuHandler Level::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
  return NULL;
}

SEL_CCControlHandler Level::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
  return NULL;
}

bool Level::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
  CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "dragon", Dragon*, this->_dragon);
  return false;
}

void Level::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    PhysSprite *bomb = PhysSprite::spriteWithWorld(world);
    bomb->activateCollisions();
    
    this->addChild(bomb);
}

void Level::onEnter()
{
    PhysGameScene::onEnter();

    // Schedule a selector that is called every frame
    this->scheduleUpdate();

    //enabling as targeted touch delegate
    this->setTouchMode(kCCTouchesOneByOne);
    this->setTouchEnabled(true);
}

void Level::onExit()
{
  CCLayer::onExit();
  
  // Remove the scheduled selector
  this->unscheduleUpdate();
}

void Level::update(float delta)
{
  PhysGameScene::update(delta);
  // Iterate through all objects in the level layer
  CCObject* child;
  CCARRAY_FOREACH(this->getChildren(), child)
  {
    GameObject* gameObject = dynamic_cast<GameObject*>(child);
    // Check if the child is a game object
    if (gameObject)
    {
      // Update all game objects
      gameObject->update();
      
      // Check for collisions with dragon
      if (gameObject != _dragon)
      {
        if (ccpDistance(gameObject->getPosition(), _dragon->getPosition()) < gameObject->getRadius() + _dragon->getRadius())
        {
          // Notify the game objects that they have collided
          gameObject->handleCollisionWith(_dragon);
          _dragon->handleCollisionWith(gameObject);
        }
      }
    }
  }
  
  // Check for objects to remove
  CCArray* gameObjectsToRemove = CCArray::create();
  CCARRAY_FOREACH(this->getChildren(), child)
  {
    GameObject* gameObject = dynamic_cast<GameObject*>(child);
    if (gameObject)
    {
      if (gameObject->getScheduledForRemove())
      {
        gameObjectsToRemove->addObject(gameObject);
      }
    }
  }

  CCARRAY_FOREACH(gameObjectsToRemove, child)
  {
    GameObject* gameObject = dynamic_cast<GameObject*>(child);
    this->removeChild(gameObject, true);
  }
  
  // Adjust the position of the layer so dragon is visible
  float yTarget = kCJDragonTargetOffset - _dragon->getPosition().y;
  CCPoint oldLayerPosition = this->getPosition();
  
  float xNew = oldLayerPosition.x-2.0f;
  float yNew = oldLayerPosition.y;
//  float yNew = yTarget * kCJScrollFilterFactor + oldLayerPosition.y * (1.0f - kCJScrollFilterFactor);
  
  // this->setPosition(ccp(xNew, yNew));
}



bool Level::ccTouchBegan(CCTouch *ptouch, CCEvent *pEvent)
{
    PhysGameScene::ccTouchBegan(ptouch, pEvent);
//    CCLOG("ccTouchBegan level");
    CCPoint location = this->convertTouchToNodeSpace(ptouch);
    _dragon->setXTarget(location.x);

    CCLOG("dragon (%f, %f) touch (%f, %f)",
          _dragon->getPosition().x, _dragon->getPosition().y,
          location.x, location.y);
    
    CCObject* child;
    CCARRAY_FOREACH(this->getChildren(), child)
    {
        GameObject* gameObject = dynamic_cast<GameObject*>(child);
        // Check if the child is a game object
        if (gameObject)
        {
            // Update all game objects
            gameObject->update();
            
            // Check for collisions with dragon
//            if (gameObject != _dragon)
//            {
                if (ccpDistance(gameObject->getPosition(), location) < gameObject->getRadius())
                {
                    // Notify the game objects that they have collided
//                    gameObject->handleCollisionWith(_dragon);
                    CCNode* explosion = loadExplosion();
                    explosion->setPosition(location);
                    this->addChild(explosion);

                }
//            }
        }
    }
    return true;
}

void Level::ccTouchMoved(CCTouch *ptouch, CCEvent *pEvent)
{
    PhysGameScene::ccTouchMoved(ptouch, pEvent);
//    CCLOG("ccTouchMoved level");

    CCPoint location = this->convertTouchToNodeSpace(ptouch);
    _dragon->setXTarget(location.x);
}

void Level::ccTouchEnded(CCTouch *ptouch, CCEvent *pEvent)
{
    PhysGameScene::ccTouchEnded(ptouch, pEvent);
//    CCLOG("ccTouchEnded level");
}

void Level::ccTouchCancelled(CCTouch *ptouch, CCEvent *pEvent)
{
    PhysGameScene::ccTouchCancelled(ptouch, pEvent);
//    CCLOG("ccTouchCancelled level");
}
