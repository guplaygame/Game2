#include "GameWinScene.h"
#include "HelloWorldScene.h" 
#include "SharedData.h"

using namespace cocos2d;

bool GameWinScene::init(){
	if(CCScene::init()){
		this->_layer = GameWinLayer::node();
		this->_layer->retain();
		this->addChild(_layer);
		return true;

	}else{
		return false;
	}
}

GameWinScene::~GameWinScene(){
	if(_layer){
		_layer->release();
		_layer=NULL;
	}
}

bool GameWinLayer::init(){
	if(CCLayerColor::initWithColor(ccc4(255,255,255,255))){
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		this->_label = CCLabelTTF::labelWithString("","Artial", 32);
		_label->retain();
		_label->setColor(ccc3(0, 0, 0));
		_label->setPosition(ccp(winSize.width/2, winSize.height/2));
		this->addChild(_label);

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

		this->runAction(CCSequence::actions(CCDelayTime::actionWithDuration(2),CCCallFunc::actionWithTarget(this,callfunc_selector(GameWinLayer::GameWinDone)),NULL));
		return true;
	}else{
		return false;
	}
}

GameWinLayer::~GameWinLayer(){
	if(_label){
		_label->release();
		_label=NULL;
	}
}

void GameWinLayer::GameWinDone(){
	CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}
