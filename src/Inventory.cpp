#include <iostream>
#include <iomanip>

#include "Inventory.h"
#include "Item.h"

using std::cout;
using std::endl;

void Inventory::addItem(std::shared_ptr<Item> aItem, int quantity)
{
	const std::string& itemName = aItem->getItemName();

	// search if inventory has item, and if it does increase the quantity of item
	for (auto& inventoryItem : items) {
		if (inventoryItem.item->getItemName() == itemName) {
			inventoryItem.quantity += quantity;
			return;
		}
	}

	items.push_back({ aItem, quantity });  // if not in inventory, add item and quantity amount
}

void Inventory::removeItem(std::shared_ptr<Item> aItem, int quantity)
{
	const std::string& itemName = aItem->getItemName();

	for (auto iter = items.begin(); iter != items.end(); ++iter) {
		if (iter->item->getItemName() == itemName) {
			// if quantity goes to 0 remove item from inventory
			if (iter->quantity - quantity <= 0) { 
				items.erase(iter);
			}
			else { // else reduce the quantity by 1 or more
				iter->quantity -= quantity;
			}

			return;
		}
	}
}

void Inventory::useItem(std::shared_ptr<Item> aItem, Character& owner, Character& target)
{
	std::string itemName = aItem->getItemName();

	for (auto iter = items.begin(); iter != items.end();) {
		if (iter->item->getItemName() == itemName) {
			iter->item->useItem(owner, target);

			iter->quantity -= 1;

			if (iter->quantity <= 0) {
				iter = items.erase(iter);
			}
			else {
				++iter;
			}
			
			return;
		}
		else {
			++iter;
		}
	}
}

void Inventory::printInventory() const
{
	cout << "Inventory:" << endl;

	cout << std::left;
	unsigned int number{ 1 };

	if (items.empty()) {
		cout << "You\'re invertory is empty...." << endl;
		return;
	}

	for (const auto& inventoryItem : items) {
		cout << number << ".) "
			<< std::setw(18) << inventoryItem.item->getItemName()
			<< std::setw(15) << "Description: " << inventoryItem.item->getItemDescription() << endl;
	}
}