#ifndef ABILITYFACTORY_H
#define ABILITYFACTORY_H

#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;


// forward declaration
class Ability;

class AbilityFactory {
public:
    static vector<unique_ptr<Ability>> createWizardAbilities(); // Wizard abilities

    static vector<unique_ptr<Ability>> createGoblinAbilities(); // Goblin abilities

    // add more when more players/monsters are added
};

#endif