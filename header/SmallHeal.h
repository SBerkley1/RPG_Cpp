#ifndef SMALL_HEAL_H
#define SMALL_HEAL_H

#include <iostream>
#include "Ability.h"
#include "Character.h"

class SmallHeal : public Ability {
public:
	SmallHeal()
		: Ability{ "Small Heal", "Heal for 8 Hit Points", 1, 2 }
		, HealAmount{ 8 } 
	{
	}

	void useAbility(Character& owner, Character& target) override
	{	
		cout << owner.getName() << " casted " << Name << endl;	
		target.characterHealsHP(HealAmount);		
	}

private:
	int HealAmount;
};



#endif