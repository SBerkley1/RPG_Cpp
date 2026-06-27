//
// Created by stephen on 6/27/26.
//

#ifndef RPG_GAME_LEVELSYSTEM_H
#define RPG_GAME_LEVELSYSTEM_H

class LevelSystem {
public:
    LevelSystem() : level{1}, xp{0} {} // sets lvl to 1 and xp to 0

    int xpToNextLevel() const;

    // xp setter
    int gainXP(int xpAmount);

    int getLevel() const;
    int getXP() const;
    bool isLvlUp() const;
    void printXP() const;

private:
    int level;
    int xp;
};

#endif //RPG_GAME_LEVELSYSTEM_H