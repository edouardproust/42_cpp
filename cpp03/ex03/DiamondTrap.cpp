#include "DiamondTrap.hpp"

// Constructor

DiamondTrap::DiamondTrap ():
	ClapTrap("C_clap_name"), ScavTrap(), FragTrap(), _name("C")
{
	this->_hit = this->_frag_hit;
	this->_energy = this->_scav_energy;
	this->_attack = this->_frag_attack;
	std::cout << "Default DiamondTrap " << this->_name << " sent by the gods!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_hit = this->_frag_hit;
	this->_energy = this->_scav_energy;
	this->_attack = this->_frag_attack;
	std::cout << "DiamondTrap " << this->_name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src):
	ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name)
{
	std::cout << "DiamondTrap " << this->_name << " cloned!" << std::endl;
}

// Destructor

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " called back to heaven!" << std::endl;
}

// Operator overload

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		this->_name = other._name;
		std::cout << "DiamondTrap upgrade for " << this->_name << std::endl;
	}
	return (*this);
}

// Actions

void	DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Am I " << this->_name << " or " << ClapTrap::_name << "?" << std::endl;
}


