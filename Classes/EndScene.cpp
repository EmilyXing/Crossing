//
//  EndScene.cpp
//  Xing
//
//  Created by Fangyuan Xing on 10/10/16.
//
//

#include "EndScene.hpp"
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
    
//    auto highestScore = static_cast<ui::Text *>(rootNode -> getChildByName("score_label"));
//    
//    highestScore -> setString(std::to_string(UserData::getInstance() -> getHighestScore()));
    
    return true;
}