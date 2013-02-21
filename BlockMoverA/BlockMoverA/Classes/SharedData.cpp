#include "SharedData.h"

Singleton* Singleton::instance=GetInstance();

Singleton::Singleton()
{
	this->setLevel(1);
	this->setScore(0);
	this->setScorePre(0);
	this->setStar(0);
	this->setDelNum(0);
}

Singleton::~Singleton()
{
	if(NULL!=instance)
	{
		delete instance;
	}
}

int Singleton::getLevel()
{
	if(level<1||level>1000){
		level=0;
	}
	return level;
}
void Singleton::setLevel(int level)
{
	this->level=level;
}

int Singleton::getScore(){
	if(score<0){
		score=0;
	}
	return score;
}

void Singleton::setScore(int score){
	this->score=score;
}

int Singleton::getScorePre(){
	if(scorePre<0){
		scorePre=0;
	}
	return scorePre;
}

void Singleton::setScorePre(int scorePre){
	this->scorePre=scorePre;
}

int Singleton::getStar(){
	if(star<0){
		star=0;
	}
	return star;
}

void Singleton::setStar(int star){
	this->star=star;
}

int Singleton::getDelNum(){
	if(delNum<0){
		delNum=0;
	}
	return delNum;
}

void Singleton::setDelNum(int delNum){
	this->delNum=delNum;
}