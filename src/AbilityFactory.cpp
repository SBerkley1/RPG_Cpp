#include "AbilityFactory.h"
#include "Ability.h"
#include "Fireball.h"
#include "Enraged.h"

vector<shared_ptr<Ability>> AbilityFactory::createWizardAbilities()
    // add or remove abilites as you please
{
    return {
        std::make_shared<Fireball>(2),
        std::make_shared<Enraged>(2,2)
    };
}

vector<shared_ptr<Ability>> AbilityFactory::createGoblinAbilities()
{
    return {
        std::make_shared<Fireball>(2),
        std::make_shared<Enraged>(2,2)
    };
}
