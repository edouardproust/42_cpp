#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Wrong animal")
{
	std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
	std::cout << "WrongAnimal copied" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal deleted" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Some weird animal noise..." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

std::ostream	&operator<<(std::ostream &o, const WrongAnimal &a)
{
	o << a.getType() << ": ";
	a.makeSound();
	return (o);
}
