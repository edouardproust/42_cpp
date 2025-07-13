#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(Animal const& src)
{
	*this = src;
	std::cout << "Animal copied" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal deleted" << std::endl;
}

Animal&	Animal::operator=(Animal const& other)
{
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Some mysterious animal noise..." << std::endl;
}

std::string const&	Animal::getType() const
{
	return (this->type);
}

std::string const&	Animal::getIdea(size_t index) const
{
	(void)index;
	static const std::string empty = "";
	return (empty);
}

void	Animal::setIdea(size_t index, std::string const& idea) {
	(void)index;
	(void)idea;
}
