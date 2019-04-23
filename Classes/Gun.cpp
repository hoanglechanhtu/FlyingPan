#include "Gun.h"
#include "FX.h"
#include "Bullet.h"
#include "Ammo.h"

Gun::Gun(int ammo, Node* player, Layer* scene)
{
	this->autorelease();

	_timeToCount = _timeToSetRotation;

	this->initWithSpriteFrame(getSprite("Canon_Gun_01.png"));
	this->setPosition(player->getContentSize()/2);
	this->setAnchorPoint(Vec2(0.3, 0.5));

	_shootingPoint = Sprite::create("player/bullet/ShootingPoint.png");
	_shootingPoint->setOpacity(0);
	_shootingPoint->setPosition(Vec2(this->getContentSize().width * 0.8, this->getContentSize().height * 0.65));
	this->addChild(_shootingPoint);


	_shootingPoint2 = Sprite::create("player/bullet/ShootingPoint.png");
	_shootingPoint2->setOpacity(0);
	_shootingPoint2->setPosition(_shootingPoint->getPosition() + Vec2(20000.0f, 0.0f));
	this->addChild(_shootingPoint2);

	_ammo = new Ammo(ammo);
	scene->addChild(_ammo);

	_scene = scene;
	this->scheduleUpdate();

	
}

void Gun::update(float dt) {
	float rotation = this->getRotation();
	
	_timeToCount -= dt;
	if (rotation != _currentRotation) {
		if (_timeToCount < 0) {
			_currentRotation = rotation;
			_timeToCount = _timeToSetRotation;
		}
	}
	else {
		_timeToCount = _timeToSetRotation;
	}
}

Gun::~Gun()
{
	//delete this;
}

void Gun::Shoot() {
	
}

void Gun::checkOutOfBullets() {
	//if (_ammo->getAmmo() < 1) {
	//	_bulletDisplayment->removeFromParentAndCleanup(1);
	//}
}

int Gun::getAmmo() {
	return _ammo->getAmmo();
}

void Gun::reloadAmmo(int ammo) {
	_ammo->reloadAmmo(ammo);
}

//void Gun::setRotation(float rotation) {
//	_currentRotation = rotation;
//}