#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat():
	AAnimal(),
	brain(new Brain)
{
	this->type = "cat";
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat &src):
	AAnimal(src),
	brain(new Brain(*src.brain))
{
	std::cout << "Cat copied" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat deleted" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other) {
		AAnimal::operator=(other);
		delete(this->brain);
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meoooowww!" << std::endl;
}
