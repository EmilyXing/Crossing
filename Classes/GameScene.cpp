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
#include "Board.hpp"
#include "Common.h"

USING_NS_CC;

bool GameScene::init()
{
    if(!Scene::init())
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("GameScene.csb");
    addChild(rootNode);
    
    auto board = Board::create();
    
    board -> setPosition(480,320); // 分辨率是960,640 相当于把board放中间
    
    rootNode -> addChild(board);
    
    board -> generateBalls();
    
    return true;
}