//
//  GameScene.cpp
//  Xing
//
//  Created by Fangyuan Xing on 3/20/16.
//
//

#include "GameScene.hpp"
#include "EndScene.hpp"
#include "UserData.hpp"
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
    
    m_score = 0;
    
    auto rootNode = CSLoader::createNode("GameScene.csb");
    addChild(rootNode);
    
    auto board = Board::create();
    
    board -> setPosition(320,480); // 分辨率是640,960 相当于把board放中间
    
    rootNode -> addChild(board);
    
    board -> generateBalls();
    
    
    // 设置onDeleted回调函数
    board -> m_onDeleted = [&,rootNode]() {
        
        m_score++;
        
        auto currentScore = static_cast<ui::Text *>(rootNode -> getChildByName("current_score_label"));
        
        currentScore -> setString(std::to_string(m_score));
    };
    
    
    // 设置isOver回调函数
    board -> m_isOver = [&](){
        
        UserData::getInstance() -> setLastScore(m_score);
        Director::getInstance() -> replaceScene(EndScene::create());
    };
    
    
    return true;
}
