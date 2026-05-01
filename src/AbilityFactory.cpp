#include "AbilityFactory.h"
#include "Ability.h"
#include "Fireball.h"
#include "Enraged.h"

vector<unique_ptr<Ability>> AbilityFactory::createWizardAbilities()
    // add or remove abilites as you please
{
    vector<unique_ptr<Ability>> abilities;

    abilities.push_back(std::make_unique<Fireball>(2));
    abilities.push_back(std::make_unique<Enraged>(2,2));

    return abilities;
}

vector<unique_ptr<Ability>> AbilityFactory::createGoblinAbilities()
{
    vector<unique_ptr<Ability>> abilities;

    abilities.push_back(std::make_unique<Fireball>(2));

    return abilities;
}

vector<unique_ptr<Ability>> AbilityFactory::createTrollAbilities()
{
    vector<unique_ptr<Ability>> abilites;

    abilites.push_back(std::make_unique<Enraged>(2,2));

    return abilites;
}

vector<unique_ptr<Ability>> AbilityFactory::createOrcAbilities()
{
    vector<unique_ptr<Ability>> abilities;

    abilities.push_back(std::make_unique<Fireball>(2));
    abilities.push_back(std::make_unique<Enraged>(2,2));

    return abilities;
}
