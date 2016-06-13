#include "TestLayer.h"
using namespace std;

TestLayer::TestLayer(void)
{
}


TestLayer::~TestLayer(void)
{
}

bool TestLayer::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		CCSize visibleSize=CCDirector::sharedDirector()->getVisibleSize();
		
		//username editbox
		p_User_EditBox = CCEditBox::create(CCSizeMake(250,50), CCScale9Sprite::create("login_edit_normal.9.png"));
		p_User_EditBox->setPosition(ccp(visibleSize.width/2, visibleSize.height*3/4));
		p_User_EditBox->setFontColor(ccBLUE);
		p_User_EditBox->setPlaceHolder("Username");
		p_User_EditBox->setMaxLength(12);
		p_User_EditBox->setInputMode(kEditBoxInputModeAny);
		p_User_EditBox->setReturnType(kKeyboardReturnTypeDone);
		addChild(p_User_EditBox);

		//password editbox
		p_Psw_EditBox = CCEditBox::create(CCSizeMake(250,50), CCScale9Sprite::create("login_edit_normal.9.png"));
		p_Psw_EditBox->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
		p_Psw_EditBox->setFontColor(ccRED);
		p_Psw_EditBox->setPlaceHolder("Password");
		p_Psw_EditBox->setMaxLength(12);
		p_Psw_EditBox->setInputMode(kEditBoxInputModeAny);
		p_Psw_EditBox->setInputFlag(kEditBoxInputFlagPassword);
		p_Psw_EditBox->setReturnType(kKeyboardReturnTypeDone);
		addChild(p_Psw_EditBox);

		CCScale9Sprite* confirmnormal=CCScale9Sprite::create("btn_style_alert_dialog_button_normal.9.png");
		confirmnormal->setContentSize(CCSizeMake(100,60));
		CCScale9Sprite* confirmpressd=CCScale9Sprite::create("btn_style_alert_dialog_button_pressed.9.png");
		confirmpressd->setContentSize(CCSizeMake(100,60));
		CCMenuItemSprite* menuitem=CCMenuItemSprite::create(confirmnormal,confirmpressd,this,menu_selector(TestLayer::btncallback));
		CCMenu* menu=CCMenu::create(menuitem,NULL);
		menu->setPosition(visibleSize.width/2-85,visibleSize.height/4);
		this->addChild(menu);

		m_labelStatusCode = CCLabelTTF::create("HTTP Status Code", "Marker Felt", 20);
		m_labelStatusCode->setAnchorPoint(ccp(0,0.5));
		m_labelStatusCode->setPosition(ccp(visibleSize.width/2,visibleSize.height/4));
		m_labelStatusCode->setColor(ccc3(255,0,0));
		addChild(m_labelStatusCode);
		m_labelStatusCode->setString("waiting...");

		bRet=true;

	} while (0);
	return bRet;
}

void TestLayer::btncallback( CCObject* pSender )
{
	bool requestType_is_get=true;//采用get方式或者post方式
	if (requestType_is_get)
	{
		CCHttpRequest* request = new CCHttpRequest();//创建请求对象
		string str1 = "127.0.0.1:80/index.html?";
		string str2 = p_User_EditBox->getText();//获取username编辑框内容
		string str3 = p_Psw_EditBox->getText();//获取password编辑框内容
		string struser="username=";
		string strpsw="&password=";
		str1=str1+struser+str2+strpsw+str3;
		request->setUrl(str1.c_str());//设置请求的url，username和password已经包含在url中
		request->setRequestType(CCHttpRequest::kHttpGet);//设置为Get模式
		request->setResponseCallback(this, httpresponse_selector(TestLayer::onHttpRequestCompleted));//设置响应的回调
		request->setTag("GET test");
		CCHttpClient::getInstance()->send(request);//发送请求
		request->release();//释放请求
	}
	else
	{
		CCHttpRequest* request = new CCHttpRequest();//创建请求对象
		string str1 = "127.0.0.1:80/index.html";
		string str2 = p_User_EditBox->getText();
		string str3 = p_Psw_EditBox->getText();
		string struser="username=";
		string strpsw="&password=";
		str2=struser+str2+strpsw+str3;
  
		request->setUrl(str1.c_str());//设置请求的url，只是请求页面的url，并不包含username和password
		request->setRequestType(CCHttpRequest::kHttpPost);//设置为Post模式
		request->setResponseCallback(this, httpresponse_selector(TestLayer::onHttpRequestCompleted));//设置响应的回调
  
		const char* postData = str2.c_str();
		request->setRequestData(postData, strlen(postData));//设置请求数据，也就是username和password
		
		request->setTag("POST test");
		CCHttpClient::getInstance()->send(request);//发送请求
		request->release();//释放请求
	}
}

void TestLayer::onHttpRequestCompleted( CCHttpClient* client, CCHttpResponse* response )
{
	if (!response->isSucceed())//如果响应失败，输出错误信息
	{
		CCString strError;
		strError.initWithFormat("Receive Error! \n%s\n",response->getErrorBuffer());
		m_labelStatusCode->setString(strError.getCString());
		return ;
	}
	
	std::vector<char> *buffer = response->getResponseData();//接收响应信息
	string recieveData;
	for (unsigned int i = 0; i < buffer->size(); i++)
	{
		recieveData += (*buffer)[i];
	}
	size_t begin= recieveData.find("<body>")+6;//这里简单处理，获取<body>标签内数据，即是响应内容
	size_t end= recieveData.find("</body>");
	string result(recieveData,begin,end-begin);
	m_labelStatusCode->setString(result.c_str());
}

