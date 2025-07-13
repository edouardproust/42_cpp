#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{

	protected:

		std::string		_name;
		unsigned int	_hit;
		unsigned int	_energy;
		unsigned int	_attack;

	public:

		// Constructor
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);

		// Destructor
		~ClapTrap();

		// Operator overload
		ClapTrap	&operator=(const ClapTrap &other);

		// Action
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		// Accessors
		std::string		getName() const;
		void			setName(const std::string &name);
		unsigned int	getHit() const;
		unsigned int	getEnergy() const;
		unsigned int	getAttack() const;

};

// IO

std::ostream	&operator<<(std::ostream &o, const ClapTrap &c);

#endif
