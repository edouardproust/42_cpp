#include <string>
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name)
{
	return;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " has been destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}