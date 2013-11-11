#include "Dragon.h"
#include "Coin.h"
#include "Bomb.h"
#include "GameScene.h"
#include "CCBAnimationManager.h" 

using namespace cocos2d;
using namespace extension;

#define kCJStartSpeed 8
#define kCJCoinSpeed 8
#define kCJStartTarget 160

#define kCJTargetFilterFactor 0.05
#define kCJSlowDownFactor 0.995
#define kCJGravitySpeed 0.1
#define kCJGameOverSpeed -10
#define kCJDeltaToRotationFactor 5

Dragon::Dragon():
_xTarget(0.0f),
_ySpeed(0.0f)
{
};

bool Dragon::init()
{
    if(!GameObject::init())
        return false;
    
    _xTarget = kCJStartTarget;
    _ySpeed = kCJStartSpeed;
    _radius = 25;
    return true;
}

void Dragon::update()
{
    // Calculate new position
    CCPoint oldPosition = this->getPosition();
    
    float xNew = _xTarget * kCJTargetFilterFactor + oldPosition.x * (1-kCJTargetFilterFactor);
    float yNew = oldPosition.y + _ySpeed;
    
    // this->setPosition(ccp(oldPosition.x + 2.0f,oldPosition.y));
    
    // Update the vertical speed
    _ySpeed = (_ySpeed - kCJGravitySpeed) * kCJSlowDownFactor;
    
    // Tilt the dragon depending on horizontal speed
    float xDelta = xNew - oldPosition.x;
    this->setRotation(xDelta * kCJDeltaToRotationFactor);
    
    // Check for game over
    //if (_ySpeed < kCJGameOverSpeed)
    //    GameScene::sharedScene()->onGameOver();
};

void Dragon::handleCollisionWith(GameObject* gameObject)
{
    Coin* coin = dynamic_cast<Coin*>(gameObject);
    Bomb* bomb = dynamic_cast<Bomb*>(gameObject);
    if (coin)
    {
        // Took a coin
        _ySpeed = kCJCoinSpeed;
        
        GameScene::sharedScene()->increaseScore();
    }
    else if (bomb)
    {
        // Hit a bomb
        if (_ySpeed > 0)
            _ySpeed = 0;
        
        CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
        if (animationManager)
            animationManager->runAnimationsForSequenceNamed("Hit");
    }
};