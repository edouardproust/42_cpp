#include "Cure.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure") {}

Cure::Cure(Cure const& src): AMateria(src) {}

Cure::~Cure() {}

Cure&	Cure::operator=(Cure const& rhs)
{
	if (this != &rhs) {
		AMateria::operator=(rhs);
	}
	return (*this);
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}