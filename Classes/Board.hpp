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
    
    // 生成一个create方法
    CREATE_FUNC(Board);
    
    virtual bool init() override;
    
    void generateBalls();
    
public:
    // 处理消除后的回调函数指针：返回值是void，参数一个void
    std::function<void(void)> m_onDeleted;
    
private:
    
    std::vector<std::vector<Ball *> > m_flags;
    
    bool addBall(int row, int col, Color color);
    
    bool removeBall(int row, int col);
    
    int generateInt(int smallest, int largest);
    
    void setupTouchEvents();
    
    void processTouch(cocos2d::Vec2);
    
    bool isGameover();
    
    bool hasSameColorBall(int, int);
    
};


#endif /* Board_hpp */
