//
//  LevelScene.cpp
//  Cocos2dDEMO
//
//  Created by CMY on 16/5/11.
//
//

#include "LevelScene.hpp"
#include "math.h"

bool LevelScene::init()
{
	bool bRet = false;
	
	do {
		CC_BREAK_IF( !CCLayer::init() );
	
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		CCLayer* layer = CCLayer::create();
		
		for (int i =0; i<5 ; i++)
		{
			CCString* str = CCString::createWithFormat("%d.png",i+1);
			CCSprite* spr = CCSprite::create(str->getCString());
			spr->setPosition(ccpAdd(ccp(size.width/2, size.height/2), ccp(size.width*i, 0)));
			layer->addChild(spr);
			
		}
		
		m_scrollView = CCScrollView::create(size);
		m_scrollView->setContainer(layer);
		m_scrollView->setTouchEnabled(false);
		m_scrollView->setContentOffset(CCPoint(0, 0));
		this->addChild(m_scrollView);
		
		this->setTouchEnabled(true);
		
		m_nCurPage = 0;
		bRet = true;
		
	} while (0);

	return bRet;
}




//以下是注册触摸事件和实现各种的touch函数
void LevelScene::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0,true); //单点的 2参是优先级、3参是阻止触摸
}


bool LevelScene::ccTouchBegan(CCTouch * touch,CCEvent * pEvent)
{
	//触摸点、偏移量
	this->m_offsetPoint = m_scrollView->getContentOffset();
	this->m_touchPoint = touch->getLocation();
	
	if((int)this->m_offsetPoint.x%((int)CCDirector::sharedDirector()->getWinSize().width) == 0)
	{
		return true;
	}

	return true;
}

void LevelScene::ccTouchMoved(CCTouch * touch,CCEvent * pEvent)
{
	//计算移动了多少、scorllView设置只移动的X
	
	CCPoint point = touch->getLocation();
	
	CCPoint movePoint = ccpSub(point, m_touchPoint); //移动的点
	
	CCPoint movePointX = CCPoint(movePoint.x + m_offsetPoint.x,0); //计算出移动的x
	
	this->m_scrollView->setContentOffset(movePointX);
}

void LevelScene::ccTouchEnded(CCTouch * touch,CCEvent * pEvent)
{
	//计算 触摸结束与触摸开始的距离
	CCPoint endPoint = touch->getLocation();
	
	float distance = endPoint.x - m_touchPoint.x;
	
	if (fabs(distance) < 20)
	{
		//移动的的距离有点小 移动回去之前的页
		adjustScrollView(0);
	}
	else
	{
		//移动的距离有点大 移动到改变的页
		adjustScrollView(distance);
	}
}
//最后这个函数来校验每个关卡的位置，是各个关卡都位于屏幕的中央
void  LevelScene::adjustScrollView(float offset)
{
	CCLOG("%d",m_nCurPage);
	//页数设置
	if (offset<0)
	{
		m_nCurPage++;
	}
	else if (offset>0)
	{
		m_nCurPage--;
	}
	
	//防止过界
	if (m_nCurPage<0)
	{
		m_nCurPage = 0;
	}
	else if (m_nCurPage >4)
	{
		m_nCurPage =4;
	}
	
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	
	CCPoint adjustPoint = ccp(-size.width * m_nCurPage , 0);
	
	//ScollView跳转页数
	m_scrollView->setContentOffsetInDuration(adjustPoint, 0.3f);
	
	
}





