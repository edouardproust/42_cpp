#include "Dog.hpp"

Dog::Dog():
	AAnimal(),
	brain(new Brain)
{
	this->type = "Dog";
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(Dog const& src):
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

Dog&	Dog::operator=(Dog const& other)
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

std::string const&	Dog::getIdea(size_t index) const
{
	return (this->brain->getIdea(index));
}

void	Dog::setIdea(size_t index, std::string const& idea)
{
	this->brain->addIdea(index, idea);
}
