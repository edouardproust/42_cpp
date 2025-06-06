#include "Cat.hpp"

Cat::Cat(): Animal()
{
	this->type = "Cat";
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat &src): Animal(src)
{
	this->type = "Cat";
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

std::string Cat::getType() const
{
	return (this->type);
}

std::ostream	&operator<<(std::ostream &o, const Cat &c)
{
	o << "Type: " << c.getType();
	return (o);
}
