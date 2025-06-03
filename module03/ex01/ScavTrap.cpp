#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap (void):
	ClapTrap("Clap")
{
	this._hit(100),
	this->_energy(50),
	_attack(20)
	std::cout << "ScavTrap " << this->_name << " created! (Default model)" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this)
}
