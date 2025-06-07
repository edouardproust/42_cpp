#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{

	public:

		// Constructor
		Ice();
		Ice(Ice const& src);

		// Destructor
		virtual ~Ice();

		// Operator overload
		Ice&	operator=(Ice const& rhs);

		// Actions
		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);

};

#endif
