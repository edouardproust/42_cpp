#include "ClapTrap.hpp"
#include <iostream>

/**
 * To debug ClapTrap:
 * std::cout << (ClapTrap &c)
 */
int	main(void)
{
	std::cout << "🔵 Test constructors:\n" << std::endl;
	ClapTrap c1;
	c1.setName("C1.0");
	ClapTrap c2("C2.0");
	ClapTrap c3(c1);
	c3 = c2;
	c3.setName("C2.1");

	std::cout << "\n🔵 Test actions:\n" << std::endl;
	c1.attack("unknown enemy");
	c1.takeDamage(5);
	c1.beRepaired(2);
	c1.takeDamage(3);
	c1.attack("a stupid other enemy");
	c1.takeDamage(3);
	c1.takeDamage(1337);
	c1.beRepaired(5);

	std::cout << "\n🔵 More actions:\n" << std::endl;

	c3 = c1;
	c3.setName("C1.1");
	c3.attack("a dummy robot");
	c3.takeDamage(42);
	c3.beRepaired(3);

	std::cout << "\n🔵 Destructor:\n" << std::endl;
	return (0);
}