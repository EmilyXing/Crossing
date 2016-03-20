//
//  GameScene.hpp
//  Xing
//
//  Created by Fangyuan Xing on 3/20/16.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <cocos2d.h>

class GameScene : public cocos2d::Scene
{
public:
    CREATE_FUNC(GameScene);
    
    virtual bool init() override;
};

#endif /* GameScene_hpp */

