#include "Dog.hpp"

Dog::Dog(): Animal()
{
	this->type = "dog";
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog &src): Animal(src)
{
	std::cout << "Dog copied" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog deleted" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
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
