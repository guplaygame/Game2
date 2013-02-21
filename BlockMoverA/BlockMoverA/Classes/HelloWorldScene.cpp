#include "HelloWorldScene.h"
#include "SharedData.h"
#include "GameOverScene.h"
#include "GameWinScene.h"
#include "HomePageScene.h"

using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::node();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::node();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
		if(!CCLayerColor::initWithColor(ccc4(255,255,255,255)))
		{
			return false;
		}
		
        // 1. Add a menu item with "X" image, which is clicked to quit the program.

        // Create a "close" menu item with close icon, it's an auto release object.
        CCMenuItemImage *pCloseItem = CCMenuItemImage::itemFromNormalImage(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(HelloWorld::menuCloseCallback));
        CC_BREAK_IF(! pCloseItem);

        // Place the menu item bottom-right conner.
		 CCSize winsize = CCDirector::sharedDirector()->getWinSize();
		 pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, winsize.height-20));

        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::menuWithItems(pCloseItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        // Add the menu to HelloWorld layer as a child layer.
        this->addChild(pMenu, 1);

        // 2. Add a label shows "Hello World".

        // Create a label and initialize with string "Hello World".
        CCLabelTTF* pLabel = CCLabelTTF::labelWithString("Bloke Mover", "Thonburi", 21);
        CC_BREAK_IF(! pLabel);

        // Get window size and place the label upper. 
       
		pLabel->setPosition(ccp(winsize.width-pLabel->getContentSize().width/2-pCloseItem->getContentSize().width, winsize.height-pLabel->getContentSize().height/2));
        this->addChild(pLabel, 1);

        // 3. Add add a splash screen, show the cocos2d splash image.
       // CCSprite* pSprite = CCSprite::spriteWithFile("HelloWorld.png");
       // CC_BREAK_IF(! pSprite);

        // Place the sprite on the center of the screen
        // pSprite->setPosition(ccp(winsize.width/2, winsize.height/2));

        // Add the sprite to HelloWorld layer as a child layer.
        //this->addChild(pSprite, 0);
		BlockNum=0;

		copyData("DataTotal.txt");

		_BlockListClick = new CCMutableArray<CCSprite*>;
		_BlockList = new CCMutableArray<CCSprite*>;
		BlockList1 = new CCMutableArray<CCSprite*>;
		BlockList2 = new CCMutableArray<CCSprite*>;
		BlockList3 = new CCMutableArray<CCSprite*>;
		BlockList4 = new CCMutableArray<CCSprite*>;
		BlockList5 = new CCMutableArray<CCSprite*>;
		BlockList6 = new CCMutableArray<CCSprite*>;
		BlockList7 = new CCMutableArray<CCSprite*>;
		BlockList8 = new CCMutableArray<CCSprite*>;
		BlockList9 = new CCMutableArray<CCSprite*>;
		BlockList10 = new CCMutableArray<CCSprite*>;
		BlockList11 = new CCMutableArray<CCSprite*>;
		BlockList12 = new CCMutableArray<CCSprite*>;
		BlockList13 = new CCMutableArray<CCSprite*>;
		
		///*
		int number=getRandNum();

		BlockList1 = getBlockList(0,number);
		BlockList2 = getBlockList(1,number);
		BlockList3 = getBlockList(2,number);
		BlockList4 = getBlockList(3,number);
		BlockList5 = getBlockList(4,number);
		BlockList6 = getBlockList(5,number);
		BlockList7 = getBlockList(6,number);
		BlockList8 = getBlockList(7,number);
		BlockList9 = getBlockList(8,number);
		BlockList10 = getBlockList(9,number);
		//BlockList11 = getBlockList(10,number);
		//BlockList12 = getBlockList(11,number);
		//BlockList13 = getBlockList(12,number);
		//*/

		/*
		BlockList1 = getBlockList(0);
		BlockList2 = getBlockList(1);
		BlockList3 = getBlockList(2);
		BlockList4 = getBlockList(3);
		BlockList5 = getBlockList(4);
		BlockList6 = getBlockList(5);
		BlockList7 = getBlockList(6);
		BlockList8 = getBlockList(7);
		BlockList9 = getBlockList(8);
		BlockList10 = getBlockList(9);
		BlockList11 = getBlockList(10);
		BlockList12 = getBlockList(11);
		BlockList13 = getBlockList(12);
		//*/
		_readyBlockList();

		this->setIsTouchEnabled(true);
		
		CCLabelTTF* pLabel2 = CCLabelTTF::labelWithString("Level", "Thonburi", 21);
		pLabel2->setPosition(ccp(40,400+pLabel2->getContentSize().height/2));
		pLabel2->setColor(ccc3(0, 0, 0));
		this->addChild(pLabel2, 1);

		CCLabelTTF* pLabel3 = CCLabelTTF::labelWithString("Score", "Thonburi", 21);
		pLabel3->setPosition(ccp(135,400+pLabel3->getContentSize().height/2));
		pLabel3->setColor(ccc3(0, 0, 0));
		this->addChild(pLabel3, 1);

		Singleton* st = Singleton::GetInstance();
		st->setScorePre(st->getScore());
		int level = st->getLevel();
		char level1[8];
		sprintf(level1, "%d", level);

		label2 = CCLabelAtlas::labelWithString("12", "fps_images2.png", 15, 21,'.');
		this->addChild(label2);
		label2->setPosition(ccp(70, 400));
		label2->setString(level1);

		int score = st->getScore();
		char score1[16];
		sprintf(score1, "%d", score);

		label3 = CCLabelAtlas::labelWithString("12", "fps_images2.png", 15, 21,'.');
		this->addChild(label3);
		label3->setPosition(ccp(165, 400));
		label3->setString(score1);
		
		/*
		CCLabelTTF* pLabel4 = CCLabelTTF::labelWithString("Star", "Thonburi", 21);
		pLabel4->setPosition(ccp(55,350+pLabel4->getContentSize().height/2));
		pLabel4->setColor(ccc3(0, 0, 0));
		this->addChild(pLabel4, 1);

		int star = st->getStar();
		char star1[4];
		sprintf(star1, "%d", star);

		label4 = CCLabelAtlas::labelWithString("12", "fps_images2.png", 15, 21,'.');
		this->addChild(label4);
		label4->setPosition(ccp(80, 350));
		label4->setString(star1);
		//*/

		//PrintBlockTag(_BlockList);
		//SetBlockTag(_BlockList,number);

		//const char *filepath = CCFileUtils::fullPathFromRelativePath("DataTotal.txt");
		/*
		const char *pFileName="DataTotal.txt";   
		string strPath = CCFileUtils::fullPathFromRelativePath(pFileName);
		unsigned long len = 0;
		unsigned char *data = NULL;

		data = CCFileUtils::getFileData(strPath.c_str(),"r",&len);
		string destPath = CCFileUtils::getWriteablePath();
		destPath += pFileName;
		FILE *fp = fopen(destPath.c_str(),"w+");
		CC_BREAK_IF(!fp);
		unsigned long size = ftell(fp);
		fseek(fp,0,SEEK_SET);
		unsigned char * pData = new unsigned char[size];
		size = fread(pData,sizeof(unsigned char), size,fp);

		fwrite(data,sizeof(char),len,fp);    
		fclose(fp); 
		delete []data;    
		data = NULL;
		//*/

		/*
		//读取的字节数，读取失败则为0
		unsigned long len = 0;
		//读取的内容
		unsigned char *data = CCFileUtils::getFileData(filepath, "r", &len);
		const char *filepath1=(const char*)data;
		CCLog(filepath1);
		//记得释放内存
		if(len >0 && data) 
			delete[] data;
		//*/
		/*

		char buf[160];
		FILE* m_pFile = fopen(filepath,"r");
		int i=0;
		while(fgets(buf,sizeof(buf),m_pFile)){
			for(;i<level;i++){
				CCLog(buf);
			}
		}
		
		char ch = getc(m_pFile);
		
		char* ch1="sq";
		string s(ch1);
		char Num[2]={0};
		Num[0]=ch;
		CCLog(Num);
		while(ch != EOF&&ch!= 255){
			ch=getc(m_pFile);
			Num[0]=ch;
			CCLog(Num);
		}
		
		fclose(m_pFile);
		CCLog(filepath);

		//*/
		
        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
	CCTouch* touch = (CCTouch*)(touches->anyObject());
	CCPoint location = touch->locationInView(touch->view());
	location = CCDirector::sharedDirector()->convertToGL(location);

	float locationX = location.x;
	float locationY = location.y;
	CCSprite* BlockTemp = getOneBlock();
	BlockTemp->setPosition(location);
	CCMutableArray<CCSprite*>::CCMutableArrayIterator it,jt;
	CCMutableArray<CCSprite*>* _runBlockList = new CCMutableArray<CCSprite*>;
	CCMutableArray<CCSprite*>* _delBlockList = new CCMutableArray<CCSprite*>;

	CCSize winsize = CCDirector::sharedDirector()->getWinSize();
	if(locationY-BlockTemp->getContentSize().height*12>0){
		this->removeChild(BlockTemp,true);
		return;
	}
	if(locationX<4 || locationX>=winsize.width-4){
		this->removeChild(BlockTemp,true);
		return;
	}
	CCSprite* winSprite;
	for(it=_BlockList->begin();it!=_BlockList->end();it++){
		winSprite = *it;
		if((winSprite->getPosition().y-locationY>=0&&winSprite->getPosition().y-locationY<winSprite->getContentSize().width/2)||
			(locationY-winSprite->getPosition().y>0&&locationY-winSprite->getPosition().y<=winSprite->getContentSize().width/2)){
			if(winSprite->getPosition().x-locationX>=0&&winSprite->getPosition().x-locationX<=winSprite->getContentSize().width/2){
				_runBlockList->addObject(winSprite);
				break;
			}else if(locationX-winSprite->getPosition().x>0&&locationX-winSprite->getPosition().x<winSprite->getContentSize().width/2){
				_runBlockList->addObject(winSprite);
				break;
			}
		}
	}

	this->removeChild(BlockTemp,true);
	if(_runBlockList->count()<1){
		return;
	}
	CCSprite* runBlockListTemp,*BlockListTemp;
	float runBlockListTempX,runBlockListTempY,BlockListTempX,BlockListTempY;

	int numA = 0;
	do{
		numA=_runBlockList->count();
		for(jt=_BlockList->begin();jt!=_BlockList->end();jt++){
			BlockListTemp = *jt;
			if(_runBlockList->containsObject(BlockListTemp)){
				continue;
			}

			BlockListTempX = BlockListTemp->getPosition().x;
			BlockListTempY = BlockListTemp->getPosition().y;
			int numB=0;
			for(it=_runBlockList->begin();it!=_runBlockList->end();it++){
				runBlockListTemp = *it;
				runBlockListTempX = runBlockListTemp->getPosition().x;
				runBlockListTempY = runBlockListTemp->getPosition().y;
			
				float lenth=0;
				if(BlockListTemp->getTag()==runBlockListTemp->getTag()){
					if(runBlockListTempX==BlockListTempX){
						lenth = runBlockListTempY-BlockListTempY;
					}else if(runBlockListTempY==BlockListTempY){
						lenth = runBlockListTempX-BlockListTempX;
					}
					if(lenth<0){
						lenth=0-lenth;
					}
				}
					
				if(lenth>0&&lenth<=runBlockListTemp->getContentSize().width){
					numB=1;
					break;
				}
			}
			if(numB==1){
				_runBlockList->addObject(BlockListTemp);	
			}
		}
	}while((int)_runBlockList->count()>numA);
	
	this->removeChild(label5,true);
	if(_runBlockList->count()>1){
		int NumClick = _runBlockList->count();
		int ClickScore = NumClick*NumClick*5;
		char scoreClick[16];
		sprintf(scoreClick, "%d", ClickScore);

		label5 = CCLabelAtlas::labelWithString("12", "fps_images2.png", 15, 21,'.');
		this->addChild(label5);
		label5->setPosition(location);
		label5->setString(scoreClick);
	}

	if(_runBlockList->count()>2)
	{	
		CCSprite* BlockClick;
		if(_BlockListClick->count()>0){
			for(it=_runBlockList->begin();it!=_runBlockList->end();it++){
				BlockClick=*it;
				if(!_BlockListClick->containsObject(BlockClick)){
					_BlockListClick->removeAllObjects();
					for(jt=_runBlockList->begin();jt!=_runBlockList->end();jt++){
						BlockClick=*jt;
						_BlockListClick->addObject(BlockClick);
					}
					return;
				}
			}
		}else{
			for(it=_runBlockList->begin();it!=_runBlockList->end();it++){
				BlockClick=*it;
				_BlockListClick->addObject(BlockClick);
			}
			return;
		}
	}
	
	if(_runBlockList->count()>2){
		this->removeChild(label5,true);
		Singleton* st1 = Singleton::GetInstance();
		int score = st1->getScore();
		score=score+5*_runBlockList->count()*_runBlockList->count();
		st1->setScore(score);
		char score1[64]={0};
		sprintf(score1, "%d", st1->getScore());
		label3->setString(score1);
		
		for(it=_runBlockList->begin();it!=_runBlockList->end();it++){
			if(_BlockList->containsObject(*it)){
				_BlockList->removeObject(*it);
			}
			this->removeChild(*it,true);
		}

	/*
		CCSpriteFrameCache* frameCache =CCSpriteFrameCache::sharedSpriteFrameCache();
		CCMutableArray<CCSpriteFrame*>* animFrames = new CCMutableArray<CCSpriteFrame*>(4);
		char str[32]={0};
		for(int i=1;i<=4;i++){
			sprintf_s(str,"green%d.png",i);
			CCSpriteFrame* frame = frameCache->spriteFrameByName(str);
			animFrames->addObject(frame);
		}
		CCAnimation* animation = CCAnimation::animationWithFrames(animFrames,1.2f);
		CCActionInterval* action = CCAnimate::actionWithAnimation(animation,true);
		CCFiniteTimeAction* runAction = CCSequence::actions(action,NULL);
		
		runAction->retain();
		animFrames->release();
	*/
	/*
		CCSpriteFrameCache*  frameCache1 = CCSpriteFrameCache::sharedSpriteFrameCache();
		char strPlist[64] = {0};  
		char strPng[64] = {0}; 
		sprintf_s(strPlist,"red.plist");
		sprintf_s(strPng,"red.png");  
		frameCache1->addSpriteFramesWithFile(strPlist, strPng);


		CCMutableArray<CCSpriteFrame*>* animFrames1 = new CCMutableArray<CCSpriteFrame*>(4);  
  
		char str1[64] = {0};  
		for(int i = 1; i <= 4; i++)   
		{  
			sprintf_s(str1, "red%d.png", i);  
			CCSpriteFrame* frame = frameCache1->spriteFrameByName( str1 );  
			animFrames1->addObject(frame);  
		}  
  
		CCAnimation* animation1 = CCAnimation::animationWithFrames(animFrames,0.04f);  
  
		CCRepeatForever* mFly=CCRepeatForever::actionWithAction( CCAnimate::actionWithAnimation(animation1, false));  
		animFrames1->release();  
		frameCache1->removeSpriteFramesFromFile(strPlist);  

	*/

		for(it=_runBlockList->begin();it!=_runBlockList->end();it++){

			if(BlockList1!=NULL&&BlockList1->containsObject(*it)){
				BlockList1->removeObject(*it);
				SortBlockList(BlockList1);
				if(BlockList1->count()<1){
					BlockList1=NULL;
				}
				continue;
			}
			if(BlockList2!=NULL&&BlockList2->containsObject(*it)){
				BlockList2->removeObject(*it);
				SortBlockList(BlockList2);
				if(BlockList2->count()<1){
					MoveBlockList(BlockList1,1);

					BlockList2=NULL;
				}
				continue;
			}
			if(BlockList3!=NULL&&BlockList3->containsObject(*it)){
				BlockList3->removeObject(*it);
				SortBlockList(BlockList3);
				if(BlockList3->count()<1){
					MoveBlockList(BlockList2,1);
					MoveBlockList(BlockList1,1);
						
					BlockList3=NULL;
				}
				continue;
			}
			if(BlockList4!=NULL&&BlockList4->containsObject(*it)){
				BlockList4->removeObject(*it);
				SortBlockList(BlockList4);
				if(BlockList4->count()<1){
					MoveBlockList(BlockList3,1);
					MoveBlockList(BlockList2,1);
					MoveBlockList(BlockList1,1);
						
					BlockList4=NULL;
				}
				continue;
			}
			if(BlockList5!=NULL&&BlockList5->containsObject(*it)){
				BlockList5->removeObject(*it);
				SortBlockList(BlockList5);
				if(BlockList5->count()<1){
					MoveBlockList(BlockList4,1);
					MoveBlockList(BlockList3,1);
					MoveBlockList(BlockList2,1);
					MoveBlockList(BlockList1,1);
						
					BlockList5=NULL;
				}
				continue;
			}
			if(BlockList6!=NULL&&BlockList6->containsObject(*it)){
				BlockList6->removeObject(*it);
				SortBlockList(BlockList6);
				if(BlockList6->count()<1){
					MoveBlockList(BlockList7,-1);
					MoveBlockList(BlockList8,-1);
					MoveBlockList(BlockList9,-1);
					MoveBlockList(BlockList10,-1);
						
					BlockList6=NULL;
				}
				continue;
			}
			if(BlockList7!=NULL){
				if(BlockList7->containsObject(*it)){
					BlockList7->removeObject(*it);
					SortBlockList(BlockList7);
					if(BlockList7->count()<1){
						MoveBlockList(BlockList8,-1);
						MoveBlockList(BlockList9,-1);
						MoveBlockList(BlockList10,-1);

						BlockList7=NULL;
					}
					continue;
				}
			}
			if(BlockList8!=NULL&&BlockList8->containsObject(*it)){
				BlockList8->removeObject(*it);
				SortBlockList(BlockList8);
				if(BlockList8->count()<1){
					MoveBlockList(BlockList9,-1);
					MoveBlockList(BlockList10,-1);
					MoveBlockList(BlockList11,-1);
					MoveBlockList(BlockList12,-1);
					MoveBlockList(BlockList13,-1);
					
					BlockList8=NULL;
				}
				continue;
			}
			if(BlockList9!=NULL&&BlockList9->containsObject(*it)){
				BlockList9->removeObject(*it);
				SortBlockList(BlockList9);
				if(BlockList9->count()<1){
					MoveBlockList(BlockList10,-1);
					MoveBlockList(BlockList11,-1);
					MoveBlockList(BlockList12,-1);
					MoveBlockList(BlockList13,-1);
					
					BlockList9=NULL;
				}
				continue;
			}
			if(BlockList10!=NULL&&BlockList10->containsObject(*it)){
				BlockList10->removeObject(*it);
				SortBlockList(BlockList10);
				if(BlockList10->count()<1){
					MoveBlockList(BlockList11,-1);
					MoveBlockList(BlockList12,-1);
					MoveBlockList(BlockList13,-1);
					
					BlockList10=NULL;
				}
				continue;
			}
			if(BlockList11!=NULL&&BlockList11->containsObject(*it)){
				BlockList11->removeObject(*it);
				SortBlockList(BlockList11);
				if(BlockList11->count()<1){
					MoveBlockList(BlockList12,-1);
					MoveBlockList(BlockList13,-1);
					
					BlockList11=NULL;
				}
				continue;
			}
			if(BlockList12!=NULL&&BlockList12->containsObject(*it)){
				BlockList12->removeObject(*it);
				SortBlockList(BlockList12);
				if(BlockList12->count()<1){
					MoveBlockList(BlockList13,-1);

					BlockList12=NULL;
				}
				continue;
			}
			if(BlockList13!=NULL&&BlockList13->containsObject(*it)){
				BlockList13->removeObject(*it);
				SortBlockList(BlockList13);
				if(BlockList13->count()<1){
					BlockList13=NULL;
				}
				continue;
			}
		}
	}
	
	_runBlockList=NULL;
	bool bool1 = spriteFinished();
	
	if(bool1){
		Singleton* st2= Singleton::GetInstance();
		int level = st2->getLevel();
		int DelNum = st2->getDelNum();
		int count=_BlockList->count();
		int nums =count+DelNum-156;

		if(nums<4){
			st2->setStar(5);
		}else if(nums<7){
			st2->setStar(4);
		}else if(nums<10){
			st2->setStar(3);
		}else if(nums<13){
			st2->setStar(2);
		}else if(nums<16){
			st2->setStar(1);
		}else{
			st2->setStar(0);
		}

		if(count<2||(level<16&&count<18-level)){
			level=level+1;
			st2->setLevel(level);
			GameWinScene * GameWinScene = GameWinScene::node();
			GameWinScene->getLayer()->getLabel()->setString("You Win!");
			CCDirector::sharedDirector()->replaceScene(GameWinScene); 
		}else{
			GameOverScene *gameOverScene = GameOverScene::node();
			gameOverScene->getLayer()->getLabel()->setString("You Lose!");
			CCDirector::sharedDirector()->replaceScene(gameOverScene); 
		}
		
		/*
		CCScene *newLevel = HelloWorld::scene();
		CCDirector::sharedDirector()->replaceScene(newLevel);
		//*/
	}
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
	CCDirector::sharedDirector()->replaceScene(HomePageScene::node());
}
bool HelloWorld::spriteFinished(){
	CCMutableArray<CCSprite*>::CCMutableArrayIterator it,jt,lt;
	CCSprite* tempSprite1,*tempSprite2,*tempSprite3;
	float tempSprite2X,tempSprite2Y,tempSprite3X,tempSprite3Y;
	for(it=_BlockList->begin();it!=_BlockList->end();it++){
		tempSprite1=*it;
		CCMutableArray<CCSprite*>* tempArr = new CCMutableArray<CCSprite*>;
		tempArr->addObject(tempSprite1);
		int num=0;
		do{
			num=tempArr->count();
			for(jt=_BlockList->begin();jt!=_BlockList->end();jt++){
				tempSprite2=*jt;
				if(tempArr->containsObject(tempSprite2)){
					continue;
				}
				tempSprite2X = tempSprite2->getPosition().x;
				tempSprite2Y = tempSprite2->getPosition().y;
				int num1=0;
				for(lt=tempArr->begin();lt!=tempArr->end();lt++){
					tempSprite3=*lt;
					tempSprite3X = tempSprite3->getPosition().x;
					tempSprite3Y = tempSprite3->getPosition().y;
					float lenth=0;
					if(tempSprite2->getTag()==tempSprite3->getTag()){
						if(tempSprite2X==tempSprite3X){
							lenth = tempSprite3Y-tempSprite2Y;
						}else if(tempSprite3Y==tempSprite2Y){
							lenth = tempSprite3X-tempSprite2X;
						}
						if(lenth<0){
							lenth=0-lenth;
						}
						if(lenth>0&&lenth<=tempSprite3->getContentSize().width){
							num1=1;
							break;
						}
					}
				}
				if(num1==1){
					tempArr->addObject(tempSprite2);	
				}
			}
			if(tempArr->count()>2){
				return false;
			}
		}while(((int)tempArr->count())>num);
		
		tempArr=NULL;
	}
	return true;
}

