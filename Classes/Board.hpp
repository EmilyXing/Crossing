//
//  Board.hpp
//  Xing
//
//  Created by Fangyuan Xing on 3/20/16.
//
//

#ifndef Board_hpp
#define Board_hpp

#include <cocos2d.h>
#include <vector>

class Ball;

class Board : public cocos2d::Sprite
{
    std::vector<std::vector<Ball *> > m_flags;
public:
    
    CREATE_FUNC(Board);
    
    virtual bool init() override;
    
    bool addBall(int row, int col, int color);
    
    bool removeBall(int row, int col);
    
};


#endif /* Board_hpp */
