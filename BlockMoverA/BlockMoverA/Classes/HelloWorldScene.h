#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

class HelloWorld : public cocos2d::CCLayerColor
{
public:
	//level
	cocos2d::CCLabelAtlas *label2;
	//score
	cocos2d::CCLabelAtlas *label3;
	//star
	cocos2d::CCLabelAtlas *label4;
	//
	cocos2d::CCLabelAtlas *label5;
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    virtual void menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    LAYER_NODE_FUNC(HelloWorld);
	
	void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
	bool spriteFinished();
	void SortBlockList(cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList);
	void MoveBlockList(cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList,int Direction);
	void PrintBlockTag(cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList);
	void SetBlockTag(cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList,int level);
	
	int countLeftBlock();

protected:
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* _BlockListClick;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* _BlockList;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList1;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList2;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList3;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList4;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList5;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList6;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList7;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList8;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList9;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList10;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList11;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList12;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList13;


private:
	int getRandNum();
	cocos2d::CCSprite* getOneBlock();
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* getBlockList(int n);
	cocos2d::CCSprite* getOneBlock(int num);
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* getBlockList(int n,int row);
	void _readyBlockList();
	int BlockNum;
	void copyData(const char* pFileName);

};

#endif  // __HELLOWORLD_SCENE_H__