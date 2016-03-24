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
#include "Common.h"

class Ball;

class Board : public cocos2d::Sprite
{
    
public:
    
    CREATE_FUNC(Board);
    
    virtual bool init() override;
    
    void generateBalls();
    
private:
    
    std::vector<std::vector<Ball *> > m_flags;
    
    bool addBall(int row, int col,Color color);
    
    bool removeBall(int row, int col);
    
    int generateInt(int smallest, int largest);
    
};


#endif /* Board_hpp */
