#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat():
	AAnimal(),
	brain(new Brain)
{
	this->type = "Cat";
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(Cat const& src):
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

Cat&	Cat::operator=(Cat const& other)
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

std::string const&	Cat::getIdea(size_t index) const
{
	return (this->brain->getIdea(index));
}

void	Cat::setIdea(size_t index, std::string const& idea)
{
	this->brain->addIdea(index, idea);
}
