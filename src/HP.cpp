#include <iostream>
#include "HP.h"

using std::cout;
using std::endl;

HP::HP(int startingHP) 
	: CurrentHP{ startingHP }, MaxHP{ startingHP }
{
}

void HP::setMaxHP(int addLvlUpHP)
	// set new Max HP when leveling up
{
	this->MaxHP += addLvlUpHP;
	this->CurrentHP = this->MaxHP;
}

bool HP::isAlive() const
	// true if CurrentHP > 0
{
	return this->CurrentHP > 0;
}

void HP::heal(int healAmount)
	// heal by parameter's amount
{
	if (healAmount + this->CurrentHP > this->MaxHP)
		this->CurrentHP = this->MaxHP;
	else
		this->CurrentHP += healAmount;
}

void HP::takeDamage(int damage)
{
	if (damage > this->CurrentHP)
		this->CurrentHP = 0;
	else
		this->CurrentHP -= damage;
}

void HP::healHP(int healAmount)
{
	if (healAmount <= 0) {
		cout << "No heal was applied!" << endl;
		return;
	}

	int healed = this->CurrentHP + healAmount;

	if (healed > this->CurrentHP) {
		this->CurrentHP = this->MaxHP;
	}
	else {
		this->CurrentHP = healed;
	}
}

void HP::displayHP() const
	// displays CurrentHP / MaxHP
{
	cout << "HP: " << this->CurrentHP << " / " << this->MaxHP << endl;
}

int HP::getCurrentHP() const
{
	return this->CurrentHP;
}

int HP::getMaxHP() const
{
	return this->MaxHP;
}