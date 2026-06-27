#include <iostream>
#include <vector>
#include <memory>

#include "Ability.h"
#include "AbilityFactory.h"
#include "Character.h"
#include "Enraged.h"
#include "Fireball.h"
#include "HP.h"
#include "Monster.h"
#include "Player.h"

#include "HealthPotion.h"

void loadPlayerAbilities(Character& player);
void loadMonsterAbilities(Monster& monster);

int main() {
    auto wizard = std::make_unique<Player>("Valek", 25, 5);

    auto healthPotion = std::make_shared<HealthPotion>();

    auto monsters = std::vector<std::unique_ptr<Monster>>();
    monsters.push_back(std::make_unique<Monster>("Goblin", 20, 5, Monster::Type::Goblin));
    monsters.push_back(std::make_unique<Monster>("Troll", 25, 5, Monster::Type::Troll));
    monsters.push_back(std::make_unique<Monster>("Orc", 30, 5, Monster::Type::Orc));


    loadPlayerAbilities(*wizard);
    wizard->addItem(healthPotion);

    for (auto& monster : monsters) {
        loadMonsterAbilities(*monster);
    }
    
    Character& goblin = *monsters[0];   // goblin
    Character& troll = *monsters[1];    // troll
    Character& orc = *monsters[2];

    wizard->printAbilities();
    wizard->printPlayerInventory();
    wizard->printPlayerXP();

    cout << endl;

    goblin.printAbilities(); // nned to fix to show quantity too

    cout << "Valek: "; 
    wizard->printHitPoints();
    wizard->printMana();

    cout << "Goblin: ";
    goblin.printHitPoints();



   int counter = 0;
   while (wizard->isAlive() && goblin.isAlive() && counter <= 10) {
       if (counter == 1) {
           wizard->useItem(healthPotion, *wizard);
           wizard->printPlayerInventory();
       }
        
       if (counter == 2) {
           wizard->useAbility(4, *wizard);
           goblin.useAbility(1, goblin); 

           cout << wizard->getName() << ":\n";
           wizard->printHitPoints();
           wizard->printMana();

           cout << goblin.getName() << ":\n";
           goblin.printHitPoints();
       }

       wizard->useAbility(0, goblin);
       cout << endl;

       goblin.useAbility(0, *wizard);
       cout << endl;

       cout << "Valek: ";
       wizard->printHitPoints();

       cout << "Goblin ";
       goblin.printHitPoints();

       cout << endl;

       wizard->updateEffect();

       wizard->printEffects();
       wizard->printMana();

       ++counter;
   } 

   cout << "\n==========================\n" << endl;

    wizard->playerGainsXP(450);
    wizard->printPlayerXP();

   unsigned int newCounter{ 0 };
   while (wizard->isAlive() && troll.isAlive() && newCounter <= 10) {
       if (newCounter == 1) {
           wizard->useAbility(4, *wizard);
       }

       if (newCounter == 2) {
           wizard->useAbility(2, *wizard);
           troll.useAbility(1, troll);
       }

       wizard->useAbility(0, troll);
       cout << endl;

       troll.useAbility(0, *wizard);
       cout << endl;

       cout << "Valek: ";
       wizard->printHitPoints();

       cout << "Troll ";
       troll.printHitPoints();

       cout << endl;

       wizard->updateEffect();

       wizard->printEffects();
       wizard->printMana();

       ++newCounter;
   }

   cout << "\n==========================\n" << endl;

   return 0;
}


void loadPlayerAbilities(Character& player) 
    // loading Player abilities
{
    for (auto& ability : AbilityFactory::createWizardAbilities()) {
        player.addAbility(std::move(ability));
    }
}



void loadMonsterAbilities(Monster& monster)
    // loading Monster abilites based on MonsterType
{
    std::vector<std::unique_ptr<Ability>> abilities;

    switch(monster.getMonsterType()) {
    case Monster::Type::Goblin:
        abilities = AbilityFactory::createGoblinAbilities();
        break;

    case Monster::Type::Troll:
        abilities = AbilityFactory::createTrollAbilities();
        break;

    case Monster::Type::Orc:
        abilities = AbilityFactory::createOrcAbilities();
        break;

    default: // eventually change to throw
        cout << "Invalid Monster Type!" << endl;
    }


    for(auto& ability : abilities) {
        monster.addAbility(std::move(ability));
    }
}
