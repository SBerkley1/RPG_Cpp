#include <iostream>
#include <vector>
#include <memory>
#include <format>

#include "Ability.h"
#include "AbilityFactory.h"
#include "Character.h"
#include "Enraged.h"
#include "Fireball.h"
#include "HP.h"
#include "Monster.h"
#include "Player.h"

#include "HealthPotion.h"
#include "ManaPotion.h"
#include "random.h"



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

    switch (monster.getMonsterType()) {
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


    for (auto& ability : abilities) {
        monster.addAbility(std::move(ability));
    }
}

int randomNumber() {
    std::random_device rd{};
    std::seed_seq ss{ rd(), rd() , rd(), rd() , rd(), rd() , rd(), rd() , rd()};
    std::mt19937 mt{ ss };

    std::uniform_int_distribution die3{ 1, 3 };

    return die3(mt);
}

std::string itemDropped(Player& player) 
{
    auto healthPotion = std::make_shared<HealthPotion>();
    auto manaPotion = std::make_shared<ManaPotion>();
    std::string none{ "None Found" };

    int num{ randomNumber() };

    switch (num)
    {
    case 1:
        break;
    case 2:
        player.addItem(healthPotion);
        return "Health Potion";
    case 3:
        player.addItem(manaPotion);
        return "Mana Potion";
    default:
        cout << "Unknown error" << endl;
    }

    return none;
}

void battleReport(Character& player, Character& monster)
{
    Monster* monsterReport = dynamic_cast<Monster*>(&monster);
    Player* playerReport = dynamic_cast<Player*>(&player);

    if (monsterReport == nullptr || playerReport == nullptr) {
        cout << "NOTHING IS HERE: battleReport() type void" << endl;
        return;
    }

    string border(28, '-');
    string title{ "Battle Summary" };

    cout << border << '\n'
        << std::format("| {:^24} |\n", title)
        << border << '\n'
        << std::format("| {:<24} |\n", monster.getName() + " defeated")
        << std::format("| {:^24} |\n", "")
        << std::format("| {:<24} |\n", std::format("XP earned: {}", monsterReport->getXpEarned()))
        << std::format("| {:<24} |\n", "Item found: " + itemDropped(*playerReport)) // add logic for quantity
        << border << '\n'
        << endl;
}
