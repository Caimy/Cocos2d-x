//
//  UI.hpp
//  Cocos2dDEMO
//
//  Created by CMY on 16/5/10.
//
//

#ifndef UI_hpp
#define UI_hpp

#include <stdio.h>
#include "List.hpp"

class UI : ListDelegate  //这需求可以做
{
public:
	
	UI()
	{
		List* list = new List();
		list->setDelegate(this); //指定要做这个需求
		list->Want();
	}
	
	void onMenu()
	{
		CCLOG("帮你做好了");
	}
};



#endif /* UI_hpp */
