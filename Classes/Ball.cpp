//
//  Ball.cpp
//  Xing
//
//  Created by Fangyuan Xing on 3/20/16.
//
//

#include <string>
#include "Ball.hpp"
using namespace std;

bool Ball::init()
{
    if(!Sprite::init())
    {
        return false;
    }
    
    m_color = Color::blue;
    
    return true;
}

void Ball::setColor(Color color)
{
    m_color = color;
    
    string name = "assets/ball" + to_string(m_color) + ".png";
    
    //CCLOG("name = %s", name.c_str());
    
    setTexture(name);
}

Color Ball::getColor()
{
    return m_color;
}

bool Ball::isDeleted()
{
    return m_deleted;
}
void Ball::setDeleted(bool deleted)
{
    m_deleted = deleted;
}