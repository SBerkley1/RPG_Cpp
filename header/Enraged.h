#pragma once
#ifndef ENRAGED_H
#define ENRAGED_H

#include <iostream>
#include "Ability.h"
#include "Character.h"

class Enraged : public Ability {
public:

	Enraged(int damageBuff, int numberRounds) 
        : Ability{ "Enraged", "Increases damage by +2 for 2 rounds.", 1, 2 }, DamageBuff { damageBuff }, Rounds { numberRounds } {}


	void useAbility(Character& owner, Character& target) override
	{
		cout << owner.getName() << " casted " << Name << " and damage has been increase by +" 
             << DamageBuff << " damage for " << Rounds << " rounds!" << endl;
		owner.addEffect({"Enraged", "+2 damage for 2 rounds", DamageBuff, Rounds});
    }

private:
	int DamageBuff;
    int Rounds;
};

#endif // ENRAGED_H