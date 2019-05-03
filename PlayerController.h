#include "BWTP_Func.h"

class Player;

USING_NS_CC;

#pragma once
class PlayerController : public Sprite
{
public:
	PlayerController(Node* parent);
	~PlayerController();


	void setPlayer(Player* player);
	void setTutorial(bool isTutorial);
	void setEnableTrajectory(bool isEnable);
	void hint(float angle);

private:
	Player* _player;
	DrawNode* _aim;
	DrawNode* _trajectory;
	Sprite* _cancelShot;
	Node* _fakeBullet;
	Vec2 previousDot;

	bool _isTutorial;
	int _maxDots;
	int _dots;
	float _currentDegree;
	bool _isTrajectory;
	

	void simulateTrajectory();

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

	void update(float dt) override;
};

