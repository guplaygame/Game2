#ifndef __SharedData_H__
#define __SharedData_H__
#include "cocos2d.h"

class Singleton :public cocos2d::CCLayerColor
{
private:
	Singleton();
	static Singleton* instance;
	int level;
	int score;
	int scorePre;
	int star;
	int delNum;

public:
	static Singleton* GetInstance()
	{
		if(NULL==instance){
			instance=new Singleton();
		}
		return instance;		
	}

	
	int getLevel();
	void setLevel(int level);
	int getScore();
	void setScore(int score);
	int getScorePre();
	void setScorePre(int scorePre);
	int getStar();
	void setStar(int star);
	int getDelNum();
	void setDelNum(int delNum);

	virtual ~Singleton();
	
};
#endif