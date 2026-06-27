#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <memory>

#include "Character.h"
#include "Inventory.h"
#include "Item.h"
#include "LevelSystem.h"

using std::cout;
using std::endl;

class Player : public Character
{
public:
	Player(string name, int startingHP, int startingMana)
	: Character(name, startingHP, startingMana), levelSystem() {}

	void characterTakeDamage(int damage) override;
	void playerGainsXP(int amount);

	void addItem(std::shared_ptr<Item> aItem, unsigned int quantity = 1);
	void removeItem(std::shared_ptr<Item> aItem, unsigned int quantity = 1);
	void useItem(std::shared_ptr<Item> item, Character& target);
	
	void printAbilities() const override;
	void printEffects() const override;
	void printMana() const;
	void printPlayerXP() const;
	void printPlayerInventory() const;
private:
	Inventory inventory;
	LevelSystem levelSystem;
};

#endif // PLAYER_H