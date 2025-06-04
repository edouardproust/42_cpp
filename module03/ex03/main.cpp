#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "🔵 Test constructors:\n" << std::endl;
	ClapTrap c;
	c.setName("C1.0");
	FragTrap f1;
	f1.setName("f1.0");
	FragTrap f2("f2.0");
	FragTrap f3(f2);
	f3.setName("f2.1");
	f1 = f3;
	f1.setName("f2.2");

	std::cout << "\n🔵 Actions:\n" << std::endl;
	c.attack("dummy robot");
	c.takeDamage(42);
	f1.attack("this stupid dummy");
	f1.takeDamage(42);
	f1.highFivesGuys();
	f1.attack("the dummy again");
	f1.beRepaired(20);
	f1.takeDamage(4242);
	f1.highFivesGuys();
	f1.beRepaired(20);
	f1.attack("dummy robot");

	std::cout << "\n🔵 Destructor:\n" << std::endl;
	return (0);
}