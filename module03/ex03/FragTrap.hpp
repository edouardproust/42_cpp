#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap: virtual public ClapTrap
{

	public:
		// Constructor
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &src);

		// Destructor
		~FragTrap();

		// Operator overload
		FragTrap	&operator=(const FragTrap &other);

		// Actions
		void	highFivesGuys(void);

};

#endif