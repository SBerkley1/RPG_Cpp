#include <iomanip>

#include "Ability.h"
#include "Effect.h"
#include "Player.h"


void Player::characterTakeDamage(int damage)
{
    cout << this->Name << " takes " << damage << " damage!" << endl;
	this->HitPoints.takeDamage(damage);
}

void Player::playerGainsXP(int amount)
{
    this->levelSystem.gainXP(amount);
}

void Player::addItem(std::shared_ptr<Item> aItem, unsigned int quantity)
{
    inventory.addItem(aItem, quantity);
}

void Player::removeItem(std::shared_ptr<Item> aItem, unsigned int quantity)
{
    inventory.removeItem(aItem, quantity);
}

void Player::useItem(std::shared_ptr<Item> item, Character& target)
{
    inventory.useItem(item, *this, target);
}

void Player::printAbilities() const
{
    	// iterate through ability list and print the name
		cout << this->Name << "\'s Ability List:" << endl;

        cout << std::left;
        unsigned int number{ 1 }; // used to print out a numerical list
		for (const auto& ability : CharacterAbilities) {
			cout << number << ".) " 
                 << std::setw(18) << ability->getName()
                 << std::setw(15) << ("Mana Cost: " + std::to_string(ability->getManaCost())) 
                 << "Cooldown: " << ability->getCooldown() << endl;

            ++number; // increment number
		}

		cout << endl;
}

void Player::printEffects() const
{
    if (ActiveEffects.size() == 0) {
        return;
    }
    cout << this->Name << "\'s Active Buffs/Debuffs:" << endl;

    for (const auto& effect: ActiveEffects) {
        cout << effect.name
             << ":  Description: " << effect.description
             << "   Duration: " << effect.effectRounds << endl;
    }
}

void Player::printMana() const
{
    ManaPoints.printManaSlots();
}

void Player::printPlayerXP() const
{
    levelSystem.printXP();
}

void Player::printPlayerInventory() const
{
    inventory.printInventory();
}
