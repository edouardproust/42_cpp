#include "Weapon.hpp"
#include <string>

Weapon::Weapon(std::string type): _type(type)
{
	return;
}

const std::string& Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(const std::string& type)
{
	this->_type = type;
}