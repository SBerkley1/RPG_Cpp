#include "Ability.h"
#include "Effect.h"
#include "Monster.h"

void Monster::characterTakeDamage(int damage)
{
    cout << this->Name << " takes " << damage << " damage!" << endl;
	this->HitPoints.takeDamage(damage);
}

void Monster::printAbilities() const
{
    	// iterate through ability list and print the name
		cout << this->Name << "\'s Ability List:" << endl;

        unsigned int number{ 1 };
		for (const auto& ability : CharacterAbilities) {
			cout << number << ".) " << ability->getName() << '\n';
            ++number;
		}

		cout << endl;
}


void Monster::printEffects() const
{
    cout << this->Name << "\'s Active Buffs/Debuffs:" << endl;

    for (const auto& effect: ActiveEffects) {
        cout << effect.name
             << ":  Description: " << effect.description
             << "   Duration: " << effect.effectRounds << endl;
    }
}

Monster::Type Monster::getMonsterType() const
{
    return MonsterType;
}
