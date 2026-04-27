#pragma once
#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include "Character.h"

using std::cout;
using std::endl;

class Monster : public Character
{
public:
	Monster(const string& name, int startingHP, int startingMana) : Character(name, startingHP, startingMana) {}

	void characterTakeDamage(int damage) override;	// Monster takes damage and output Monster taking damage

	void printAbilities() const override;			// prints all abilities Monster has
	void printEffects() const override;
};	

#endif // MONSTER_H