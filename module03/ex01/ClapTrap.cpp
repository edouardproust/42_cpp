#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap (void):
	_name("Bob"),
	_hit(10),
	_energy(10),
	_attack(0)
{
	std::cout << "ClapTrap " << this->_name << " created! (Default model)" << std::endl;
}

ClapTrap::ClapTrap(std::string name):
	_name(name),
	_hit(10),
	_energy(10),
	_attack(0)
{
	std::cout << "ClapTrap " << this->_name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src):
	_name(src._name),
	_hit(src._hit),
	_energy(src._energy),
	_attack(src._attack)
{
	std::cout << "ClapTrap " << this->_name << " duplicated!" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << this->_name << " destroyed!" << std::endl;
}

// Operator overload
ClapTrap	&ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other)
	{
		std::cout << "ClapTrap " << this->_name << " modified to " << other._name << std::endl;
		this->_name = other._name;
		this->_hit = other._hit;
		this->_energy = other._energy;
		this->_attack = other._attack;
	} else {
		std::cout << "ClapTrap " << this->_name << " cannot be modified to himself!" << std::endl;
	}
	return (*this);
}

// Action functions

void	ClapTrap::attack(const std::string& target) {
	if (this->_energy > 0) {
		--this->_energy;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attack << " damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << this->_name << " cannot attack" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount > this->_hit)
		amount = this->_hit;
	this->_hit -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " <<  amount << " damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy > 0) {
		this->_hit += amount;
		--this->_energy;
		std::cout << "ClapTrap " << this->_name << " regained " << amount << " hit points" << std::endl;
	} else {
		std::cout << "ClapTrap " << this->_name << " cannot get repaired" << std::endl;
	}
}

// Accessors

std::string	ClapTrap::getName() const
{
	return (this->_name);
}

void	ClapTrap::setName(const std::string &name)
{
	std::string	prevName = this->_name;
	this->_name = name;
	std::cout << "ClapTrap " << prevName << " renamed: " << this->_name << std::endl;
}

unsigned int	ClapTrap::getHit() const {
	return (this->_hit);
}

unsigned int	ClapTrap::getEnergy() const {
	return (this->_energy);
}

unsigned int	ClapTrap::getAttack() const {
	return (this->_attack);
}

// Stream overload

std::ostream	&operator<<(std::ostream &o, const ClapTrap &c)
{
	o << "  [" << c.getName() << " hit:" << c.getHit() << ", ene:" << c.getEnergy() << ", att:" << c.getAttack() << "]" << std::endl;
	return (o);
}
