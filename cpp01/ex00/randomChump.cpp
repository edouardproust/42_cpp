#include "Zombie.hpp"
#include <iostream>

void randomChump(std::string name)
{
	Zombie	newChump(name);
	newChump.announce();
}