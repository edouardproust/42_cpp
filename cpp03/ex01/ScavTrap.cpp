#include "ScavTrap.hpp"
#include <iostream>

// Constructor

ScavTrap::ScavTrap ():
	ClapTrap()
{
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
	std::cout << "Default ScavTrap " << this->_name << " invoked!" << std::endl;
}

ScavTrap::ScavTrap(std::string name):
	ClapTrap(name)
{
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
	std::cout << "ScavTrap " << this->_name << " created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src):
	ClapTrap(src)
{
	std::cout << "ScavTrap " << this->_name << " cloned!" << std::endl;
}

// Destructor

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destroyed!" << std::endl;
}

// Operator overload

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "ScavTrap upgrade for " << this->_name << std::endl;
	}
	return (*this);
}

// Actions

void	ScavTrap::attack(const std::string& target) {
	if (this->_energy <= 0) {
		std::cout << "ScavTrap " << this->_name << " cannot attack (no energy)" << std::endl;
	} else if (this->_hit <= 0) {
		std::cout << "ScavTrap " << this->_name << " cannot attack (he is dead)" << std::endl;
	} else {
		--this->_energy;
		std::cout << "ScavTrap " << this->_name << " hits " << target << " causing " << this->_attack << " damage!" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	if (this->_energy <= 0) {
		std::cout << "ScavTrap " << this->_name << " cannot guard gate (no energy)" << std::endl;
	} else if (this->_hit <= 0) {
		std::cout << "ScavTrap " << this->_name << " cannot guard gate (he is dead)" << std::endl;
	} else {
		std::cout << "ScavTrap " << this->_name << " now guards the gate!" << std::endl;
	}
}
