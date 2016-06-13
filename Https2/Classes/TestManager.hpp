//
//  TestManager.hpp
//  Cocos2dDEMO
//
//  Created by CMY on 16/5/10.
//
//

#ifndef TestManager_hpp
#define TestManager_hpp

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;


class TestManager
{
public:
	TestManager* getInstance()
	{
		if (m_Instance == NULL)
		{
			m_Instance = new TestManager();
			
			//静态数据
			m_data = new CCDictionary();
			
			//非静态数据 取对象获取
			//		CCDictionary* data = m_Instance->m_data;
			//		data = new CCDictionary();
		}
		
		return  m_Instance;
	}

	
	//添加
	void addItem(const std::string& str, CCObject* obj)
	{
		m_data->setObject(obj, str);
	}
	
	
	//获取
	CCObject* getItem(const std::string& str)
	{
		return m_data->objectForKey(str);
	}
	
	
	//移除单例
	void removeInstance()
	{
		CC_SAFE_DELETE(m_Instance);
		CC_SAFE_RELEASE_NULL(m_data);
	}
	

private:
	static TestManager* m_Instance;
	
	static CCDictionary* m_data;
	
};

CCDictionary* TestManager::m_data = NULL;
TestManager* TestManager::m_Instance = NULL;

#endif /* TestManager_hpp */
