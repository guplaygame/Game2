#ifndef _GAME_OVER_SCENE_H_
#define _GAME_OVER_SCENE_H_

#include"cocos2d.h"

class GameOverLayer:public cocos2d::CCLayerColor
{
public:
	GameOverLayer():_label(NULL){};
	virtual ~GameOverLayer();
	bool init();
	
	LAYER_NODE_FUNC(GameOverLayer);
	
	void gameOverDone();

	CC_SYNTHESIZE_READONLY(cocos2d::CCLabelTTF*,_label,Label);
	cocos2d::CCLabelAtlas *label1;
	cocos2d::CCLabelAtlas *label2;
};

class GameOverScene:public cocos2d::CCScene{
public:
	GameOverScene():_layer(NULL) {};
	~GameOverScene();
	bool init();

	SCENE_NODE_FUNC(GameOverScene);
	
	CC_SYNTHESIZE_READONLY(GameOverLayer*, _layer,Layer);
	void RetryT(CCObject* pSender);
	void ReStartT(CCObject* pSender);
	void menuCloseCallback(CCObject* pSender);
};

#endif