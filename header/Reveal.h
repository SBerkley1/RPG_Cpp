#ifndef REVEAL_H
#define REVEAL_H

#include <iostream>
#include "Ability.h"
#include "Character.h"

class Reveal : public Ability {
public:
	Reveal() : Ability("Reveal", "Reveals targeted stats", 2, 1) {}

	void useAbility(Character& owner, Character& target) override
	{
		cout << owner.getName() << " casted " << Name << " and revealed that "
			 << target.getName() << "\'s current HP is: " << target.getCurrentHP() << endl;
	}
};


#endif