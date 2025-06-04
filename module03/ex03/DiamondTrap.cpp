#include "DiamondTrap.hpp"

// Constructor

DiamondTrap::DiamondTrap ():
	ClapTrap("C_clap_name"), FragTrap("C"), ScavTrap("C")
{
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "Default DiamondTrap " << this->_name << " sent by the gods!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "DiamondTrap " << this->_name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src):
	ClapTrap(src), FragTrap(src), ScavTrap(src)
{
	std::cout << "DiamondTrap " << this->_name << " cloned!" << std::endl;
}

// Destructor

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " called bak to heaven!" << std::endl;
}

// Operator overload

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "DiamondTrap upgrade for " << this->_name << std::endl;
	}
	return (*this);
}

// Actions

void	DiamondTrap::whoAmI()
{
	// TODO
}


