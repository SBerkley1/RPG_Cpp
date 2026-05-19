#ifndef HEALTH_POTION_H
#define HEALTH_POTION_H

#include <iostream>

#include "Item.h"
#include "Character.h"

class HealthPotion : public Item {
public:
	HealthPotion() : Item{ "Health Potion", "Heals 10 hit points" }, HealAmount{ 10 } 
	{
	}

	void useItem(Character& owner, Character& target) override
	{
		cout << owner.getName() << " used " << getItemName() << " and healed " << HealAmount << " HP!" << endl;
		target.characterHealsHP(HealAmount);
	}

	unsigned int getHealAmount()
	{
		return HealAmount;
	}

private:
	unsigned int HealAmount;
};



#endif