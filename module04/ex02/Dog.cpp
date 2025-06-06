#include "Dog.hpp"

Dog::Dog():
	AAnimal(),
	brain(new Brain)
{
	this->type = "dog";
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog &src):
	AAnimal(src),
	brain(new Brain(*src.brain))
{
	std::cout << "Dog copied" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog deleted" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)	{
		AAnimal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}
