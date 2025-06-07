#include "AMateria.hpp"

AMateria::AMateria(): _type("materia") {}

AMateria::AMateria(std::string const& type): _type(type) {}

AMateria::AMateria(AMateria const& src): _type(src._type) {}

AMateria::~AMateria() {}

AMateria&	AMateria::operator=(AMateria const& rhs)
{
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}

std::string const&	AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
    (void)target; // default: do nothing
}