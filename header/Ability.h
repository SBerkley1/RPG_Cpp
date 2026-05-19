#ifndef ABILITY_H
#define ABILITY_H

#include <string>

using std::string;

class Character;  // forward declaration

class Ability {
public:
	// use ability. can either be player or npc
	virtual void useAbility(Character& owner, Character& target) = 0;

	// destructor
	virtual ~Ability() = default;

	// getters for common attributes of ability
	string getName() const;
	string getDescription() const;
	int getManaCost() const;
	int getCooldown() const;

protected:
	// common attributes for abilites
	string Name;
	string Description;
	int ManaCost;
	int Cooldown;

	// constructor for Abilities
	Ability(const string& name, const string& description, int manaCost, int cooldown);

};

#endif // ABILITY_H