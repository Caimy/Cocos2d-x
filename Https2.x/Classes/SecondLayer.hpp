//
//  SecondLayer.hpp
//  Cocos2dDEMO
//
//  Created by CMY on 16/5/9.
//
//

#ifndef SecondLayer_hpp
#define SecondLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;

typedef void (CCObject::*SEL_CMY)();

#define menu_selector_CMY(_SELECTOR) (SEL_CMY)(&_SELECTOR)

class SecondLayer : public CCLayer
{
public:
	
	virtual bool init();
	
	virtual void ccTouchesBegan( CCSet *pTouches, CCEvent *pEvent );
	
	virtual void ccTouchesMoved( CCSet *pTouches, CCEvent *pEvent );
	
	virtual void ccTouchesEnded( CCSet *pTouches, CCEvent *pEvent );
	
	virtual void ccTouchesCancelled( CCSet *pTouches, CCEvent *pEvent );
	
	void updateOnce(float x);
	
//	virtual void registerWithTouchDispatcher( void );
	
	CREATE_FUNC(SecondLayer);
	
private:
};


#endif /* SecondLayer_hpp */
