//
//  StartScene.cpp
//  Xing
//
//  Created by Fangyuan Xing on 10/10/16.
//
//

#include "StartScene.hpp"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameScene.hpp"
#include "UserData.hpp"
USING_NS_CC;

bool StartScene::init()
{
    if(!Scene::init())
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("StartScene.csb");
    addChild(rootNode);
    
    auto startPlay = static_cast<ui::Button *>(rootNode -> getChildByName("play_button"));
    
    startPlay -> addTouchEventListener([](Ref* pSender, ui::Widget::TouchEventType type){
        switch(type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
                
            case ui::Widget::TouchEventType::ENDED:
                
                log("pressed");
                Director::getInstance() -> replaceScene(GameScene::create());
                break;
                
            default:
                break;
        }
    });
    
    auto highestScore = static_cast<ui::Text *>(rootNode -> getChildByName("score_label"));
    
    highestScore -> setString(std::to_string(UserData::getInstance() -> getHighestScore()));
    
    return true;
}