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
#include "Common.h"

class Ball : public cocos2d::Sprite
{
public:
    
    CREATE_FUNC(Ball);
    virtual bool init() override;
    
    void setColor(Color color);
    Color getColor();
    
private:
    Color m_color;
};

#endif /* Ball_hpp */
