#include "HumanA.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon):
	_name(name),
	_weapon(weapon)
{
	return;
}

void HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their "
		<< this->_weapon.getType() << std::endl;
}