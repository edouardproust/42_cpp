#include "Cat.hpp"

Cat::Cat(): Animal()
{
	this->type = "cat";
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat &src): Animal(src)
{
	this->type = "cat";
	std::cout << "Cat copied" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat deleted" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other) {
		Animal::operator=(other);
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meoooowww!" << std::endl;
}
