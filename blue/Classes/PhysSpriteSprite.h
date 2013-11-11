#ifndef blue_PhysSprite_h
#define blue_PhysSprite_h

#include <iostream>
#include "PolygonSprite.h"

#define PTM_RATIO 32

class PhysSprite : public PolygonSprite
{
public:
    
    PhysSprite();
    ~PhysSprite();
    
    static PhysSprite* spriteWithWorld(b2World *world);
    bool initWithWorld(b2World *world);

};

#endif
