#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src)
{
	this->type = "WrongCat";
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

std::string WrongCat::getType() const
{
	return (this->type);
}

std::ostream	&operator<<(std::ostream &o, const WrongCat &c)
{
	o << "Type: " << c.getType();
	return (o);
}
