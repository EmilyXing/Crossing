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
USING_NS_CC;
using namespace std;

bool Board::init()
{
    if(!Sprite::initWithFile("assets/board.png"))
    {
        return false;
    }
    
    vector<vector<Ball *>> temp(8,vector<Ball *>(8,nullptr));
    
    m_flags = temp;
    
    return true;
}

bool Board::addBall(int row, int col, Color color)
{
    if(m_flags[row][col])
    {
        return false;
    }
    
    float x = col * 80 + 40;
    float y = row * 80 + 40;
    
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
    
    m_flags[row][col] -> removeFromParent();
    
    m_flags[row][col] = nullptr;
    
    return true;
}

int Board::generateInt(int smallest, int largest)
{
    return arc4random() % (largest - smallest + 1) + smallest;
}

void Board::generateBalls()
{
    int count = 10; // 给board上加10个球
    
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