#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "HP.h"
#include "Mana.h"
#include "Effect.h"


using std::string;
using std::cout;
using std::endl;
using std::vector;

// forware declaration
class Ability; 

class Character // either player or npc
{
public:
	Character(const string& name, int startingHP, int startingMana); // will add xp(leveling system), mana, statsblock

	virtual ~Character() = default;

	virtual void characterTakeDamage(int damage);	// character taking damage
	virtual void printAbilities() const = 0;
	virtual void printEffects() const = 0;

	void useAbility(size_t index, Character& targer);		// character used an ability in CharacterAbilities

    void addAbility(std::unique_ptr<Ability> ability);
	void addEffect(const Effect& effect);					// add buffs and debuffs to player 
	void updateEffect();									// removes 1 turn from the buff/debuff countdown

	string getName() const;
	void printHitPoints() const;
	void getCurrentHP() const;
	int getBuffDamangeBonus() const;                       // get the increase of damage from buff
	bool isAlive() const;
    
	

protected:
	string Name;											// character's name
	HP HitPoints;											// character hit points
	Mana ManaPoints;			

    vector<std::shared_ptr<Ability>> CharacterAbilities;	// all of character's abilities
	vector<Effect> ActiveEffects;							// buffs and debuffs applied to a character
};

#endif // CHARACTER_H