//
//  GameScene.cpp
//  Xing
//
//  Created by Fangyuan Xing on 3/20/16.
//
//

#include "GameScene.hpp"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

bool GameScene::init()
{
    if(!Scene::init())
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("GameScene.csb");
    
    addChild(rootNode);
    
    return true;
}