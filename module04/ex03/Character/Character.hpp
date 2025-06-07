#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <vector>

class Character: public ICharacter
{

	std::string				_name;
	AMateria*				_materias[4];
	std::vector<AMateria*>	_unequipped;

	void	_initMaterias();
	void	_cloneMaterias(Character const& src);
	void	_destroyMaterias();
	void	_cloneUnequipped(Character const& src);
	void	_destroyUnequipped();

	public:

		// constructor
		Character();
		Character(std::string const& name);
		Character(Character const& src);

		// destructor
		virtual ~Character();

		// Operator overload
		Character&	operator=(Character const& rhs);

		// Action
		virtual void	equip(AMateria* m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter& target);

		// Accessors
		virtual std::string const&	getName() const;

};

#endif
