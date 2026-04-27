#pragma once
#ifndef HP_H
#define HP_H

class HP
{
public:
	HP(int startingHP);
		
	void setMaxHP(int addLvlUpHP);	// set new HP when leveling up

	bool isAlive() const;			// true if CurrentHP > 0
	void heal(int healAmount);		// heal by parameter's amount

	void takeDamage(int damage);	// creature takes damage

	void displayHP() const;				// display CurrentHP / MaxHP

	int getCurrentHP() const;
	int getMaxHP() const;

private:
	int CurrentHP;
	int MaxHP;
};

#endif // HP_H