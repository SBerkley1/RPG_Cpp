#pragma once
#ifndef FIREBALL_H
#define FIREBALL_H

#include <iostream>
#include "Ability.h"
#include "Character.h"

class Fireball : public Ability {
public:

	Fireball(int damage) : Ability{ "Fireball", "Cast a fireball to do imense damage", 1, 1 }, Damage{ damage } {}


	void useAbility(Character& owner, Character& target) override
	{
		int damage = Damage + owner.getBuffDamangeBonus();
		cout << owner.getName() << " casted " << Name << " and did " << damage << " damage!" << endl;
		
		target.characterTakeDamage(damage);
	}

private:
	int Damage;
};

#endif // FIREBALL_H