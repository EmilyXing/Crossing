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

int UserData::getLastScore()
{
    return m_lastScore;
}


void UserData::setLastScore(int x)
{
    m_lastScore = x;
    
    if(m_lastScore > m_highestScore)
    {
        m_highestScore = m_lastScore;
    }
}

int UserData::getHighestScore()
{
    return m_highestScore;
}

