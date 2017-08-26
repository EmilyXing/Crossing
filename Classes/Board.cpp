//
//  Board.cpp
//  Xing
//
//  Created by Fangyuan Xing on 3/20/16.
//
//

#include "EndScene.hpp"
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
    // 获取相当于board的坐标
    auto localPosition = this->convertToNodeSpace(location);
    
    int row = localPosition.y / GRID_SIZE;
    int col = localPosition.x / GRID_SIZE;
    
    map<Color,vector<Vec2>> balls = hasSameColorBall(row, col);
    
    bool flag = true;
    
    for(auto a : balls)
    {
        if(a.second.size() >= 2)
        {
            flag = false;
            
            for(auto p : a.second)
            {
                removeBall(p.x, p.y);
            }
        }
    }
    
    // 每次touch 判断game是否要结束
    
    if(isGameover() && m_isOver)
    {
        log("game over");
        m_isOver();
    }
    
    // if(flag) CCLOG("wrong touch");
}

std::map<Color,std::vector<cocos2d::Vec2>> Board::hasSameColorBall(int row, int col)
{
    map<Color,std::vector<cocos2d::Vec2>> balls;

    for(int i = row - 1; i >= 0; i--)
    {
        if(m_flags[i][col] && !m_flags[i][col] -> isDeleted())
        {
            balls[m_flags[i][col] -> getColor()].push_back(Vec2(i,col));
            break;
        }
    }
    
    for(int i = row + 1; i < BOARD_SIZE; i++)
    {
        if(m_flags[i][col] && !m_flags[i][col] -> isDeleted())
        {
            balls[m_flags[i][col] -> getColor()].push_back(Vec2(i, col));
            break;
        }
    }
    
    for(int i = col - 1; i >= 0; i--)
    {
        if(m_flags[row][i] && !m_flags[row][i] -> isDeleted())
        {
            balls[m_flags[row][i] -> getColor()].push_back(Vec2(row, i));
            break;
        }
    }
    
    for(int i = col + 1; i < BOARD_SIZE; i++)
    {
        if(m_flags[row][i] && !m_flags[row][i] -> isDeleted())
        {
            balls[m_flags[row][i] -> getColor()].push_back(Vec2(row, i));
            break;
        }
    }
    
    return balls;
}

bool Board::isGameover()
{
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(m_flags[i][j] && !m_flags[i][j] -> isDeleted()) // 这个位置有球并且这个球的状态稳定 没有正在deleting
            {
                continue;
            }
            
            std::map<Color,std::vector<cocos2d::Vec2>> current = hasSameColorBall(i, j);
            
            for(auto a : current)
            {
                if(a.second.size() >= 2)
                {
                    return false;
                }
            }
        }
    }
    
    return true;
}

void Board::removeBall(int row, int col)
{

    // log("delete a ball with color %d", m_flags[row][col] -> getColor());
    
    m_flags[row][col] -> setDeleted(true);
    
    auto pos = m_flags[row][col]->getPosition();
    
    auto moveUp = MoveBy::create(0.1, Vec2(0,50)); // ball在0.1秒内上移50个point
    
    auto easeMoveUp = EaseIn::create(moveUp, 0.3); // 加速度
    
    auto moveDown = MoveTo::create((pos.y + GRID_SIZE) / 1000, Vec2(pos.x, - GRID_SIZE / 2));
    
    auto easeMoveDown = EaseOut::create(moveDown, 0.3);
    
    auto fadeOut = FadeOut::create((pos.y+GRID_SIZE)/500.0f);
    
    auto downAndFadeOut = Spawn::createWithTwoActions(easeMoveDown, fadeOut);
    
    auto removeSelfFunc = CallFunc::create([=]() // &:表示这个函数里引用的变量都是外面这个函数的 =:值传递 复制
    {
        this -> m_flags[row][col] -> removeFromParent();
        
        this -> m_flags[row][col] = nullptr;
    });
    
    auto seq = Sequence::create(easeMoveUp, downAndFadeOut, removeSelfFunc,nullptr);
    
    m_flags[row][col]->runAction(seq);
    
    // 回调函数
    if (m_onDeleted)
    {
        m_onDeleted();
    }

}

int Board::generateInt(int smallest, int largest)
{
    return arc4random() % (largest - smallest + 1) + smallest;
}


void Board::addBall(int row, int col, Color color)
{
    
    float x = col * GRID_SIZE + GRID_SIZE/2;
    float y = row * GRID_SIZE + GRID_SIZE/2;
    
    auto ball = Ball::create();
    
    ball -> setColor(color);
    
    this -> addChild(ball);
    
    ball -> setPosition(x, y);
    
    m_flags[row][col] = ball;

}

void Board::generateBalls()
{
    int count = 30; // 给board上加30个球
    
    while(count > 0)
    {
        int v1 = generateInt(0,7); // 随机选位置
        int v2 = generateInt(0,7);
        Color color = (Color)generateInt(1,5); // 随机选颜色
        
        if(!m_flags[v1][v2]) // 如果当前没有球 造一个
        {
            addBall(v1, v2, color);
            count--;
        }
        
        // CCLOG("v1 = %d v2 = %d color = %d", v1,v2,color);
    }
}


