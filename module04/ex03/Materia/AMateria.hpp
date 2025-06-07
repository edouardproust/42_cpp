#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria
{

	protected:

		std::string	_type;

	public:

		// Constructor
		AMateria();
		AMateria(std::string const& type);
		AMateria(AMateria const& src);

		// Destructor
		virtual ~AMateria();

		// Operator overload
		AMateria&	operator=(AMateria const& rhs);

		// Accessors
		std::string const& getType() const;

		// Actions
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

};

#endif
