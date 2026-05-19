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
	enum class Type {
		// add monster types here and update AbilityFactory to customize the monster's ability
		Goblin,
		Troll,
		Orc
	};

	Monster(const string& name, int startingHP, int startingMana, Type type) 
		: Character(name, startingHP, startingMana), MonsterType {type} {}

	void characterTakeDamage(int damage) override;	// Monster takes damage and output Monster taking damage

	void printAbilities() const override;			// prints all abilities Monster has
	void printEffects() const override;

	Type getMonsterType() const;

private:
	Type MonsterType;
};	

#endif // MONSTER_H