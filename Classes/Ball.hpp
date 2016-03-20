//
//  Ball.hpp
//  Xing
//
//  Created by Fangyuan Xing on 3/20/16.
//
//

#ifndef Ball_hpp
#define Ball_hpp

#include <cocos2d.h>

class Ball : public cocos2d::Sprite
{
    int m_color;
    
public:
    
    CREATE_FUNC(Ball);
    virtual bool init() override;
    
    void setColor(int x);
    int getColor();
    
};

#endif /* Ball_hpp */
