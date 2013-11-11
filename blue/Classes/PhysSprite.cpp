#include "PhysSprite.h"

using namespace cocos2d;

PhysSprite::PhysSprite() {
   
}
PhysSprite::~PhysSprite() {
    
}

PhysSprite* PhysSprite::spriteWithWorld(b2World *world)
{
    PhysSprite *pobPhysSprite = new PhysSprite();
    if (pobPhysSprite && pobPhysSprite->initWithWorld(world))
    {
        pobPhysSprite->autorelease();
        return pobPhysSprite;
    }
    CC_SAFE_DELETE(pobPhysSprite);
    return NULL;
}

bool PhysSprite::initWithWorld(b2World *world)
{
    string name = "gift";

    CCSize screen = CCDirector::sharedDirector()->getWinSize();
    
    b2Body *body = createBodyForWorld(world, b2Vec2(screen.width/2/PTM_RATIO, 0), 0, 5.0, 0.2, 0.2, name);
    
    PolygonSprite::initWithFile(name + ".png", body, true);
//    body->ApplyLinearImpulse(150.0f*b2Vec2(0, 1.6f), body->GetPosition());
    CCLOG("on create pre calc (%f,%f)", screen.width/2, screen.height/2);
    CCLOG("on create (%f,%f)", body->GetPosition().x*PTM_RATIO, body->GetPosition().y*PTM_RATIO);
    return true;
}