//initialize _BlockList
void HelloWorld::_readyBlockList()
{
	CCSprite* TempBlock;
	CCMutableArray<CCSprite*>::CCMutableArrayIterator it;
	for(it=BlockList1->begin();it!=BlockList1->end();it++){
		TempBlock=*it;
		_BlockList->addObject(TempBlock);
	}
	for(it=BlockList2->begin();it!=BlockList2->end();it++){
		TempBlock=*it;
		_BlockList->addObject(TempBlock);
	}
	for(it=BlockList3->begin();it!=BlockList3->end();it++){
		TempBlock=*it;
		_BlockList->addObject(TempBlock);
	}
	for(it=BlockList4->begin();it!=BlockList4->end();it++){
		TempBlock=*it;
		_BlockList->addObject(TempBlock);
	}
	for(it=BlockList5->begin();it!=BlockList5->end();it++){
		TempBlock=*it;
		_BlockList->addObject(TempBlock);
	}
	for(it=BlockList6->begin();it!=BlockList6->end();it++){
		TempBlock=*it;
		_BlockList->addObject(TempBlock);
	}
	for(it=BlockList7->begin();it!=BlockList7->end();it++){
		TempBlock=*it;
		_BlockList->addObject(TempBlock);
	}
	for(it=BlockList8->begin();it!=BlockList8->end();it++){
		TempBlock=*it;
		_BlockList->addObject(TempBlock);
	}
	for(it=BlockList9->begin();it!=BlockList9->end();it++){
		TempBlock=*it;
		_BlockList->addObject(TempBlock);
	}
	for(it=BlockList10->begin();it!=BlockList10->end();it++){
		TempBlock=*it;
		_BlockList->addObject(TempBlock);
	}
	for(it=BlockList11->begin();it!=BlockList11->end();it++){
		TempBlock=*it;
		_BlockList->addObject(TempBlock);
	}
	for(it=BlockList12->begin();it!=BlockList12->end();it++){
		TempBlock=*it;
		_BlockList->addObject(TempBlock);
	}
	for(it=BlockList13->begin();it!=BlockList13->end();it++){
		TempBlock=*it;
		_BlockList->addObject(TempBlock);
	}
}
void HelloWorld::copyData(const char* pFileName){
	string strPath = CCFileUtils::fullPathFromRelativePath(pFileName);
	unsigned long len = 0;
	unsigned char *data = NULL;
	data = CCFileUtils::getFileData(strPath.c_str(),"r",&len);
	string destPath = CCFileUtils::getWriteablePath();
	destPath += pFileName;
	FILE *fp = fopen(destPath.c_str(),"w+");
	fwrite(data,sizeof(char),len,fp);
	fclose(fp);
	delete []data;
	data = NULL;
}
//set a list's Tags
void HelloWorld::SetBlockTag(CCMutableArray<CCSprite*>* BlockList,int level){
	const char *filepath = CCFileUtils::fullPathFromRelativePath("DataTotal.txt");
	char buf[160];
	FILE* m_pFile = fopen(filepath,"r");
	int i=1;
	while(fgets(buf,sizeof(buf),m_pFile)){
		if(level==i){
			break;
		}
		i=i+1;
	}
	CCSprite* Block;
	CCMutableArray<CCSprite*>::CCMutableArrayIterator it;
	int j=0;
	for(it=BlockList->begin();it!=BlockList->end();it++){
		Block=*it;
		Block->setTag(buf[j]);
		j=j+1;
	}
}

