//
//  LoadScene.cpp
//  Cocos2dDEMO
//
//  Created by CMY on 16/5/10.
//
//

#include "LoadScene.hpp"
#include "SecondLayer.hpp"
#include "UI.hpp"

void LoadScene::onEnter()
{
	CCLayer::onEnter();
	CCNotificationCenter::sharedNotificationCenter()->addObserver(
																  this,
																  callfuncO_selector(LoadScene::HandleMsg),
																  "test",
																  NULL);
}

void LoadScene::onExit()
{
	
	CCLayer::onExit();
	CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(this);
}


CCScene* LoadScene::scene()
{
	CCScene *scene = CCScene::create();
	
	LoadScene *layer = LoadScene::create();
	
	
	scene->addChild(layer);
	
	
	return scene;
}

bool LoadScene::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}
	
	this->m_loadedNum = 0;
	this->m_totalNum = 100;
	
	
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	
	m_progress = CCProgressTimer::create(CCSprite::create("HelloWorld.png"));
	m_progress->setPosition(s.width/2, s.height/2);
	this->addChild(m_progress);
	
	m_progress->setType(kCCProgressTimerTypeBar);
	m_progress->setBarChangeRate(ccp(1, 0));  //水平 竖直
	m_progress->setMidpoint(ccp(0, 0)); //左到右 ? 上到下
	
	
	
	this->m_labelLoading = CCLabelTTF::create("0%", "", 30);
	m_progress->addChild(m_labelLoading);
	
	
	//这里的代码是用来加载图片的，到时候把你需要加载的图片都写到这里面
	for(int i=0;i<100;i++)
	{
		//addImageAsync异步加载图片
		CCTextureCache::sharedTextureCache()->addImageAsync("CloseNormal.png",this,
															callfuncO_selector(LoadScene::loadingCallBack));
		
	}
	

	UI* ui = new UI();
	
	
	
	
	return true;
}




void LoadScene::HandleMsg( CCObject* pData ) {
	CCString* sData = (CCString*) pData;
	CCLOG("testMsg in OtherLayer: %s", sData->getCString());
}


void LoadScene::loadingCallBack(CCObject *object)
{
	this->m_loadedNum ++;
	
	//获得加载的图片占图片总数的百分比
	float percentage = (float)this->m_loadedNum/this->m_totalNum*100;

	m_labelLoading->setString(CCString::createWithFormat("%0.0f%",percentage)->getCString());
	
	m_progress->setPercentage(percentage);
	
	if (percentage >= 100) {
		this->addChild(SecondLayer::create());
	}
}
