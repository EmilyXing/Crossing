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
    int m_lastScore;
    
public:
    
    UserData() : m_highestScore(0), m_lastScore(0) {}
    
    static UserData * getInstance();
    
    int getLastScore();
    void setLastScore(int);
    
    int getHighestScore();
    
};

#endif /* UserData_hpp */
