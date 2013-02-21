#include "HomePageScene.h" 
#include "HelloWorldScene.h" 
#include "SharedData.h"

using namespace cocos2d;

bool HomePageScene::init(){
	if(CCScene::init()){
		 // Create a "close" menu item with close icon, it's an auto release object.
        CCMenuItemImage *pCloseItem = CCMenuItemImage::itemFromNormalImage(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(HomePageScene::menuCloseCallback));

        // Place the menu item bottom-right conner.
		 CCSize winsize = CCDirector::sharedDirector()->getWinSize();
		 pCloseItem->setPosition(ccp(30, -50));

		// Create a "restart" menu item with restart icon, it's an auto release object.
        CCMenuItemImage *pReStartItem = CCMenuItemImage::itemFromNormalImage(
            "restart.png",
            "restart.png",
            this,
			menu_selector(HomePageScene::ReStartT));

        // Place the menu item left-bottom conner.
		 pReStartItem->setPosition(ccp(30, 50));

		 // Create a "retry" menu item with start icon, it's an auto release object.
        CCMenuItemImage *pRetryItem = CCMenuItemImage::itemFromNormalImage(
            "retry.png",
            "retry.png",
            this,
            menu_selector(HomePageScene::RetryT));

        // Place the menu item left-bottom conner.
		 pRetryItem->setPosition(ccp(30, 0));

        // Create a menu with the "retry" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::menuWithItems(pReStartItem,pRetryItem,pCloseItem, NULL);
		pMenu->setPosition(ccp(120,winsize.height/2));

        // Add the menu to HelloWorld layer as a child layer.
        this->addChild(pMenu, 1);

		this->_layer = HomePageLayer::node();
		this->_layer->retain();
		this->addChild(_layer);
		return true;
	}else{
		return false;
	}
}

HomePageScene::~HomePageScene(){
	if(_layer){
		_layer->release();
		_layer = NULL;
	}
}
	
bool HomePageLayer::init(){
	if(CCLayerColor::initWithColor(ccc4(255,255,255,255))){
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		this->_label = CCLabelTTF::labelWithString("","Artial", 32);
		_label->retain();
		_label->setColor(ccc3(0, 0, 0));
		_label->setPosition(ccp(winSize.width/2, winSize.height/2));
		this->addChild(_label);

		/*
		CCLabelTTF* LScore = CCLabelTTF::labelWithString("Score", "Thonburi", 21);
		LScore->setPosition(ccp(40,300+LScore->getContentSize().height/2));
		LScore->setColor(ccc3(0, 0, 0));
		this->addChild(LScore, 1);
		
		Singleton* st = Singleton::GetInstance();
		int Score = st->getScore();
		char Score1[64];
		sprintf(Score1, "%d", Score);

		label1 = CCLabelAtlas::labelWithString("12", "fps_images2.png", 15, 21,'.');
		this->addChild(label1);
		label1->setPosition(ccp(70, 300));
		label1->setString(Score1);

		CCLabelTTF* LStar = CCLabelTTF::labelWithString("Star", "Thonburi", 21);
		LStar->setPosition(ccp(180,300+LScore->getContentSize().height/2));
		LStar->setColor(ccc3(0, 0, 0));
		this->addChild(LStar, 1);
		
		int Star = st->getStar();
		char Star1[64];
		sprintf(Star1, "%d", Star);

		label2 = CCLabelAtlas::labelWithString("12", "fps_images2.png", 15, 21,'.');
		this->addChild(label2);
		label2->setPosition(ccp(210, 300));
		label2->setString(Star1);
		*/
		//this->runAction(CCSequence::actions(CCDelayTime::actionWithDuration(3),CCCallFunc::actionWithTarget(this,callfunc_selector(GameOverLayer::gameOverDone)),NULL));
		return true;
	}else{
		return false;
	}
}

void HomePageScene::menuCloseCallback(CCObject* pSender){
	// "close" menu item clicked
    CCDirector::sharedDirector()->end();
}

HomePageLayer::~HomePageLayer(){
	if (_label){
		_label->release();
		_label = NULL;
	}
}

void HomePageLayer::gameOverDone(){
	CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}

void HomePageScene::RetryT(CCObject* pSender)
{
	Singleton* st = Singleton::GetInstance();
	st->setScore(st->getScorePre());

	CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}

void HomePageScene::ReStartT(CCObject* pSender)
{
	Singleton* st = Singleton::GetInstance();
	st->setScore(0);
	st->setScorePre(0);
	st->setStar(0);
	st->setLevel(1);
	st->setDelNum(0);
	CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}
