#include "AbilityFactory.h"
#include "Ability.h"
#include "NormalAttack.h"
#include "Fireball.h"
#include "Enraged.h"
#include "Reveal.h"
#include "SmallHeal.h"

vector<unique_ptr<Ability>> AbilityFactory::createWizardAbilities()
    // add or remove abilites as you please
{
    vector<unique_ptr<Ability>> abilities;

    abilities.push_back(std::make_unique<NormalAttack>(4));
    abilities.push_back(std::make_unique<Fireball>(2));
    abilities.push_back(std::make_unique<Enraged>(2,2));
    abilities.push_back(std::make_unique<Reveal>());
    abilities.push_back(std::make_unique<SmallHeal>());


    return abilities;
}

vector<unique_ptr<Ability>> AbilityFactory::createGoblinAbilities()
{
    vector<unique_ptr<Ability>> abilities;

    abilities.push_back(std::make_unique<NormalAttack>(3));
    abilities.push_back(std::make_unique<Fireball>(2));

    return abilities;
}

vector<unique_ptr<Ability>> AbilityFactory::createTrollAbilities()
{
    vector<unique_ptr<Ability>> abilities;

    abilities.push_back(std::make_unique<NormalAttack>(7));
    abilities.push_back(std::make_unique<Enraged>(2,2));

    return abilities;
}

vector<unique_ptr<Ability>> AbilityFactory::createOrcAbilities()
{
    vector<unique_ptr<Ability>> abilities;

    abilities.push_back(std::make_unique<NormalAttack>(9));
    abilities.push_back(std::make_unique<Fireball>(2));
    abilities.push_back(std::make_unique<Enraged>(2,2));

    return abilities;
}
