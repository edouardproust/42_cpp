#include "AAnimal.hpp"

AAnimal::AAnimal(): type("AAnimal")
{
	std::cout << "Animal created" << std::endl;
}

AAnimal::AAnimal(AAnimal const& src)
{
	*this = src;
	std::cout << "Animal copied" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal deleted" << std::endl;
}

AAnimal&	AAnimal::operator=(AAnimal const& other)
{
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

std::string const&	AAnimal::getType() const
{
	return (this->type);
}
