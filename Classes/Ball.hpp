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
    
    bool isDeleted();
    void setDeleted(bool);
    
private:
    Color m_color;
    bool m_deleted;
};

#endif /* Ball_hpp */
