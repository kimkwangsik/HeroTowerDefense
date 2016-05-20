﻿#ifndef __Hero_H__
#define __Hero_H__

#include "cocos2d.h"
#include "Monster.h"


class Hero : public cocos2d::Sprite
{
public:
	Hero(int typenum);

	cocos2d::Size heroContentSize;

	void setPriorityWithThis(bool usdNodePriority);
	void setpMonster(cocos2d::Vector<Monster*> *_repMonster);

	char name[10];

	virtual void onEnter();
	virtual void onExit();

	void setHeroSetting();

	void heroTick(float a);
	cocos2d::Vec2 minDis;
	cocos2d::Vec2 absMaxDis;
	cocos2d::Vector<Monster*> *_pMonster;
	Monster* nearMonster;
	bool near1;
	float _attackPower;
	
	void setpGold(int* _pnowStageGold);
	void setpMasicGauge(int * _pmasicGauge);
	int *nowStageGold;
	int *nowMasicGauge;


	//int towerUpgradeLevel;
	//cocos2d::Sprite* b_Yes;
	//cocos2d::Sprite* b_No;
	//cocos2d::Sprite* b_Upgrade;
	//int	cost;
	//bool towerSetup;
	//bool towerMenuVisible;
	//bool towerUpgradeVisible;
	//cocos2d::EventListener* _listenter;
	//cocos2d::Label* levelView;

private:
	int _fixedPriority;
	bool _useNodePriority;
	int _heroType;
	bool _setupBegan;
	float _attackDelay;
};

#endif //defined(__SpriteExtendEx__Monster__)//