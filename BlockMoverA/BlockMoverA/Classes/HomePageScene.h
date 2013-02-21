#ifndef __HomePage_SCENE_H__
#define __HomePage_SCENE_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

class HomePageLayer:public cocos2d::CCLayerColor
{
public:
	HomePageLayer():_label(NULL){};
	virtual ~HomePageLayer();
	bool init();
	
	LAYER_NODE_FUNC(HomePageLayer);
	
	void gameOverDone();

	CC_SYNTHESIZE_READONLY(cocos2d::CCLabelTTF*,_label,Label);
	cocos2d::CCLabelAtlas *label1;
	cocos2d::CCLabelAtlas *label2;
};

class HomePageScene:public cocos2d::CCScene{
public:
	HomePageScene():_layer(NULL) {};
	~HomePageScene();
	bool init();
	 virtual void menuCloseCallback(CCObject* pSender);

	SCENE_NODE_FUNC(HomePageScene);
	
	CC_SYNTHESIZE_READONLY(HomePageLayer*, _layer,Layer);
	void RetryT(CCObject* pSender);
	void ReStartT(CCObject* pSender);
};

#endif