#include "AAnimal.hpp"

AAnimal::AAnimal(): type("animal")
{
	std::cout << "Animal created" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	*this = src;
	std::cout << "Animal copied" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal deleted" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal& other)
{
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

void	AAnimal::makeSound() const
{
	std::cout << "Some mysterious animal noise..." << std::endl;
}

std::string AAnimal::getType() const
{
	return (this->type);
}

std::ostream	&operator<<(std::ostream &o, const AAnimal &a)
{
	o << a.getType() << ": ";
	a.makeSound();
	return (o);
}
