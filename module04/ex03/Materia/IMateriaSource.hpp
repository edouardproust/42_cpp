#ifndef I_MATERIA_SOURCE_HPP
# define I_MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class IMateriaSource
{

	public:

		// Destructor
		virtual ~IMateriaSource() {}

		// Actions
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;

};

#endif
