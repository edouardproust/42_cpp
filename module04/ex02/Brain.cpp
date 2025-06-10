#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(Brain const& other)
{
	*this = other;
	std::cout << "Brain copied" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain deleted" << std::endl;
}

Brain&	Brain::operator=(Brain const& src)
{
	if (this != &src) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = src.ideas[i];
		}
	}
	return (*this);
}

void	Brain::addIdea(size_t index, std::string const& idea)
{
	if (index < 100) {
		this->ideas[index] = idea;
	}
}

std::string const&	Brain::getIdea(size_t index)
{
	if (index < 100) {
		return (this->ideas[index]);
	}
	static const std::string empty = "";
	return (empty);
}