//print a list's Tags
void HelloWorld::PrintBlockTag(CCMutableArray<CCSprite*>* BlockList){
	CCSprite* Block;
	CCMutableArray<CCSprite*>::CCMutableArrayIterator it;
	int i=0;
	char BlockTagArr[158]={0};
	for(it=BlockList->begin();it!=BlockList->end();it++){
		Block=*it;
		BlockTagArr[i] = Block->getTag()+'0';
		i=i+1;
	}
	BlockTagArr[156]=10;

	const char *pFileName="DataTotal.txt";
	string destPath = CCFileUtils::getWriteablePath();
	destPath += pFileName;
	unsigned long len = 0;
	unsigned char *data = NULL;
	data = (unsigned char *)BlockTagArr;
	len = strlen((const char *)data);
	
	FILE *fp = fopen(destPath.c_str(),"a+");
	fwrite(data,sizeof(char),len,fp);    
	fclose(fp);
	
}
//Get a list of Block
CCMutableArray<CCSprite*>* HelloWorld::getBlockList(int n,int row)
{
	CCSprite* Block,* BlockTemp;
	CCMutableArray<CCSprite*>* BlockList = new CCMutableArray<CCSprite*>;
	CCMutableArray<CCSprite*>::CCMutableArrayIterator it;
	const char *filepath = CCFileUtils::fullPathFromRelativePath("DataTotal.txt");
	char buf[170]={0};
	for(int i=0;i<170;i++){
		buf[i]=49;
	}
	string strFilePath = CCFileUtils::getWriteablePath();
	strFilePath = strFilePath+"DataTotal.txt";
	//CCLog(strFilePath.c_str());
	FILE* m_pFile = fopen(strFilePath.c_str(),"r");
	if(m_pFile){
		int k=1;
		char buf1[170]={0};
		fgets(buf,sizeof(buf),m_pFile);
		while(k<row){
			fgets(buf,sizeof(buf),m_pFile);
			k=k+1;
		}
		/*
		for(int i=0;i<170;i++){
			if(!(buf[i]==49 || buf[i]==50 || buf[i]==51)){
				 buf[i]=51;
			}
		}
		*/
		fclose(m_pFile);
	}

	Singleton* st= Singleton::GetInstance();
	int DelNums=(buf[157]-48)*100+(buf[158]-48)*10+(buf[159]-48);
	st->setDelNum(DelNums);

	int num=0;
	for(int i=0;i<12;i++)
	{
		num=n*12+i;
		if(i>0){
			for(it=BlockList->begin();it!=BlockList->end();it++){
				BlockTemp = *it;
				BlockTemp->setPosition(ccp(BlockTemp->getPosition().x,BlockTemp->getPosition().y+BlockTemp->getContentSize().height));
			}
		}
		
		Block = getOneBlock(buf[num]);
		Block->setPosition(ccp(Block->getContentSize().width*n+Block->getContentSize().width/2,Block->getContentSize().height/2));
		BlockList->addObject(Block);
	}
	
	return BlockList;
}

