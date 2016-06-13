#include "TestScene.h"

CTestScene::CTestScene(void)
{
}


CTestScene::~CTestScene(void)
{
}

bool CTestScene::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCScene::init());

		_testLayer=TestLayer::create();
		this->addChild(_testLayer);

		bRet=true;
	} while (0);
	return bRet;
}