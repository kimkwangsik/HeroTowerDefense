#ifndef __HeroStatu_H__
#define __HeroStatu_H__

#include "cocos2d.h"

class HeroStatu : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(HeroStatu);

	bool myhero1;
	bool myhero2;
	bool myhero3;
	int clickHeroNum;

	cocos2d::LabelTTF* upgrade;

	cocos2d::Sprite* mainSprite;
	cocos2d::MenuItemImage* pHeroItem1;
	cocos2d::MenuItemImage* pHeroItem2;

	cocos2d::Size VisibleWinSize;

	void doClick(Ref* pSender);

	//virtual void onEnter();
};

#endif // __HELLOWORLD_SCENE_H__
