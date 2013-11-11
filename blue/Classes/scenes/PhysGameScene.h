#ifndef blue_PhysGameScene_h
#define blue_PhysGameScene_h

#define calculate_determinant_2x2(x1,y1,x2,y2) x1*y2-y1*x2
#define calculate_determinant_2x3(x1,y1,x2,y2,x3,y3) x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1

// When you import this file, you import all the cocos2d classes
#include "cocos2d.h"
#include "Box2D.h"
#include "GLES-Render.h"
#include "PolygonSprite.h"
#include "PhysSprite.h"
#include "SimpleAudioEngine.h"
#include "RayCastCallback.h"
//#include "scenes_manager.h"

class PhysGameScene : public CCLayer {
public:
    ~PhysGameScene();
    PhysGameScene();
    
    static CCScene* scene();
    void initPhysics();

    virtual void draw();
    void update(float dt);
    
    virtual void onEnter();
    virtual bool ccTouchBegan(CCTouch *ptouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *ptouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *ptouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *ptouch, CCEvent *pEvent);
 
    void clearSlices();
    void checkAndSliceObjects();
    
    b2Vec2* arrangeVertices(b2Vec2* vertices, int count);
    void splitPolygonSprite(PolygonSprite* sprite);
    bool areVerticesAcceptable(b2Vec2* vertices, int count);
    b2Body* createBodyWithPosition(b2Vec2 position, float rotation, b2Vec2* vertices, int32 count, float density, float friction, float restitution);
    
private:
    int m_iCount;
    void resetMotionStreak();
    void addMotionStreakPoint(CCPoint point);
    
    CCPoint _startPoint;
    CCPoint _endPoint;
    
    GLESDebugDraw *m_debugDraw;
    RaycastCallback *_raycastCallback;
    
protected:
    b2World* world;
};

#endif
