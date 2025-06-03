#pragma once
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{

	private:

		bool	gateKeeping;

	public:
		// Constructor
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);

		// Destructor
		~ScavTrap(void);

		// Operator overload
		ScavTrap	&operator=(const ScavTrap &other);

		// Actions
		void	attack(const std::string& target);
		void	guardGate() const;

};