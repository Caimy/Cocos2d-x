//
//  LevelScene.hpp
//  Cocos2dDEMO
//
//  Created by CMY on 16/5/11.
//
//

#ifndef LevelScene_hpp
#define LevelScene_hpp

#include <stdio.h>
#include <cocos2d.h>
#include <cocos-ext.h>
USING_NS_CC;
USING_NS_CC_EXT;

class LevelScene : public CCLayer
{
public:
	bool init();
	CREATE_FUNC(LevelScene);
	//以下是注册触摸事件和实现各种的touch函数
	virtual void registerWithTouchDispatcher();
	bool ccTouchBegan(CCTouch * touch,CCEvent * pEvent);
	void ccTouchMoved(CCTouch * touch,CCEvent * pEvent);
	void ccTouchEnded(CCTouch * touch,CCEvent * pEvent);
	//最后这个函数来校验每个关卡的位置，是各个关卡都位于屏幕的中央
	void  adjustScrollView(float offset);
private:
	//将CCScrollView作为自己的层添加进来
	CCScrollView * m_scrollView;
	//触摸点的位置
	CCPoint m_touchPoint;
	//CCScrollView的便宜量
	CCPoint m_offsetPoint;
	//当前为第几个关卡
	int m_nCurPage;
};


#endif /* LevelScene_hpp */
