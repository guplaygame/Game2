#ifndef _Game_Win_Scene_H_
#define _Game_Win_Scene_H_

#include"cocos2d.h"

class GameWinLayer:public cocos2d::CCLayerColor
{
public:
	GameWinLayer():_label(NULL){};
	virtual ~GameWinLayer();
	bool init();
	
	LAYER_NODE_FUNC(GameWinLayer);

	void GameWinDone();

	CC_SYNTHESIZE_READONLY(cocos2d::CCLabelTTF*,_label,Label);
	cocos2d::CCLabelAtlas *label1;
	cocos2d::CCLabelAtlas *label2;

};

class GameWinScene:public cocos2d::CCScene{
public:
	GameWinScene():_layer(NULL){};
	~GameWinScene();
	bool init();
	
	SCENE_NODE_FUNC(GameWinScene);

	CC_SYNTHESIZE_READONLY(GameWinLayer*, _layer,Layer);
};

#endif