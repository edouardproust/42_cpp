#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	this->type = "Wrong cat";
	std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src)
{
	this->type = "wrong cat";
	std::cout << "WrongCat copied" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat deleted" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Meoooowww!" << std::endl;
}
