#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain copied" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain deleted" << std::endl;
}

Brain	&Brain::operator=(const Brain &src)
{
	if (this != &src) {
		for (int i; i < 100; i++) {
			this->ideas[i] = src.ideas[i];
		}
	}
	return (*this);
}
