#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->_initSource();
}

MateriaSource::MateriaSource(MateriaSource const& src)
{
	this->_cloneSource(src);
}

MateriaSource::~MateriaSource()
{
	this->_destroySource();
}

MateriaSource&	MateriaSource::operator=(MateriaSource const& rhs)
{
	if (this != &rhs) {
		this->_destroySource();
		this->_cloneSource(rhs);
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for(int i = 0; i < 4 ; i++) {
		if (this->_source[i] == m) // Avoid duplicates
			return;
		if (!this->_source[i]) {
			this->_source[i] = m;
			break;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for(int i = 0; i < 4; i++) {
		if (this->_source[i] && type == this->_source[i]->getType()) {
			return (this->_source[i]->clone());
		}
	}
	return (NULL);
}

void	MateriaSource::_initSource()
{
	for(int i = 0; i < 4; i++) {
		this->_source[i] = NULL;
	}
}

void	MateriaSource::_cloneSource(MateriaSource const& src)
{
	for(int i = 0; i < 4; i++) {
		this->_source[i] = src._source[i] ? src._source[i]->clone() : NULL;
	}
}

void	MateriaSource::_destroySource()
{
	for(int i = 0; i < 4; i++) {
		delete this->_source[i]; // 'delete NULL' is a no-op
		this->_source[i] = NULL;
	}
}
