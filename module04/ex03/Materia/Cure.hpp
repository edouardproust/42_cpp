#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{

	public:

		// Constructor
		Cure();
		Cure(Cure const& src);

		// Destructor
		virtual ~Cure();

		// Operator overload
		Cure&	operator=(Cure const& rhs);

		// Actions
		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);

};

#endif
