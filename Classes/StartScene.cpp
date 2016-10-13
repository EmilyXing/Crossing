//
//  StartScene.cpp
//  Xing
//
//  Created by Fangyuan Xing on 10/10/16.
//
//

#include "StartScene.hpp"

bool StartScene::init()
{
    if(!Scene::init())
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("StartScene.csb");
    addChild(rootNode);
    
    auto logo = Label::createWithTTF("Xing", "ttf_from_ue.ttf", 24);
    
    
    return true;
}