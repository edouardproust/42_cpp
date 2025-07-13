#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "🔵 Test constructors:\n" << std::endl;
	DiamondTrap d1("D2.0");
	std::cout << d1 << std::endl;
	d1.whoAmI();

	std::cout << "\n🔵 Actions:\n" << std::endl;
	d1.attack("a dummy robot");
	d1.takeDamage(42);
	d1.highFivesGuys();
	d1.attack("the dummy again");
	d1.beRepaired(20);
	d1.takeDamage(4242);
	d1.highFivesGuys();
	d1.beRepaired(20);
	d1.attack("dummy robot");

	std::cout << "\n🔵 Destructor:\n" << std::endl;
	return (0);
}