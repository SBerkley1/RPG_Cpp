#ifndef ITEM_CLASS_H
#define ITEM_CLASS_H

#include <string>
#include <memory>

class Character;


class Item {
public:
	Item(std::string aName, std::string aDescription);
	virtual ~Item() = default;

	virtual void useItem(Character& owner, Character& target) = 0;
	
	const std::string& getItemName() const;
	const std::string& getItemDescription() const;

private:
	std::string name;
	std::string description;
};


#endif