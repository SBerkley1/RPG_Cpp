#include "Mana.h"
#include "Ability.h"
#include <cstddef>
#include <iostream>

Mana::Mana(int newPlayerMana)
{
    this->CurrentMana = newPlayerMana;
    this->MaxMana = newPlayerMana;
}

int Mana::getCurrentMana()
{
    return CurrentMana;
}

int Mana::getMaxMana()
{
    return MaxMana;
}

bool Mana::isEnoughMana(Ability* ability)
{
    return CurrentMana >= ability->getManaCost();
}

void Mana::setCurrentMana(int mana)
{
    this->CurrentMana = mana;
}

void Mana::setLvlUpMaxMana(int addLvlUpMana)
// used when lvling up
{
    this->MaxMana += addLvlUpMana;
    this->CurrentMana = this->MaxMana;
}

void Mana::restoreMana(int restoreAmount)
{
    int restore = CurrentMana + restoreAmount;

    if (restore > MaxMana) {
        CurrentMana = MaxMana;
    }
    else {
        CurrentMana = restore;
    }
}

void Mana::printManaSlots() const
{
    std::cout << "Mana: ";
    char manaCharacter = 'o';
    for(size_t i = 0; i <= this->CurrentMana; ++i) {
        if (CurrentMana > 0) {
            std::cout << manaCharacter << ' ';
        }
        else {
            std::cout << "Empty";
        }
    }
    std::cout << std::endl;
}
