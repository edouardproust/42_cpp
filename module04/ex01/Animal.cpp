#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
	std::cout << "Animal copied" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal deleted" << std::endl;
}

Animal	&Animal::operator=(const Animal& other)
{
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Some mysterious animal noise..." << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

std::ostream	&operator<<(std::ostream &o, const Animal &a)
{
	o << a.getType() << ": ";
	a.makeSound();
	return (o);
}
