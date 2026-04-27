#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Character.h"

using std::cout;
using std::endl;

class Player : public Character
{
public:
	Player(string name, int startingHP, int startingMana) : Character(name, startingHP, startingMana) {}

	void characterTakeDamage(int damage) override;
	
	void printAbilities() const override;
	void printEffects() const override;

	void printMana() const;
};

#endif // PLAYER_H