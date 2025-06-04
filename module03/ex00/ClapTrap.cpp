#include "ClapTrap.hpp"

// Constructor

ClapTrap::ClapTrap ():
	_name("C"),
	_hit(10),
	_energy(10),
	_attack(0)
{
	std::cout << "Default ClapTrap " << this->_name << " created!" << std::endl;
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
	std::cout << "ClapTrap " << this->_name << " cloned!" << std::endl;
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

// Action

void	ClapTrap::attack(const std::string& target) {
	if (this->_energy <= 0) {
		std::cout << "ClapTrap " << this->_name << " cannot attack (no energy)" << std::endl;
	} else if (this->_hit <= 0) {
		std::cout << "ClapTrap " << this->_name << " cannot attack (he is dead)" << std::endl;
	} else {
		--this->_energy;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attack << " damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit <= 0) {
		std::cout << "ClapTrap " << this->_name << " takes 0 damage (he is dead)" << std::endl;
	} else {
		if (amount > this->_hit)
			amount = this->_hit;
		this->_hit -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " <<  amount << " damage";
		if (this->_hit == 0) {
			std::cout << " and died!";
		}
		std::cout << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy <= 0) {
		std::cout << "ClapTrap " << this->_name << " cannot heal (no energy)" << std::endl;
	} else if (this->_hit <= 0) {
		std::cout << "ClapTrap " << this->_name << " cannot heal (he is dead)" << std::endl;
	} else {
		this->_hit += amount;
		--this->_energy;
		std::cout << "ClapTrap " << this->_name << " regained " << amount << " hit points" << std::endl;
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
	std::cout << "ClapTrap " << prevName << " renamed " << this->_name << std::endl;
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
