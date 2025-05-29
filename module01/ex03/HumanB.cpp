#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name): _name(name)
{
	return;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their ";
	std::cout << this->_weapon->getType() << std::endl;
}
