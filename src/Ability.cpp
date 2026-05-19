#include "Ability.h"
#include "Character.h"


Ability::Ability(const string& name, const string& description, int manaCost, int cooldown)
	: Name{ name }, Description{ description }, ManaCost{ manaCost }, Cooldown{ cooldown }
{
}

string Ability::getName() const
{
	return this->Name;
}

string Ability::getDescription() const
{
    return this->Description;
}

int Ability::getManaCost() const
{
	return this->ManaCost;
}

int Ability::getCooldown() const
{
	return this->Cooldown;
}
