//
//  LoadScene.hpp
//  Cocos2dDEMO
//
//  Created by CMY on 16/5/10.
//
//

#ifndef LoadScene_hpp
#define LoadScene_hpp

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;

class LoadScene : public CCLayer
{
public:
	void onEnter();
	
	void onExit();
	
	virtual bool init();
	
	void HandleMsg(CCObject* obj);
	
	static cocos2d::CCScene* scene();
	
	CREATE_FUNC(LoadScene);
	
	//异步加载图片调用的函数
	void loadingCallBack(CCObject * object);
private:
	//设置加载图片的总数
	int m_totalNum;
	//以加载图片的数量
	int m_loadedNum;
	//俩个文本信息
	CCLabelTTF * m_labelLoading;
	CCProgressTimer * m_progress;

};


#endif /* LoadScene_hpp */
