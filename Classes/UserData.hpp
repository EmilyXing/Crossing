//
//  UserData.hpp
//  Xing
//
//  Created by Fangyuan Xing on 10/11/16.
//
//

#ifndef UserData_hpp
#define UserData_hpp

#include <stdio.h>

class UserData
{
    int m_highestScore;
    
public:
    
    UserData(): m_highestScore(0) {};
    
    UserData * getInstance();
    int getHighestScore();
    void updateHighestScore(int);
};

#endif /* UserData_hpp */
