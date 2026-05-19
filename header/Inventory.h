#ifndef INVENTORY_CLASS_H
#define INVENTORY_CLASS_H

#include <string>
#include <vector>
#include <memory>

#include "Character.h"

// forware declaration 
class Item;


class Inventory {
public:
	struct ItemAmount {
		std::shared_ptr<Item> item;
		int quantity;
	};

	void addItem(std::shared_ptr<Item> aItem, int quantity = 1);
	void removeItem(std::shared_ptr<Item> aItem, int quantity = 1);
	void useItem(std::shared_ptr<Item> aItem, Character& owner, Character& target);

	void printInventory() const;
private:
	std::vector<ItemAmount> items;

};



#endif