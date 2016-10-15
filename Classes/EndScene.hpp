//
//  EndScene.hpp
//  Xing
//
//  Created by Fangyuan Xing on 10/10/16.
//
//

#ifndef EndScene_hpp
#define EndScene_hpp


#include <stdio.h>
#include <cocos2d.h>
#include "ui/CocosGUI.h"

class EndScene : public cocos2d::Scene
{
public:
    
    CREATE_FUNC(EndScene);
    
    virtual bool init() override;
};


#endif /* EndScene_hpp */
