#include "Lava.h"
#include "AudioEngine.h"
#include "PointPlusFX.h"
#include "FX.h"
#include "Bullet.h"
#include "EnemyExplosion.h"

Lava::Lava(Vec2 position, float scale,int tag, Layer* parent)
{
	this->autorelease();

	// Start :: Init
	_tag = tag;
	//this->initWithFile("items/Lava.png");
	this->setPosition(position);
	this->setName("Lava" + to_string(_tag));
	parent->addChild(this, 0);
	// End :: Init

	auto colissionListener = EventListenerPhysicsContact::create();
	colissionListener->onContactBegin = CC_CALLBACK_1(Lava::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(colissionListener, this);
}


Lava::~Lava()
{
	//delete this;
}

int Lava::getEnemyTag() {
	return this->_tag;
}
