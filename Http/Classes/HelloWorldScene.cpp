// V3.4
#include "HelloWorldScene.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() ) return false;
    
    onHttpRequest("get");
    CCLOG("----------------------------");
//    onHttpRequest("post");
	
    return true;
}


// 发送HTTP请求
void HelloWorld::onHttpRequest(std::string type)
{
    // 创建HTTP请求
    HttpRequest* request = new HttpRequest();
    
    if (type == "get")
    {
		//请求方式
        request->setRequestType(HttpRequest::Type::GET);
        // url后面附加数据信息
        request->setUrl("http://127.0.0.1:80/index.html");
    }
    else if(type == "post")
    {
        request->setRequestType(HttpRequest::Type::POST);
        request->setUrl("http://httpbin.org/post");
        // 设置post发送请求的数据信息
        std::string data = "hello world!";
        request->setRequestData(data.c_str(), data.length());
    }
    
    // HTTP响应函数
    request->setResponseCallback(CC_CALLBACK_2(HelloWorld::onHttpResponse, this));
    
    // 发送请求
    HttpClient::getInstance()->send(request);
    
    // 释放链接
    request->release();
}


// HTTP响应请求函数
void HelloWorld::onHttpResponse(HttpClient* sender, HttpResponse* response)
{
	if (!response->isSucceed())//如果响应失败，输出错误信息
	{
		CCString strError;
		strError.initWithFormat("Receive Error! \n%s\n",response->getErrorBuffer());
		CCLOG("%s",strError.getCString());
		return ;
	}
	
	std::vector<char> *buffer = response->getResponseData();//接收响应信息
	std::string recieveData;
	for (unsigned int i = 0; i < buffer->size(); i++)
	{
		recieveData += (*buffer)[i];
	}
	size_t begin= recieveData.find("<body>")+6;//这里简单处理，获取<body>标签内数据，即是响应内容
	size_t end= recieveData.find("</body>");
	std::string result(recieveData,begin,end-begin);
	CCLOG("%s",result.c_str());
}

