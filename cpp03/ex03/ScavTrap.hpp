#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap: virtual public ClapTrap
{

	protected:

		unsigned int	_scav_energy;

	public:
		// Constructor
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);

		// Destructor
		~ScavTrap();

		// Operator overload
		ScavTrap	&operator=(const ScavTrap &other);

		// Actions
		void	attack(const std::string& target);
		void	guardGate();

};

#endif