#ifndef MANA_POTION_H
#define MANA_POTION_H

#include <iostream>

#include "Item.h"
#include "Character.h"

class ManaPotion : public Item {
public:
	ManaPotion() : Item{ "Mana Potion", "Restore 5 mana" }, ManaAmount{ 5 }
	{
	}

	void useItem(Character& owner, Character& target) override
	{
		cout << owner.getName() << " used " << getItemName() << " and restored " << ManaAmount << " Mana!" << endl;
		target.characterHealsHP(ManaAmount);
	}

	unsigned int getManaAmount()
	{
		return ManaAmount;
	}

private:
	unsigned int ManaAmount;
};



#endif