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
#include "Ball.hpp"

USING_NS_CC;

bool GameScene::init()
{
    if(!Scene::init())
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("GameScene.csb");
    
    addChild(rootNode);
    
    
    auto greenBall = Ball::create();
    
    greenBall -> setColor(2);
    
    rootNode -> addChild(greenBall);
    
    greenBall -> setPosition(Vec2(300, 300));
    
    auto orangeBall = Ball::create();
    
    orangeBall -> setColor(4);
    
    rootNode -> addChild(orangeBall);
    
    orangeBall -> setPosition(300,300);
    
    return true;
}