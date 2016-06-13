
//  SecondLayer.cpp
//  Cocos2dDEMO
//
//  Created by CMY on 16/5/9.
//
//

#include "SecondLayer.hpp"


bool SecondLayer::init()
{
	bool bRet = false;
	
	do {
	
		CC_BREAK_IF(! CCLayer::init());
		
		CCTexture2D* bg = CCTextureCache::sharedTextureCache()->textureForKey("CloseNormal.png");
		
		CCSprite* spr = CCSprite::createWithTexture(bg);
		
		this->addChild(spr);
		
		scheduleOnce(schedule_selector(SecondLayer::updateOnce), 2);
		
		bRet = true;
		
	} while (0);
	
	return bRet;
}

void SecondLayer::ccTouchesBegan( CCSet *pTouches, CCEvent *pEvent )
{
	CCLOG("SecondLayer ccTouchesBegan");
	
}


void SecondLayer::ccTouchesMoved( CCSet *pTouches, CCEvent *pEvent )
{
	
	CCLOG("SecondLayer ccTouchesMoved");
}

void SecondLayer::ccTouchesEnded( CCSet *pTouches, CCEvent *pEvent )
{
	
	CCLOG("SecondLayer ccTouchesEnded");
}


void SecondLayer::ccTouchesCancelled( CCSet *pTouches, CCEvent *pEvent )
{
	
	CCLOG("SecondLayer ccTouchesCancelled");
}


void SecondLayer::updateOnce(float x)
{
	CCString* sData = CCString::create("HelloWorldScene's data");
	sData->retain();
	
	CCNotificationCenter::sharedNotificationCenter()->postNotification("test", sData);
}
