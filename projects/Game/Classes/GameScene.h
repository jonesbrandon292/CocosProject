//
//  GameScene.h
//  HelloCpp
//
//  Created by Brandon Scott Jones on 11/23/13.
//
//

#ifndef __HelloCpp__GameScene__
#define __HelloCpp__GameScene__

#include "cocos2d.h"

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(Object* pSender);
    
    void WinButtonCallback(Object* pSender);
    
    void LoseButtonCallback(Object* pSender);
    
    void RetryButtonCallback(Object* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
};

#endif /* defined(__HelloCpp__GameScene__) */




