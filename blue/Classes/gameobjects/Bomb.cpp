#include "Bomb.h"
#include "Dragon.h"
#include "Explosion.h"
#include "cocos-ext.h"
#include "scenes_manager.h"

using namespace std;

Bomb::Bomb()
{
  
}

bool Bomb::init()
{
  if (!GameObject::init()) {
    return false;
  }
  _radius = 15;
  return true;
}

void Bomb::handleCollisionWith(GameObject* gameObject)
{
  Dragon *object = dynamic_cast<Dragon*>(gameObject);
  if (object) {
    // Collided with the dragon, remove object and add an exposion instead
    this->setScheduledForRemove(true);
    CCNode* explosion = loadExplosion();
    explosion->setPosition(this->getPosition());
    this->getParent()->addChild(explosion);
  }
}

