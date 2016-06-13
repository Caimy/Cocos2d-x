//
//  BlockLayer.cpp
//  Cocos2dDEMO
//
//  Created by CMY on 16/6/7.
//
//

#include "BlockLayer.hpp"

bool BlockLayer::init()
{
	ccColor4B color = {100,0,0,125};  //设置面板颜色及透明度
	if (!CCLayerColor::initWithColor(color))
	{
		return false;
	}
	initData();
	setTouchEnabled(true);   //开启触摸事件
	
	return true;
}


void BlockLayer::initData()
{
//	CCMenuItemImage *pMenuImage = CCMenuItemImage::create(
//														  "CloseNormal.png",
//														  "CloseSelected.png",
//														  this,
//														  menu_selector(BlockLayer::onMenuClick_Test));
//	pMenuImage->setScale(4);
//	CCMenu* pMenu = CCMenu::create(pMenuImage,NULL);
//	this->addChild(pMenu);
}

void BlockLayer::onMenuClick_Test(CCObject* pSender)
{
	CCLog("能响应到BlockLayer");
	this->removeFromParentAndCleanup(true);
}

void BlockLayer::registerWithTouchDispatcher( void )
{
	//吞噬事件的前提是 优先级要比前面的高 且 吞噬标志为true
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -128,false); 
}

bool BlockLayer::ccTouchBegan( CCTouch *pTouches, CCEvent *pEvent )
{
	CCLOG("SecondLayer ccTouchesBegan");
	return false; //决定是否要move和end
}

void BlockLayer::ccTouchMoved( CCTouch *pTouches, CCEvent *pEvent )
{
	
	CCLOG("SecondLayer ccTouchesMoved");
}

void BlockLayer::ccTouchEnded( CCTouch *pTouches, CCEvent *pEvent )
{
	
	CCLOG("SecondLayer ccTouchesEnded");
}