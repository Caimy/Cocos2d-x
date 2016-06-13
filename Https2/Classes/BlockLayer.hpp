//
//  BlockLayer.hpp
//  Cocos2dDEMO
//
//  Created by CMY on 16/6/7.
//
//

#ifndef BlockLayer_hpp
#define BlockLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class BlockLayer : public CCLayerColor
{
public:
	virtual bool init();
	
	void initData();
	
	void onMenuClick_Test(CCObject* pSender);
	
	void registerWithTouchDispatcher( void );
	
	virtual bool ccTouchBegan( CCTouch *pTouches, CCEvent *pEvent );
	
	virtual void ccTouchMoved( CCTouch *pTouches, CCEvent *pEvent );
	
	virtual void ccTouchEnded( CCTouch *pTouches, CCEvent *pEvent );
	
	CREATE_FUNC(BlockLayer);
};

#endif /* BlockLayer_hpp */