//Get a Block
CCSprite* HelloWorld::getOneBlock(int num)
{	
	CCSprite* Block;
	num=num-48;
	switch(num)
	{
		case 1:
			Block=CCSprite::spriteWithFile("DiamondBlue.png",CCRectMake(0,0,32,32));
			Block->setTag(1);
			break;
		case 2:
			Block=CCSprite::spriteWithFile("DiamondGreen.png",CCRectMake(0,0,32,32));
			Block->setTag(2);
			break;
		case 3:
			Block=CCSprite::spriteWithFile("DiamondPurple.png",CCRectMake(0,0,32,32));
			Block->setTag(3);
			break;
		case 4:
			Block=CCSprite::spriteWithFile("DiamondRed.png",CCRectMake(0,0,32,32));
			Block->setTag(4);
			break;
		case 5:
			Block=CCSprite::spriteWithFile("DiamondRoseo.png",CCRectMake(0,0,32,32));
			Block->setTag(5);
			break;
		case 6:
			Block=CCSprite::spriteWithFile("DiamondYellow.png",CCRectMake(0,0,32,32));
			Block->setTag(6);
			break;
	}
	
	this->addChild(Block);
	return Block;
}

//Get a list of Block
CCMutableArray<CCSprite*>* HelloWorld::getBlockList(int n)
{
	CCSprite* Block,* BlockTemp;
	CCMutableArray<CCSprite*>* BlockList = new CCMutableArray<CCSprite*>;
	CCMutableArray<CCSprite*>::CCMutableArrayIterator it;
	
	for(int i=0;i<12;i++)
	{
		if(i>0){
			for(it=BlockList->begin();it!=BlockList->end();it++){
				BlockTemp = *it;
				BlockTemp->setPosition(ccp(BlockTemp->getPosition().x,BlockTemp->getPosition().y+BlockTemp->getContentSize().height));
			}
		}
		Block = getOneBlock();
		Block->setPosition(ccp(Block->getContentSize().width*n+Block->getContentSize().width/2+4,Block->getContentSize().height/2));
		BlockList->addObject(Block);
	}
	
	return BlockList;
}

