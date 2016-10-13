//
//  UserData.cpp
//  Xing
//
//  Created by Fangyuan Xing on 10/11/16.
//
//

#include "UserData.hpp"

// singleton
UserData * UserData::getInstance()
{
    static UserData * userData = nullptr;
    
    if(userData == nullptr)
    {
        userData = new UserData();
    }
    
    return userData;
}

int UserData::getHighestScore()
{
    return m_highestScore;
}

void UserData::updateHighestScore(int x)
{
    m_highestScore = x;
}