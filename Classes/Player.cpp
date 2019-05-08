#include "Player.h"
#include "Gun.h"
#include "Pan.h"
#include "PreloadedSprite.h"

Player::Player(Vec2 position,int ammo, float scale, Layer* scene)
{
	this->autorelease();

	scene->addChild(this);
	this->setName("Player");
	//this->setAnchorPoint(Vec2(0.5, 0));
	this->setPosition(position);
	this->setScale(scale);

	_gun = new Gun(ammo, this, scene);
	this->addChild(_gun, 3);

}


Player::~Player()
{
	//delete this;
}

void Player::setBodyPartsRotateion(float degree) {
	//_head->setRotation(degree);
	_gun->setRotation(degree);
}

void Player::shoot() {
	_gun->Shoot();
}

int Player::getAmmo() {
	return _gun->getAmmo();
}

void Player::reloadAmmo(int ammo) {
	_gun->reloadAmmo(ammo);
}

void Player::setOpacityForAll(float a) {
	_body->setOpacity(a);
	_head->setOpacity(a);
	_gun->setOpacity(a);
}