//Get a Block
CCSprite* HelloWorld::getOneBlock()
{	
	//srand(time(NULL)+rand());
	//BlockNum=BlockNum+time(NULL)+rand();
	//srand(BlockNum+BlockNum%11+(BlockNum%3*BlockNum%7));
	int num1 = rand()%3+1;
	CCSprite* Block;
	switch(num1)
	{
		case 1:
			Block=CCSprite::spriteWithFile("DiamondBlue.png",CCRectMake(0,0,32,32));
			Block->setTag(1);
			break;
		case 2:
			Block=CCSprite::spriteWithFile("DiamondGreen.png",CCRectMake(0,0,32,32));
			Block->setTag(2);
			break;
		case 3:
			Block=CCSprite::spriteWithFile("DiamondPurple.png",CCRectMake(0,0,32,32));
			Block->setTag(3);
			break;
		case 4:
			Block=CCSprite::spriteWithFile("DiamondRed.png",CCRectMake(0,0,32,32));
			Block->setTag(4);
			break;
		case 5:
			Block=CCSprite::spriteWithFile("DiamondRoseo.png",CCRectMake(0,0,32,32));
			Block->setTag(5);
			break;
		case 6:
			Block=CCSprite::spriteWithFile("DiamondYellow.png",CCRectMake(0,0,32,32));
			Block->setTag(6);
			break;
	}
	
	this->addChild(Block);
	return Block;
}
int HelloWorld::getRandNum(){
	Singleton* st = Singleton::GetInstance();
	int level=st->getLevel();

	srand(time(NULL)+rand());
	BlockNum=BlockNum+time(NULL)+rand();
	srand(BlockNum+BlockNum%21+BlockNum%11);
	int num1 = rand()%21+1;
	return num1;
}

//Move the BlockList to the left or right
void HelloWorld::MoveBlockList(CCMutableArray<CCSprite*>* BlockList,int Direction){
	CCSprite* ListTemp;
	CCMutableArray<CCSprite*>::CCMutableArrayIterator it;
	if(BlockList!=NULL){
		for(it=BlockList->begin();it!=BlockList->end();it++){
			ListTemp=*it;
			ListTemp->setPosition(ccp(ListTemp->getPosition().x+Direction*ListTemp->getContentSize().width,ListTemp->getPosition().y));
		}
	}
}

//Reset position in the BlockList of elements
void HelloWorld::SortBlockList(cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList){
	int listNum=BlockList->count();
	CCSprite* ListTemp;
	CCMutableArray<CCSprite*>::CCMutableArrayIterator it;
	for(it=BlockList->begin();it!=BlockList->end();it++){
		ListTemp=*it;
		listNum--;
		ListTemp->setPosition(ccp(ListTemp->getPosition().x,ListTemp->getContentSize().height*listNum+ListTemp->getContentSize().height/2));
	}
}

