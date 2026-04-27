#ifndef MANA_H
#define MANA_H

class Mana {
public:
    Mana() = default;

    Mana(int newPlayerMana);  // create Mana for Character

    int getCurrentMana();
    int getMaxMana();

    void setLvlUpMaxMana(int addLvlUpMana); // setting new max mana after lvl up

    void restoreMana(int restoreAmount);    // restore mana via potion

    void printManaSlots() const;                  // print mana slots to screen

private:
    int CurrentMana;
    int MaxMana;

};



#endif