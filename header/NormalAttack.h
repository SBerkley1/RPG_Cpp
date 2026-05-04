#ifndef NORMALATTACK_H
#define NORMALATTACK_H

#include <iostream>
#include "Ability.h"
#include "Character.h"

class NormalAttack : public Ability {
public:

	NormalAttack(int damage) : Ability{ "Normal Attack", "base damage from weapon", 0, 1 }, Damage{ damage } {}


	void useAbility(Character& owner, Character& target) override
	{
		int damage = Damage + owner.getBuffDamangeBonus();
		cout << owner.getName() << " used a " << Name << " and did " << damage << " damage!" << endl;

		target.characterTakeDamage(damage);
	}

private:
	int Damage;
};

#endif