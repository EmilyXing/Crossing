//
//  EndScene.cpp
//  Xing
//
//  Created by Fangyuan Xing on 10/10/16.
//
//

#include "EndScene.hpp"
#include "UserData.hpp"
#include "GameScene.hpp"
#include "StartScene.hpp"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

bool EndScene::init()
{
    if(!Scene::init())
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("EndScene.csb");
    addChild(rootNode);
    
    // hihgest score and last score
    auto highestScore = static_cast<ui::Text *>(rootNode -> getChildByName("highest_score_label"));
    auto lastScore = static_cast<ui::Text *>(rootNode -> getChildByName("current_score_label"));
    
    lastScore -> setString(std::to_string(UserData::getInstance() -> getLastScore()));
    highestScore -> setString(std::to_string(UserData::getInstance() -> getHighestScore()));
    
    
    // restart button
    auto restartPlay = static_cast<ui::Button *>(rootNode -> getChildByName("restart_button"));
    
    restartPlay -> addTouchEventListener([](Ref* pSender, ui::Widget::TouchEventType type){
        switch(type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
                
            case ui::Widget::TouchEventType::ENDED:
                
                Director::getInstance() -> replaceScene(GameScene::create());
                break;
                
            default:
                break;
        }
    });
    
    // home button
    auto returnHome = static_cast<ui::Button *>(rootNode -> getChildByName("home_button"));
    
    returnHome -> addTouchEventListener([](Ref* pSender, ui::Widget::TouchEventType type){
        switch(type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
                
            case ui::Widget::TouchEventType::ENDED:
                
                Director::getInstance() -> replaceScene(StartScene::create());
                break;
                
            default:
                break;
        }
    });

    
    return true;
}