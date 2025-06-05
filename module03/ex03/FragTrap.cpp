#include "FragTrap.hpp"

// Constructor

FragTrap::FragTrap ():
	ClapTrap()
{
	this->_hit = 100;
	this->_frag_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
	this->_frag_attack = 30;
	std::cout << "Default FragTrap " << this->_name << " sent by the gods!" << std::endl;
}

FragTrap::FragTrap(std::string name):
	ClapTrap(name)
{
	this->_hit = 100;
	this->_frag_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
	this->_frag_attack = 30;
	std::cout << "FragTrap " << this->_name << " created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src):
	ClapTrap(src)
{
	std::cout << "FragTrap " << this->_name << " cloned!" << std::endl;
}

// Destructor

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " called back to heaven!" << std::endl;
}

// Operator overload

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "FragTrap upgrade for " << this->_name << std::endl;
	}
	return (*this);
}

// Actions

void	FragTrap::highFivesGuys(void)
{
	if (this->_energy <= 0) {
		std::cout << "FragTrap " << this->_name << " cannot highfive (no energy)" << std::endl;
	} else if (this->_hit <= 0) {
		std::cout << "FragTrap " << this->_name << " cannot highfive (he is dead)" << std::endl;
	} else {
		std::cout << "FragTrap " << this->_name << " does a highfive to all the robots!" << std::endl;
	}
}
