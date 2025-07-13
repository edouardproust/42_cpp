#include "Dog.hpp"

Dog::Dog(): Animal()
{
	this->type = "Dog";
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(Dog const& src): Animal(src)
{
	std::cout << "Dog copied" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog deleted" << std::endl;
}

Dog&	Dog::operator=(Dog const& other)
{
	if (this != &other)	{
		Animal::operator=(other);
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}
