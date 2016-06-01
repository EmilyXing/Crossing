//
//  Board.cpp
//  Xing
//
//  Created by Fangyuan Xing on 3/20/16.
//
//

#include "Board.hpp"
#include "Ball.hpp"
#include <stdlib.h>
#include <map>
USING_NS_CC;
using namespace std;

bool Board::init()
{
    if(!Sprite::initWithFile("assets/board.png")) // 640 * 640
    {
        return false;
    }
    
    setupTouchEvents();
    
    vector<vector<Ball *>> temp(8,vector<Ball *>(8,nullptr));
    
    m_flags = temp;
    
    return true;
}

void Board::setupTouchEvents()
{
    auto listener = EventListenerTouchOneByOne::create();
    
    
    listener -> onTouchBegan = [this](Touch* touch, Event* event)
    {
        // for test
        //CCLOG("on touch began");
        
        // get到touch的那个点的坐标
        auto location = touch -> getLocation();
        // rect得到的是board的范围
        auto rect = this -> getBoundingBox();
        
        // 判断touch的点在不在board之中  如果在board范围里 board做出处理
        if(rect.containsPoint(location))
        {
            // return true means swallow 底下的sence不会再收到touch event
            return true;
        }
        
        return false;
    };
    
    listener -> onTouchEnded = [this](Touch* touch, Event* event)
    {
        auto location = touch -> getLocation();
        auto rect = this -> getBoundingBox();
        
        if(rect.containsPoint(location))
        {
            this -> processTouch(location);
        }
        
    };
    
    // 把listener加入到当前的事件处理机制中
    _eventDispatcher -> addEventListenerWithSceneGraphPriority(listener, this);
}

void Board::processTouch(Vec2 location)
{
    //获取窗口大小
    //Size windowSize = Director::getInstance()->getWinSize();
//    int row = location.y / GRID_SIZE;
//    int col = (location.x - (windowSize.width - windowSize.height)/2) / GRID_SIZE;
    
    // 获取相当于board的坐标
    auto localPosition = this->convertToNodeSpace(location);
    
    int row = localPosition.y / GRID_SIZE;
    int col = localPosition.x / GRID_SIZE;
    
    map<Color,vector<pair<int,int>>> balls;
    
    //
    for(int i = row - 1; i >= 0; i--)
    {
        if(m_flags[i][col])
        {
            balls[m_flags[i][col] -> getColor()].push_back(make_pair(i,col));
            break;
        }
    }
    
    for(int i = row + 1; i < BOARD_SIZE; i++)
    {
        if(m_flags[i][col])
        {
            balls[m_flags[i][col] -> getColor()].push_back(make_pair(i, col));
            break;
        }
    }
    
    for(int i = col - 1; i >= 0; i--)
    {
        if(m_flags[row][i])
        {
            balls[m_flags[row][i] -> getColor()].push_back(make_pair(row, i));
            break;
        }
    }
    
    for(int i = col + 1; i < BOARD_SIZE; i++)
    {
        if(m_flags[row][i])
        {
            balls[m_flags[row][i] -> getColor()].push_back(make_pair(row, i));
            break;
        }
    }

    bool flag = true;
    
    for(auto& a : balls)
    {
        if(a.second.size() >= 2)
        {
            flag = false;
            for(auto& p : a.second)
            {
                removeBall(p.first, p.second);
            }
        }
    }
    
    if(flag) CCLOG("wrong touch");
}


bool Board::addBall(int row, int col, Color color)
{
    if(m_flags[row][col])
    {
        return false;
    }
    
    float x = col * GRID_SIZE + GRID_SIZE/2;
    float y = row * GRID_SIZE + GRID_SIZE/2;
    
    auto ball = Ball::create();
    ball -> setColor(color);
    
    addChild(ball);
    
    ball -> setPosition(x, y);
    
    m_flags[row][col] = ball;
    
    return true;
}

bool Board::removeBall(int row, int col)
{
    if(!m_flags[row][col])
    {
        return false;
    }
    
    auto pos = m_flags[row][col]->getPosition();
    
    auto moveUp = MoveTo::create(0.1, Vec2(pos.x, pos.y + GRID_SIZE));
    
    auto easeMoveUp = EaseIn::create(moveUp, 0.3);
    
    auto moveDown = MoveTo::create((pos.y + GRID_SIZE) / 1000,Vec2(pos.x, - GRID_SIZE / 2));
    
    auto easeMoveDown = EaseOut::create(moveDown, 0.3);
    
    auto removeSelfFunc = CallFunc::create([=](){ // &:表示这个函数里引用的变量都是外面这个函数的 =:值传递 复制
        
        this->m_flags[row][col] -> removeFromParent();
        
        this->m_flags[row][col] = nullptr;
    });
    
    auto seq = Sequence::create(easeMoveUp, easeMoveDown, removeSelfFunc,nullptr);
    
    m_flags[row][col]->runAction(seq);
    
    return true;
}

int Board::generateInt(int smallest, int largest)
{
    return arc4random() % (largest - smallest + 1) + smallest;
}

void Board::generateBalls()
{
    int count = 30; // 给board上加10个球
    
    while(count > 0)
    {
        int v1 = generateInt(0,7);
        int v2 = generateInt(0,7);
        Color color = (Color)generateInt(1,5);
        
        if(!m_flags[v1][v2])
        {
            addBall(v1, v2, color);
            count--;
        }
        
        CCLOG("v1 = %d v2 = %d color = %d", v1,v2,color);
    }
}