int HelloWorld::countLeftBlock(){
	CCMutableArray<CCSprite*>::CCMutableArrayIterator it,jt,kt,lt,mt,nt,xt,yt,zt;
	//记录13个list
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList1_1=new CCMutableArray<CCSprite*>;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList2_1=new CCMutableArray<CCSprite*>;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList3_1=new CCMutableArray<CCSprite*>;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList4_1=new CCMutableArray<CCSprite*>;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList5_1=new CCMutableArray<CCSprite*>;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList6_1=new CCMutableArray<CCSprite*>;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList7_1=new CCMutableArray<CCSprite*>;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList8_1=new CCMutableArray<CCSprite*>;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList9_1=new CCMutableArray<CCSprite*>;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList10_1=new CCMutableArray<CCSprite*>;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList11_1=new CCMutableArray<CCSprite*>;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList12_1=new CCMutableArray<CCSprite*>;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList13_1=new CCMutableArray<CCSprite*>;

	//BlockList0记录所有原始的Bloak
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList0=new CCMutableArray<CCSprite*>;
	//BlockList0_1 存储本次全部的Block;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList0_1=new CCMutableArray<CCSprite*>;
	//BlockList0_2 存储本次已判断的Block;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList0_2=new CCMutableArray<CCSprite*>;
	//BlockList0_3 存储即将判断的Block;
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList0_3=new CCMutableArray<CCSprite*>;
	//BlockList0_4 计算是否结束本次计算
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList0_4=new CCMutableArray<CCSprite*>;
	//记录已判断过的Block
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList0_5=new CCMutableArray<CCSprite*>;
	//记录要删除的Block
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList0_6=new CCMutableArray<CCSprite*>;
	//临时记录要删除的BlockList0中的Block
	cocos2d::CCMutableArray<cocos2d::CCSprite*>* BlockList0_7=new CCMutableArray<CCSprite*>;

	CCSprite* ListTemp,* ListTemp1;
	int countBlock=0;
	int countBlockTemp=0;
	int BlockNums=0;
	int BlockNumTemp=0;

	//删除的Block数量
	int LeftNum=0;
	//本局得分
	int BlockScore=0;

	//给BlockList0赋值
	for(it=_BlockList->begin();it!=_BlockList->end();it++){
		ListTemp=*it;
		ListTemp1 =new CCSprite();
		ListTemp1->setPosition(ListTemp->getPosition());
		ListTemp1->setTag(ListTemp->getTag());
		ListTemp1->setContentSize(ListTemp->getContentSize());

		BlockList0->addObject(ListTemp1);
	}

	int bools=0;
	do{
		int boolNum=0;
		int bools_1=0;
		BlockList0_5->removeAllObjects();
		do{
			BlockList0_1->removeAllObjects();
			BlockList0_2->removeAllObjects();
			BlockList0_3->removeAllObjects();
			BlockList0_4->removeAllObjects();

			BlockList1_1->removeAllObjects();
			BlockList2_1->removeAllObjects();
			BlockList3_1->removeAllObjects();
			BlockList4_1->removeAllObjects();
			BlockList5_1->removeAllObjects();
			BlockList6_1->removeAllObjects();
			BlockList7_1->removeAllObjects();
			BlockList8_1->removeAllObjects();
			BlockList9_1->removeAllObjects();
			BlockList10_1->removeAllObjects();
			BlockList11_1->removeAllObjects();
			BlockList12_1->removeAllObjects();
			BlockList13_1->removeAllObjects();

			for(xt=BlockList0->begin();xt!=BlockList0->end();xt++){
				ListTemp=*xt;
				ListTemp1 =new CCSprite();
				ListTemp1->setPosition(ListTemp->getPosition());
				ListTemp1->setTag(ListTemp->getTag());
				ListTemp1->setContentSize(ListTemp->getContentSize());

				if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width){
					BlockList1_1->addObject(ListTemp1);
				}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*2){
					BlockList2_1->addObject(ListTemp1);
				}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*3){
					BlockList3_1->addObject(ListTemp1);
				}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*4){
					BlockList4_1->addObject(ListTemp1);
				}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*5){
					BlockList5_1->addObject(ListTemp1);
				}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*6){
					BlockList6_1->addObject(ListTemp1);
				}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*7){
					BlockList7_1->addObject(ListTemp1);
				}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*8){
					BlockList8_1->addObject(ListTemp1);
				}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*9){
					BlockList9_1->addObject(ListTemp1);
				}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*10){
					BlockList10_1->addObject(ListTemp1);
				}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*11){
					BlockList11_1->addObject(ListTemp1);
				}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*12){
					BlockList12_1->addObject(ListTemp1);
				}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*13){
					BlockList13_1->addObject(ListTemp1);
				}
				
				BlockList0_1->addObject(ListTemp1);
			}
			//整理13个数组
			if(BlockList1_1->count()>0){
				SortBlockList(BlockList1_1);
			}
			if(BlockList2_1->count()>0){
				SortBlockList(BlockList2_1);
			}else{
				MoveBlockList(BlockList1_1,1);
			}
			if(BlockList3_1->count()>0){
				SortBlockList(BlockList3_1);
			}else{
				MoveBlockList(BlockList2_1,1);
				MoveBlockList(BlockList1_1,1);
			}
			if(BlockList4_1->count()>0){
				SortBlockList(BlockList4_1);
			}else{
				MoveBlockList(BlockList3_1,1);
				MoveBlockList(BlockList2_1,1);
				MoveBlockList(BlockList1_1,1);
			}
			if(BlockList5_1->count()>0){
				SortBlockList(BlockList5_1);
			}else{
				MoveBlockList(BlockList4_1,1);
				MoveBlockList(BlockList3_1,1);
				MoveBlockList(BlockList2_1,1);
				MoveBlockList(BlockList1_1,1);
			}
			if(BlockList6_1->count()>0){
				SortBlockList(BlockList6_1);
			}else{
				MoveBlockList(BlockList5_1,1);
				MoveBlockList(BlockList4_1,1);
				MoveBlockList(BlockList3_1,1);
				MoveBlockList(BlockList2_1,1);
				MoveBlockList(BlockList1_1,1);
			}
			if(BlockList7_1->count()>0){
				SortBlockList(BlockList7_1);
			}else{
				MoveBlockList(BlockList6_1,1);
				MoveBlockList(BlockList5_1,1);
				MoveBlockList(BlockList4_1,1);
				MoveBlockList(BlockList3_1,1);
				MoveBlockList(BlockList2_1,1);
				MoveBlockList(BlockList1_1,1);
			}
			if(BlockList8_1->count()>0){
				SortBlockList(BlockList8_1);
			}else{
				MoveBlockList(BlockList9_1,-1);
				MoveBlockList(BlockList10_1,-1);
				MoveBlockList(BlockList11_1,-1);
				MoveBlockList(BlockList12_1,-1);
				MoveBlockList(BlockList13_1,-1);
			}
			if(BlockList9_1->count()>0){
				SortBlockList(BlockList9_1);
			}else{
				MoveBlockList(BlockList10_1,-1);
				MoveBlockList(BlockList11_1,-1);
				MoveBlockList(BlockList12_1,-1);
				MoveBlockList(BlockList13_1,-1);
			}
			if(BlockList10_1->count()>0){
				SortBlockList(BlockList10_1);
			}else{
				MoveBlockList(BlockList11_1,-1);
				MoveBlockList(BlockList12_1,-1);
				MoveBlockList(BlockList13_1,-1);
			}
			if(BlockList11_1->count()>0){
				SortBlockList(BlockList11_1);
			}else{
				MoveBlockList(BlockList12_1,-1);
				MoveBlockList(BlockList13_1,-1);
			}
			if(BlockList12_1->count()>0){
				SortBlockList(BlockList12_1);
			}else{
				MoveBlockList(BlockList13_1,-1);
			}
			if(BlockList13_1->count()>0){
				SortBlockList(BlockList13_1);
			}

			//判定是否结束；
			CCSprite* tempSprite1,*tempSprite2,*tempSprite3;
			float tempSprite2X,tempSprite2Y,tempSprite3X,tempSprite3Y;
			int num=0;
			int num1=0;
			float lenth1=0;
			bools_1=1;
			for(it=BlockList0_1->begin();it!=BlockList0_1->end();it++){
				BlockList0_4->removeAllObjects();
				tempSprite1=*it;
				if(BlockList0_3->containsObject(tempSprite1)){
					continue;
				}
				boolNum=0;
				for(yt=BlockList0_5->begin();yt!=BlockList0_5->end();yt++){
					ListTemp1=*yt;
					if(tempSprite1->getTag()==ListTemp1->getTag()){
						if(tempSprite1->getPosition().x==ListTemp1->getPosition().x&&tempSprite1->getPosition().y==ListTemp1->getPosition().y){
							boolNum=1;
						}
					}
					if(boolNum==1){
						break;
					}
				}
				if(boolNum==1){
					continue;
				}

				BlockList0_4->addObject(tempSprite1);
				num=0;
				do{
					num=BlockList0_4->count();
					for(jt=BlockList0_1->begin();jt!=BlockList0_1->end();jt++){
						tempSprite2=*jt;
						if(BlockList0_4->containsObject(tempSprite2)){
							continue;
						}
						if(BlockList0_3->containsObject(tempSprite2)){
							continue;
						}
						boolNum=0;
						for(yt=BlockList0_5->begin();yt!=BlockList0_5->end();yt++){
							ListTemp1=*yt;
							if(tempSprite2->getTag()==ListTemp1->getTag()){
								if(tempSprite2->getPosition().x==ListTemp1->getPosition().x&&tempSprite2->getPosition().y==ListTemp1->getPosition().y){
									boolNum=1;
								}
							}
							if(boolNum==1){
								break;
							}
						}
						if(boolNum==1){
							continue;
						}
						tempSprite2X = tempSprite2->getPosition().x;
						tempSprite2Y = tempSprite2->getPosition().y;
						num1=0;
						for(kt=BlockList0_4->begin();kt!=BlockList0_4->end();kt++){
							tempSprite3=*kt;
							tempSprite3X = tempSprite3->getPosition().x;
							tempSprite3Y = tempSprite3->getPosition().y;
							lenth1=0;
							if(tempSprite2->getTag()==tempSprite3->getTag()){
								if(tempSprite2X==tempSprite3X){
									lenth1 = tempSprite3Y-tempSprite2Y;
								}else if(tempSprite3Y==tempSprite2Y){
									lenth1 = tempSprite3X-tempSprite2X;
								}
								if(lenth1<0){
									lenth1=0-lenth1;
								}
								if(lenth1>0&&lenth1<=tempSprite3->getContentSize().width){
									num1=1;
									break;
								}
							}
						}
						if(num1==1){
							BlockList0_4->addObject(tempSprite2);	
						}
					}
				}while((int)BlockList0_4->count()>num);
				
				if(BlockList0_4->count()<3){
					bools_1=1;
				}else{
					bools_1=0;
					break;
				}
				for(kt=BlockList0_4->begin();kt!=BlockList0_4->end();kt++){
					tempSprite1=*kt;
					BlockList0_3->addObject(tempSprite1);
				}
			}

			BlockList0_3->removeAllObjects();
			BlockList0_4->removeAllObjects();
			if(bools_1==0){
				for(jt=BlockList0_1->begin();jt!=BlockList0_1->end();jt++){
					BlockList0_3->removeAllObjects();
					ListTemp=*jt;
					if(BlockList0_2->containsObject(ListTemp)){
						continue;
					}
					BlockList0_3->addObject(ListTemp);

					//判断连续的Block,存储在BlockList0_3中
					CCSprite *BlockTemp1,*BlockTemp2;
					float BlockTemp1X,BlockTemp1Y,BlockTemp2X,BlockTemp2Y;
					int numA=0;
					int numB=0;
					float lenth=0;
					do{
						numA=BlockList0_3->count();
						for(kt=BlockList0_1->begin();kt!=BlockList0_1->end();kt++){
							BlockTemp1=*kt;
							if(BlockList0_3->containsObject(BlockTemp1)){
								continue;
							}
							if(BlockList0_2->containsObject(BlockTemp1)){
								continue;
							}
							if(countBlockTemp==0){
								boolNum=0;
								for(yt=BlockList0_5->begin();yt!=BlockList0_5->end();yt++){
									ListTemp1=*yt;
									if(BlockTemp1->getTag()==ListTemp1->getTag()){
										if(BlockTemp1->getPosition().x==ListTemp1->getPosition().x&&BlockTemp1->getPosition().y==ListTemp1->getPosition().y){
											boolNum=1;
										}
									}
									if(boolNum==1){
										break;
									}
								}
								if(boolNum==1){
									continue;
								}
							}
							BlockTemp1X = BlockTemp1->getPosition().x;
							BlockTemp1Y = BlockTemp1->getPosition().y;
							numB=0;
							for(lt=BlockList0_3->begin();lt!=BlockList0_3->end();lt++){
								BlockTemp2=*lt;
								BlockTemp2X = BlockTemp2->getPosition().x;
								BlockTemp2Y = BlockTemp2->getPosition().y;
								lenth=0;
								if(BlockTemp1->getTag()==BlockTemp2->getTag()){
									if(BlockTemp1X==BlockTemp2X){
										lenth = BlockTemp1Y-BlockTemp2Y;
									}else if(BlockTemp1Y==BlockTemp2Y){
										lenth = BlockTemp1X-BlockTemp2X;
									}
									if(lenth<0){
										lenth=0-lenth;
									}
								}
								if(lenth==BlockTemp1->getContentSize().width){
									numB=1;
									break;
								}
							}
							if(numB==1){
								BlockList0_3->addObject(BlockTemp1);	
							}
						}
					}while((int)BlockList0_3->count()>numA);
					
					if(countBlockTemp>0){
						if((int)BlockList0_3->count()>2){
							BlockNumTemp = BlockNumTemp+((int)BlockList0_3->count());
							countBlockTemp=countBlockTemp+((int)BlockList0_3->count())*((int)BlockList0_3->count())*5;
						}
						for(it=BlockList0_3->begin();it!=BlockList0_3->end();it++){
							BlockList0_2->addObject(*it);
						}
					}else if((int)BlockList0_3->count()>2){
						BlockNumTemp =BlockNumTemp +((int)BlockList0_3->count());
						countBlockTemp=((int)BlockList0_3->count())*((int)BlockList0_3->count())*5;
						CCSprite *BlockTemp3,*BlockTemp4;
						for(mt=BlockList0_3->begin();mt!=BlockList0_3->end();mt++){
							BlockTemp3=*mt;
							BlockList0_2->addObject(*mt);
							BlockTemp4=new CCSprite();
							BlockTemp4->setTag(BlockTemp3->getTag());
							BlockTemp4->setPosition(BlockTemp3->getPosition());
							BlockTemp4->setContentSize(BlockTemp3->getContentSize());
							BlockList0_4->addObject(BlockTemp4);

						}
						for(mt=BlockList0_3->begin();mt!=BlockList0_3->end();mt++){
							if((int)BlockList1_1->count()>0&&BlockList1_1->containsObject(*mt)){
								BlockList1_1->removeObject(*mt);
								SortBlockList(BlockList1_1);
								continue;
							}
							if((int)BlockList2_1->count()>0&&BlockList2_1->containsObject(*mt)){
								BlockList2_1->removeObject(*mt);
								SortBlockList(BlockList2_1);
								if(BlockList2_1->count()<1){
									MoveBlockList(BlockList1_1,1);
								}
								continue;
							}
							if((int)BlockList3_1->count()>0&&BlockList3_1->containsObject(*mt)){
								BlockList3_1->removeObject(*mt);
								SortBlockList(BlockList3_1);
								if(BlockList3_1->count()<1){
									MoveBlockList(BlockList2_1,1);
									MoveBlockList(BlockList1_1,1);
								}
								continue;
							}
							if((int)BlockList4_1->count()>0&&BlockList4_1->containsObject(*mt)){
								BlockList4_1->removeObject(*mt);
								SortBlockList(BlockList4_1);
								if(BlockList4_1->count()<1){
									MoveBlockList(BlockList3_1,1);
									MoveBlockList(BlockList2_1,1);
									MoveBlockList(BlockList1_1,1);
								}
								continue;
							}
							if((int)BlockList5_1->count()>0&&BlockList5_1->containsObject(*mt)){
								BlockList5_1->removeObject(*mt);
								SortBlockList(BlockList5_1);
								if(BlockList5_1->count()<1){
									MoveBlockList(BlockList4_1,1);
									MoveBlockList(BlockList3_1,1);
									MoveBlockList(BlockList2_1,1);
									MoveBlockList(BlockList1_1,1);
								}
								continue;
							}
							if((int)BlockList6_1->count()>0&&BlockList6_1->containsObject(*mt)){
								BlockList6_1->removeObject(*mt);
								SortBlockList(BlockList6_1);
								if(BlockList6_1->count()<1){
									MoveBlockList(BlockList5_1,1);
									MoveBlockList(BlockList4_1,1);
									MoveBlockList(BlockList3_1,1);
									MoveBlockList(BlockList2_1,1);
									MoveBlockList(BlockList1_1,1);
								}
								continue;
							}
							if((int)BlockList7_1->count()>0&&BlockList7_1->containsObject(*mt)){
								BlockList7_1->removeObject(*mt);
								SortBlockList(BlockList7_1);
								if(BlockList7_1->count()<1){
									MoveBlockList(BlockList6_1,1);
									MoveBlockList(BlockList5_1,1);
									MoveBlockList(BlockList4_1,1);
									MoveBlockList(BlockList3_1,1);
									MoveBlockList(BlockList2_1,1);
									MoveBlockList(BlockList1_1,1);
								}
								continue;
							}
							if((int)BlockList8_1->count()>0&&BlockList8_1->containsObject(*mt)){
								BlockList8_1->removeObject(*mt);
								SortBlockList(BlockList8_1);
								if(BlockList8_1->count()<1){
									MoveBlockList(BlockList9_1,-1);
									MoveBlockList(BlockList10_1,-1);
									MoveBlockList(BlockList11_1,-1);
									MoveBlockList(BlockList12_1,-1);
									MoveBlockList(BlockList13_1,-1);
								}
								continue;
							}
							if((int)BlockList9_1->count()>0&&BlockList9_1->containsObject(*mt)){
								BlockList9_1->removeObject(*mt);
								SortBlockList(BlockList9_1);
								if(BlockList9_1->count()<1){
									MoveBlockList(BlockList10_1,-1);
									MoveBlockList(BlockList11_1,-1);
									MoveBlockList(BlockList12_1,-1);
									MoveBlockList(BlockList13_1,-1);
								}
								continue;
							}
							if((int)BlockList10_1->count()>0&&BlockList10_1->containsObject(*mt)){
								BlockList10_1->removeObject(*mt);
								SortBlockList(BlockList10_1);
								if(BlockList10_1->count()<1){
									MoveBlockList(BlockList11_1,-1);
									MoveBlockList(BlockList12_1,-1);
									MoveBlockList(BlockList13_1,-1);
								}
								continue;
							}
							if((int)BlockList11_1->count()>0&&BlockList11_1->containsObject(*mt)){
								BlockList11_1->removeObject(*mt);
								SortBlockList(BlockList11_1);
								if(BlockList11_1->count()<1){
									MoveBlockList(BlockList12_1,-1);
									MoveBlockList(BlockList13_1,-1);
								}
								continue;
							}
							if((int)BlockList12_1->count()>0&&BlockList12_1->containsObject(*mt)){
								BlockList12_1->removeObject(*mt);
								SortBlockList(BlockList12_1);
								if(BlockList12_1->count()<1){
									MoveBlockList(BlockList13_1,-1);
								}
								continue;
							}
							if((int)BlockList13_1->count()>0&&BlockList13_1->containsObject(*mt)){
								BlockList13_1->removeObject(*mt);
								SortBlockList(BlockList13_1);
								continue;
							}
						}
					}
				}
				
				/*
				if(countBlockTemp>countBlock){
					countBlock=countBlockTemp;
					BlockList0_6->removeAllObjects();
					for(nt=BlockList0_4->begin();nt!=BlockList0_4->end();nt++){
						BlockList0_6->addObject(*nt);
					}
				}
				//*/
				///*
				if(BlockNumTemp>BlockNums){
					BlockNums=BlockNumTemp;
					BlockList0_6->removeAllObjects();
					for(nt=BlockList0_4->begin();nt!=BlockList0_4->end();nt++){
						BlockList0_6->addObject(*nt);
					}
				}
				//*/

				for(nt=BlockList0_4->begin();nt!=BlockList0_4->end();nt++){
					BlockList0_5->addObject(*nt);
				}
				
				BlockList0_4->removeAllObjects();
				countBlockTemp=0;
				BlockNumTemp=0;
			}
		}while(bools_1==0);

		//char numD[64];
		//sprintf(numD, "%d", BlockList0_3->count());
		//CCLog(numD);

		BlockScore+=((int)BlockList0_6->count())*((int)BlockList0_6->count())*5;
		LeftNum+=BlockList0_6->count();
		countBlock=0;
		BlockNums=0;

		for(yt=BlockList0_6->begin();yt!=BlockList0_6->end();yt++){
			ListTemp=*yt;
			for(xt=BlockList0->begin();xt!=BlockList0->end();xt++){
				ListTemp1=*xt;
				if(ListTemp->getTag()==ListTemp1->getTag()){
					if(ListTemp->getPosition().x==ListTemp1->getPosition().x&&ListTemp->getPosition().y==ListTemp1->getPosition().y){
						BlockList0_7->addObject(*xt);
					}
				}
				
			}
		}
		for(yt=BlockList0_7->begin();yt!=BlockList0_7->end();yt++){
			BlockList0->removeObject(*yt);
		}
		BlockList0_7->removeAllObjects();
		BlockList0_6->removeAllObjects();

		BlockList0_1->removeAllObjects();
		BlockList0_4->removeAllObjects();

		BlockList1_1->removeAllObjects();
		BlockList2_1->removeAllObjects();
		BlockList3_1->removeAllObjects();
		BlockList4_1->removeAllObjects();
		BlockList5_1->removeAllObjects();
		BlockList6_1->removeAllObjects();
		BlockList7_1->removeAllObjects();
		BlockList8_1->removeAllObjects();
		BlockList9_1->removeAllObjects();
		BlockList10_1->removeAllObjects();
		BlockList11_1->removeAllObjects();
		BlockList12_1->removeAllObjects();
		BlockList13_1->removeAllObjects();

		for(xt=BlockList0->begin();xt!=BlockList0->end();xt++){
			ListTemp1=*xt;

			if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width){
				BlockList1_1->addObject(ListTemp1);
			}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*2){
				BlockList2_1->addObject(ListTemp1);
			}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*3){
				BlockList3_1->addObject(ListTemp1);
			}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*4){
				BlockList4_1->addObject(ListTemp1);
			}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*5){
				BlockList5_1->addObject(ListTemp1);
			}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*6){
				BlockList6_1->addObject(ListTemp1);
			}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*7){
				BlockList7_1->addObject(ListTemp1);
			}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*8){
				BlockList8_1->addObject(ListTemp1);
			}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*9){
				BlockList9_1->addObject(ListTemp1);
			}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*10){
				BlockList10_1->addObject(ListTemp1);
			}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*11){
				BlockList11_1->addObject(ListTemp1);
			}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*12){
				BlockList12_1->addObject(ListTemp1);
			}else if(ListTemp1->getPosition().x<ListTemp1->getContentSize().width*13){
				BlockList13_1->addObject(ListTemp1);
			}
		}
		//整理13个数组
		if(BlockList1_1->count()>0){
			SortBlockList(BlockList1_1);
		}
		if(BlockList2_1->count()>0){
			SortBlockList(BlockList2_1);
		}else{
			MoveBlockList(BlockList1_1,1);
		}
		if(BlockList3_1->count()>0){
			SortBlockList(BlockList3_1);
		}else{
			MoveBlockList(BlockList2_1,1);
			MoveBlockList(BlockList1_1,1);
		}
		if(BlockList4_1->count()>0){
			SortBlockList(BlockList4_1);
		}else{
			MoveBlockList(BlockList3_1,1);
			MoveBlockList(BlockList2_1,1);
			MoveBlockList(BlockList1_1,1);
		}
		if(BlockList5_1->count()>0){
			SortBlockList(BlockList5_1);
		}else{
			MoveBlockList(BlockList4_1,1);
			MoveBlockList(BlockList3_1,1);
			MoveBlockList(BlockList2_1,1);
			MoveBlockList(BlockList1_1,1);
		}
		if(BlockList6_1->count()>0){
			SortBlockList(BlockList6_1);
		}else{
			MoveBlockList(BlockList5_1,1);
			MoveBlockList(BlockList4_1,1);
			MoveBlockList(BlockList3_1,1);
			MoveBlockList(BlockList2_1,1);
			MoveBlockList(BlockList1_1,1);
		}
		if(BlockList7_1->count()>0){
			SortBlockList(BlockList7_1);
		}else{
			MoveBlockList(BlockList6_1,1);
			MoveBlockList(BlockList5_1,1);
			MoveBlockList(BlockList4_1,1);
			MoveBlockList(BlockList3_1,1);
			MoveBlockList(BlockList2_1,1);
			MoveBlockList(BlockList1_1,1);
		}
		if(BlockList8_1->count()>0){
			SortBlockList(BlockList8_1);
		}else{
			MoveBlockList(BlockList9_1,-1);
			MoveBlockList(BlockList10_1,-1);
			MoveBlockList(BlockList11_1,-1);
			MoveBlockList(BlockList12_1,-1);
			MoveBlockList(BlockList13_1,-1);
		}
		if(BlockList9_1->count()>0){
			SortBlockList(BlockList9_1);
		}else{
			MoveBlockList(BlockList10_1,-1);
			MoveBlockList(BlockList11_1,-1);
			MoveBlockList(BlockList12_1,-1);
			MoveBlockList(BlockList13_1,-1);
		}
		if(BlockList10_1->count()>0){
			SortBlockList(BlockList10_1);
		}else{
			MoveBlockList(BlockList11_1,-1);
			MoveBlockList(BlockList12_1,-1);
			MoveBlockList(BlockList13_1,-1);
		}
		if(BlockList11_1->count()>0){
			SortBlockList(BlockList11_1);
		}else{
			MoveBlockList(BlockList12_1,-1);
			MoveBlockList(BlockList13_1,-1);
		}
		if(BlockList12_1->count()>0){
			SortBlockList(BlockList12_1);
		}else{
			MoveBlockList(BlockList13_1,-1);
		}
		if(BlockList13_1->count()>0){
			SortBlockList(BlockList13_1);
		}

		bools=1;
		//判定是否结束；
		CCSprite* tempSprite1,*tempSprite2,*tempSprite3;
		float tempSprite2X,tempSprite2Y,tempSprite3X,tempSprite3Y;
		int num=0;
		int num1=0;
		float lenth1=0;
		for(it=BlockList0->begin();it!=BlockList0->end();it++){
			tempSprite1=*it;
			BlockList0_4->addObject(tempSprite1);
			num=0;
			do{
				num=BlockList0_4->count();
				for(jt=BlockList0->begin();jt!=BlockList0->end();jt++){
					tempSprite2=*jt;
					if(BlockList0_4->containsObject(tempSprite2)){
						continue;
					}
					tempSprite2X = tempSprite2->getPosition().x;
					tempSprite2Y = tempSprite2->getPosition().y;
					num1=0;
					for(kt=BlockList0_4->begin();kt!=BlockList0_4->end();kt++){
						tempSprite3=*kt;
						tempSprite3X = tempSprite3->getPosition().x;
						tempSprite3Y = tempSprite3->getPosition().y;
						lenth1=0;
						if(tempSprite2->getTag()==tempSprite3->getTag()){
							if(tempSprite2X==tempSprite3X){
								lenth1 = tempSprite3Y-tempSprite2Y;
							}else if(tempSprite3Y==tempSprite2Y){
								lenth1 = tempSprite3X-tempSprite2X;
							}
							if(lenth1<0){
								lenth1=0-lenth1;
							}
							if(lenth1>0&&lenth1<=tempSprite3->getContentSize().width){
								num1=1;
								break;
							}
						}
					}
					if(num1==1){
						BlockList0_4->addObject(tempSprite2);	
					}
				}
			}while((int)BlockList0_4->count()>num);
			
			if(BlockList0_4->count()>2){
				bools=0;
				break;
			}
			BlockList0_4->removeAllObjects();
		}
	}while(bools==0);

	return BlockScore*10000+(LeftNum);
}
