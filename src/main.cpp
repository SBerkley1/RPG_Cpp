#include <iostream>
#include <memory>

#include "Ability.h"
#include "AbilityFactory.h"
#include "Character.h"
#include "Enraged.h"
#include "Fireball.h"
#include "HP.h"
#include "Monster.h"
#include "Player.h"

void loadAbilities(Character* player, Character* npc);

int main() {
    auto wizard = std::make_shared<Player>("Valek", 16, 5);
    auto goblin = std::make_shared<Monster>("Goblin", 11, 5);

    loadAbilities(wizard.get(), goblin.get());

    wizard->printAbilities();

    cout << endl;

    goblin->printAbilities();

    cout << "Valek: "; 
    wizard->printHitPoints();
    wizard->printMana();

    cout << "Goblin: ";
    goblin->printHitPoints();



   int counter = 0;
    while (wizard->isAlive() && goblin->isAlive()) {
        if (counter == 2) {
            wizard->useAbility(1, *wizard); 
        }

        wizard->useAbility(0, *goblin);
        cout << endl;

        goblin->useAbility(0, *wizard);
        cout << endl;

        cout << "Valek: ";
        wizard->printHitPoints();

        cout << "Goblin ";
        goblin->printHitPoints();

        cout << endl;

        wizard->updateEffect();

        wizard->printEffects();
        wizard->printMana();

        ++counter;
    } 

    return 0;
}

void loadAbilities(Character* player, Character* npc)
{
    // load wizard abilities
    for (auto& ability : AbilityFactory::createWizardAbilities()) {
        player->addAbility(ability);
    }

    // load goblin abilities
    for (auto& ability : AbilityFactory::createGoblinAbilities()) {
        npc->addAbility(ability);
    }
}
