//
//  GameScene.cpp
//  HelloCpp
//
//  Created by Brandon Scott Jones on 11/23/13.
//
//

#include "GameScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(GameScene::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Game Scene", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    auto winButton = MenuItemImage::create("Win_Button.png", "Win_Button.png", CC_CALLBACK_1(GameScene::WinButtonCallback, this));
    
    winButton->setPosition(visibleSize.width * 0.3f + origin.x, visibleSize.height * 0.5f + origin.y);
    
    auto winButtonMenu = Menu::create(winButton, nullptr);
    winButtonMenu->setPosition(0, 0);
    
    this->addChild(winButtonMenu, 1);
    
    auto loseButton = MenuItemImage::create("Lose_Button.png", "Lose_Button.png", CC_CALLBACK_1(GameScene::LoseButtonCallback, this));
    
    loseButton->setPosition(visibleSize.width * 0.7f + origin.x, visibleSize.height * 0.5f + origin.y);
    
    auto loseButtonMenu = Menu::create(loseButton, nullptr);
    loseButtonMenu->setPosition(0, 0);
    
    this->addChild(loseButtonMenu, 1);
    
    return true;
}

void GameScene::WinButtonCallback(Object* pSender)
{
    this->removeAllChildren();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto label = LabelTTF::create("You Win!", "Arial", 24);
    
    label->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + (visibleSize.height * 0.75f) - label->getContentSize().height));
    
    this->addChild(label, 2);
    

    auto retryButton = MenuItemImage::create("Retry_Button.png", "Retry_Button.png", CC_CALLBACK_1(GameScene::RetryButtonCallback, this));
    
    retryButton->setPosition(visibleSize.width * 0.5f + origin.x, visibleSize.height * 0.5f + origin.y);
    
    auto retryButtonMenu = Menu::create(retryButton, nullptr);
    retryButtonMenu->setPosition(0, 0);
    
    this->addChild(retryButtonMenu, 2);
}

void GameScene::LoseButtonCallback(Object* pSender)
{
    this->removeAllChildren();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto label = LabelTTF::create("You Lose...", "Arial", 24);
    
    label->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + (visibleSize.height * 0.75f) - label->getContentSize().height));
    
    this->addChild(label, 2);
    
    
    auto retryButton = MenuItemImage::create("Retry_Button.png", "Retry_Button.png", CC_CALLBACK_1(GameScene::RetryButtonCallback, this));
    
    retryButton->setPosition(visibleSize.width * 0.5f + origin.x, visibleSize.height * 0.5f + origin.y);
    
    auto retryButtonMenu = Menu::create(retryButton, nullptr);
    retryButtonMenu->setPosition(0, 0);
    
    this->addChild(retryButtonMenu, 2);
}

void GameScene::RetryButtonCallback(Object* pSender)
{
    Director::getInstance()->pushScene(HelloWorld::createScene());
}

void GameScene::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}