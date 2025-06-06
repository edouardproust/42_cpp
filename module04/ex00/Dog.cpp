#include "Dog.hpp"

Dog::Dog(): Animal()
{
	this->type = "Dog";
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog &src): Animal(src)
{
	this->type = "Dog";
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

std::string	Dog::getType() const
{
	return (this->type);
}

std::ostream	&operator<<(std::ostream &o, const Dog &d)
{
	o << "Type: " << d.getType();
	return (o);
}
