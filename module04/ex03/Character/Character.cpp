#include "Character.hpp"

// Constructor

Character::Character(): _name("anonyme")
{
	this->_initMaterias();
}

Character::Character(std::string const& name): _name(name)
{
	this->_initMaterias();
}

Character::Character(Character const& src): _name(src._name)
{
	this->_cloneMaterias(src);
	this->_cloneUnequipped(src);
}

// Destrcutor

Character::~Character()
{
	this->_destroyMaterias();
	this->_destroyUnequipped();
}

// Overload operators

Character&	Character::operator=(Character const& rhs)
{
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_destroyMaterias();
		this->_destroyUnequipped();
		this->_cloneMaterias(rhs);
		this->_cloneUnequipped(rhs);
	}
	return (*this);
}

// Actions

void	Character::equip(AMateria* m)
{
	if (!m)
		return;
	for(int i = 0; i < 4; i++) {
		if (!this->_materias[i]) {
			this->_materias[i] = m;
			return;
		}
	}
	delete m; /* Delete materia if it is out of range
	('delete NULL' is a no-op) */
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !this->_materias[idx])
		return;
	this->_unequipped.push_back(this->_materias[idx]);
	this->_materias[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 4 || !this->_materias[idx])
		return;
	this->_materias[idx]->use(target);
}

// Accessors

std::string const&	Character::getName() const
{
	return (this->_name);
}

// Utils

void	Character::_initMaterias()
{
	for(int i = 0; i < 4; i++) {
		this->_materias[i] = NULL;
	}
}

void	Character::_cloneMaterias(Character const& src)
{
	for(int i = 0; i < 4; i++) {
		this->_materias[i] = src._materias[i] ? src._materias[i]->clone() : NULL;
	}
}

void	Character::_destroyMaterias()
{
	for (int i = 0; i < 4; i++) {
		delete this->_materias[i]; // 'delete NULL' is a no-op
		this->_materias[i] = NULL;
	}
}

void	Character::_cloneUnequipped(Character const& src)
{
	for(std::vector<AMateria*>::const_iterator it = src._unequipped.begin();
		it != src._unequipped.end(); it++) {
		this->_unequipped.push_back(*it ? (*it)->clone() : NULL);
	}
}

void	Character::_destroyUnequipped()
{
	for(std::vector<AMateria*>::iterator it = this->_unequipped.begin();
		it != this->_unequipped.end(); it++) {
		delete *it; // 'delete NULL' is a no-op
	}
	this->_unequipped.clear();
}
