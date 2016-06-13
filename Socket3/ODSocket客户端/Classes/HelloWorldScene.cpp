#include "HelloWorldScene.h"
USING_NS_CC;

#include "ODSocket/ODSocket.h"

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
	
	size = Director::getInstance()->getVisibleSize();
	
    connectServer();
	
	//MenuImage
	CCMenuItemImage *pMenuImage = CCMenuItemImage::create(
														  "CloseNormal.png",
														  "CloseSelected.png",
														  this,
														  menu_selector(HelloWorld::menuCloseCallback));
	
	
	// Menu
	CCMenu* pMenu = CCMenu::create(pMenuImage,NULL);
	pMenu->setPosition(ccp(size.width/2, size.height/2));
	this->addChild(pMenu);
	
    return true;
}


// Socker连接
void HelloWorld::connectServer()
{
    // 初始化
    socket.Init();
    socket.Create(AF_INET, SOCK_STREAM, 0);
    
    // 设置服务器的IP地址，端口号
    // 并连接服务器 Connect
    const char* ip = "127.0.0.1";
    int port = 12345;
    bool result = socket.Connect(ip, port);
	
	//是否连接成功
    if (result) {
        CCLOG("connect to server success!");
        // 开启新线程，在子线程中，接收数据
        std::thread recvThread = std::thread(&HelloWorld::receiveData, this);
        recvThread.detach(); // 从主线程分离
    }
    else {
        CCLOG("can not connect to server");
        return;
    }
}

// 接收数据
void HelloWorld::receiveData()
{
    // 因为是强联网
    // 所以可以一直检测服务端是否有数据传来
    while (true) {
		// 接收数据 Recv
        char data[512] = "";
        int result = socket.Recv(data, 512, 0);
        CCLOG("%d", result);
		
        // 与服务器的连接断开了
		if (result <= 0)
		{
			CCLOG("与服务器断开了！！");
			break;
		}
			
        CCLOG("客户端接收到数据：%s", data);
    }
    // 关闭连接
    socket.Close();
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
	
	socket.Send("login", 5);
}

