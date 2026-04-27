
#include "Ability.h"
#include "Effect.h"
#include "Player.h"


void Player::characterTakeDamage(int damage)
{
    cout << this->Name << " takes " << damage << " damage!" << endl;
	this->HitPoints.takeDamage(damage);
}

void Player::printAbilities() const
{
    	// iterate through ability list and print the name
		cout << this->Name << "\'s Ability List:" << endl;

		for (const auto& ability : CharacterAbilities) {
			cout << ability->getName() 
                 << ":    Mana Cost: " << ability->getManaCost() 
                 << "   Cooldown: " << ability->getCooldown() << endl;
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
