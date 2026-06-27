#include <iostream>
#include "LevelSystem.h"

int LevelSystem::xpToNextLevel() const
{
    return level * 100; /// generic next level xp amount
}

int LevelSystem::gainXP(int xpAmount)
{
    xp += xpAmount;
    int lvlGained = 0;

    while (xp >= xpToNextLevel())
    {
        ++level;
        ++lvlGained;
        std::cout << "Leveled up to level " << level << std::endl;
    }

    return lvlGained;
}

int LevelSystem::getLevel() const
{
    return level;
}

int LevelSystem::getXP() const
{
    return xp;
}

bool LevelSystem::isLvlUp() const
{
    return xp >= xpToNextLevel();
}

void LevelSystem::printXP() const
{
    std::cout << "XP: " << xp << '/' << xpToNextLevel() << std::endl;
}
