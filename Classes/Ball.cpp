//
//  Ball.cpp
//  Xing
//
//  Created by Fangyuan Xing on 3/20/16.
//
//

#include <string>
#include <iostream>
#include "Ball.hpp"
using namespace std;

bool Ball::init()
{
    if(!Sprite::init())
    {
        return false;
    }
    
    m_color = 1;
    
    return true;
}

void Ball::setColor(int x)
{
    m_color = x;
    
    string name = "assets/ball" + to_string(m_color) + ".png";
    
    setTexture(name);
}

int Ball::getColor()
{
    return m_color;
}