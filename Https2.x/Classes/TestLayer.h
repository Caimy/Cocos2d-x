#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class TestLayer :
	public CCLayer
{
public:
	TestLayer(void);
	~TestLayer(void);

	CREATE_FUNC(TestLayer);

	virtual bool init();

	CCEditBox* p_User_EditBox;
	CCEditBox* p_Psw_EditBox;

	void btncallback(CCObject* pSender);

	void onHttpRequestCompleted(CCHttpClient* client, CCHttpResponse* response);

	CCLabelTTF* m_labelStatusCode;
};

