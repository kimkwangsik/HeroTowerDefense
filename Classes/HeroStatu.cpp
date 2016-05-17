#include "HeroStatu.h"
#include "Menus.h"

USING_NS_CC;

Scene* HeroStatu::createScene()
{
	auto scene = Scene::create();
	auto layer = HeroStatu::create();
	scene->addChild(layer);

	return scene;
}

bool HeroStatu::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}
	clickHeroNum = 0;

	auto pScene = Menus::createScene();
	auto scenestr = new Menus("HeroStatu");
	scenestr->autorelease();
	pScene->addChild(scenestr);
	this->addChild(pScene, 10);


	VisibleWinSize = Director::getInstance()->getVisibleSize();

	auto heroSprite = Sprite::create("Images/white.png");
	heroSprite->setPosition(Vec2(0, VisibleWinSize.height / 2));
	heroSprite->setAnchorPoint(Vec2(0, 0.5));
	addChild(heroSprite);

	auto pHero1 = MenuItemImage::create(
		"Images/GameEnd/Game_btn_on.png",
		"Images/GameEnd/Game_btn_down.png",
		CC_CALLBACK_1(HeroStatu::doClick, this));
	pHero1->setPosition(Vec2(heroSprite->getContentSize().width / 3, 10));
	pHero1->setAnchorPoint(Vec2(0.5, 0));

	auto pHero2 = MenuItemImage::create(
		"Images/GameEnd/Game_btn_on.png",
		"Images/GameEnd/Game_btn_down.png",
		CC_CALLBACK_1(HeroStatu::doClick, this));
	pHero2->setPosition(Vec2(heroSprite->getContentSize().width / 3 * 2, 10));
	pHero2->setAnchorPoint(Vec2(0.5, 0));

	upgrade = LabelTTF::create("강화", "Arial", 15);
	upgrade->setPosition(Vec2(pHero2->getContentSize().width / 2,
		pHero2->getContentSize().height / 2));
	upgrade->setColor(Color3B::WHITE);
	pHero2->addChild(upgrade, 2);

	pHero1->setTag(421);
	pHero2->setTag(422);

	auto pHero = Menu::create(pHero1, pHero2, NULL);
	pHero->setPosition(Vec2::ZERO);
	heroSprite->addChild(pHero);

	mainSprite = Sprite::create("Images/Hero/Paladin/Walking/Down_1.png");
	mainSprite->setPosition(Vec2(heroSprite->getContentSize().width / 2, heroSprite->getContentSize().height));
	mainSprite->setAnchorPoint(Vec2(0.5, 1));
	mainSprite->setScale(2.5f);
	mainSprite->setVisible(false);
	heroSprite->addChild(mainSprite);


	auto heroMenuSprite = Sprite::create("Images/g43961.png");
	heroMenuSprite->setPosition(Vec2(VisibleWinSize.width, VisibleWinSize.height / 2));
	heroMenuSprite->setAnchorPoint(Vec2(1, 0.5));
	addChild(heroMenuSprite);

	pHeroItem1 = MenuItemImage::create(
		"Images/GameEnd/Game_btn_on.png",
		"Images/GameEnd/Game_btn_down.png",
		CC_CALLBACK_1(HeroStatu::doClick, this));
	pHeroItem1->setPosition(Vec2(10, heroMenuSprite->getContentSize().height - 10));
	pHeroItem1->setAnchorPoint(Vec2(0, 1));

	pHeroItem2 = MenuItemImage::create(
		"Images/GameEnd/Game_btn_on.png",
		"Images/GameEnd/Game_btn_down.png",
		CC_CALLBACK_1(HeroStatu::doClick, this));
	pHeroItem2->setPosition(Vec2(pHeroItem1->getContentSize().width+10, heroMenuSprite->getContentSize().height - 10));
	pHeroItem2->setAnchorPoint(Vec2(0, 1));

	pHeroItem1->setTag(411);
	pHeroItem2->setTag(412);

	auto pHeroMenu = Menu::create(pHeroItem1, pHeroItem2, NULL);
	pHeroMenu->setPosition(Vec2::ZERO);
	heroMenuSprite->addChild(pHeroMenu);

	return true;
}

void HeroStatu::doClick(Ref * pSender)
{
	auto tItem = (MenuItem *)pSender;
	int i = tItem->getTag();
	int gold = UserDefault::getInstance()->getIntegerForKey("have_gold");

	if (i == 411)
	{
		//mainSprite = Sprite::create("Images/Hero/Paladin/Walking/Down_1.png");
		mainSprite->setTexture("Images/Hero/Paladin/Walking/Down_1.png");
		mainSprite->setVisible(true);
		bool hero1 = UserDefault::getInstance()->getBoolForKey("Hero1");
		clickHeroNum = 1;
		if (hero1)
		{
			log("있다");
			upgrade->setString("강화");
		}
		else
		{
			log("없다");
			upgrade->setString("소환");
		}
	}
	else if (i == 412)
	{
		mainSprite->setTexture("Images/Hero/Paladin/Walking/Up_1.png");
		clickHeroNum = 2;
		bool hero2 = UserDefault::getInstance()->getBoolForKey("Hero2");
		if (hero2)
		{

		}
		else
		{

		}
	}
	else if (i == 421)
	{
		log("정보");
	}
	else if (i == 422)
	{
		if (clickHeroNum == 1)
		{
			bool hero1 = UserDefault::getInstance()->getBoolForKey("Hero1");
			if (hero1)
			{
				if (gold >= 10)
				{
					int level = UserDefault::getInstance()->getIntegerForKey("Hero1_Level");
					level++;
					gold = gold - 10;
					UserDefault::getInstance()->setIntegerForKey("Hero1_Level", level);
				}
				else
				{
					log("강화 금액 부족");
				}
			}
			else if(gold >= 100)
			{
				int level = UserDefault::getInstance()->getIntegerForKey("Hero1_Level");
				level++;
				UserDefault::getInstance()->setIntegerForKey("Hero1_Level", level);
				gold = gold - 100;
				UserDefault::getInstance()->setBoolForKey("Hero1", true);
			}
			else
			{
				log("소환 금액 부족");
			}
			UserDefault::getInstance()->setIntegerForKey("have_gold", gold);
		}
	}
}
