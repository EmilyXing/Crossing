//
//  StartScene.hpp
//  Xing
//
//  Created by Fangyuan Xing on 10/10/16.
//
//

#ifndef StartScene_hpp
#define StartScene_hpp

#include <stdio.h>
#include <cocos2d.h>

class StartScene : public cocos2d::Scene
{
public:
    CREATE_FUNC(StartScene);
    
    virtual bool init() override;
};


#endif /* StartScene_hpp */
