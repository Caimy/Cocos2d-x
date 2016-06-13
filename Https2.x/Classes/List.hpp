//
//  List.hpp
//  Cocos2dDEMO
//
//  Created by CMY on 16/5/10.
//
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;

class ListDelegate   //中间商
{
public:
	virtual void onMenu() = 0;
};



class  List
{
public:
	
	void Want()
	{
		//那个谁帮我处理下
		if (m_delegate)
			m_delegate->onMenu();
	}
	
	
	//发布需求
	CC_SYNTHESIZE(ListDelegate*, m_delegate, Delegate);
};





#endif /* List_hpp */
