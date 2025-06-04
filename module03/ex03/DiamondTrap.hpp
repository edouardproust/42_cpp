#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:

		std::string	_name;

	public:
		// Constructor
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &src);

		// Destructor
		~DiamondTrap();

		// Operator overload
		DiamondTrap	&operator=(const DiamondTrap &other);

		// Actions
		void	whoAmI();

};

#endif