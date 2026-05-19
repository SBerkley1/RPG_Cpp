#ifndef MANA_H
#define MANA_H

// forward declaration
class Ability;

class Mana {
public:
    Mana() = default;

    Mana(int newPlayerMana);  // create Mana for Character

    int getCurrentMana();
    int getMaxMana();

    bool isEnoughMana(Ability* ability);

    void setCurrentMana(int mana);          // set current mana after using ability
    void setLvlUpMaxMana(int addLvlUpMana); // setting new max mana after lvl up

    void restoreMana(int restoreAmount);    // restore mana via potion

    void printManaSlots() const;                  // print mana slots to screen

private:
    int CurrentMana;
    int MaxMana;

};



#endif