#ifndef blue_Dragon_h
#define blue_Dragon_h

#include "GameObject.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Dragon : public GameObject
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Dragon, create);
    Dragon();
    virtual bool init();
    virtual float getXTarget() {return _xTarget;};
    void setXTarget(float value){ _xTarget = value; };
    virtual float getYSpeed() {return _ySpeed;};
    void setYSpeed(float value) { _ySpeed = value; };
    virtual void update();
    virtual void handleCollisionWith(GameObject* gameObject);
private:
    float _xTarget;
    float _ySpeed;
};

class DragonLoader : public CCNodeLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(DragonLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Dragon);
    
};

#endif