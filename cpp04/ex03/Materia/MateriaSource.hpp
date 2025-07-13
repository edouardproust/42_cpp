#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{

	AMateria	*_source[4];

	void	_initSource();
	void	_cloneSource(MateriaSource const& src);
	void	_destroySource();

	public:

		// Constructor
		MateriaSource();
		MateriaSource(MateriaSource const& src);

		// Destructor
		virtual ~MateriaSource();

		// Operator overload
		MateriaSource&	operator=(MateriaSource const& rhs);

		// Actions
		virtual void		learnMateria(AMateria* m);
		virtual AMateria*	createMateria(std::string const & type);

};

#endif
