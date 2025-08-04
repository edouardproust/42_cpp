#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "🔵 Test constructors:\n" << std::endl;
	ClapTrap c;
	c.setName("C1.0");
	ScavTrap s1;
	s1.setName("S1.0");
	ScavTrap s2("S2.0");
	ScavTrap s3(s2);
	s3.setName("S2.1");
	s1 = s3;
	s1.setName("S2.2");

	std::cout << "\n🔵 Actions:\n" << std::endl;
	c.attack("dummy robot");
	c.takeDamage(42);
	s1.attack("this stupid dummy");
	s1.takeDamage(42);
	s1.guardGate();
	s1.attack("the dummy again");
	s1.beRepaired(20);
	s1.takeDamage(4242);
	s1.guardGate();
	s1.beRepaired(20);
	s1.attack("dummy robot");

	std::cout << "\n🔵 Destructor:\n" << std::endl;
	return (0);
}