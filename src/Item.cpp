#include "Item.h"


Item::Item(std::string aName, std::string aDescription)
{
	name = aName;
	description = aDescription;
}

const std::string& Item::getItemName() const
{
	return name;
}

const std::string& Item::getItemDescription() const
{
	return description;
}