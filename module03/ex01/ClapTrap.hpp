#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <string>
# include <ostream>

class ClapTrap
{

	private:

		std::string		_name;
		unsigned int	_hit;
		unsigned int	_energy;
		unsigned int	_attack;

	public:

		// Constructor
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);

		// Destructor
		~ClapTrap(void);

		// Operator overload
		ClapTrap	&operator=(const ClapTrap &other);

		// Action functions
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

std::ostream	&operator<<(std::ostream &o, const ClapTrap &c);

#endif
