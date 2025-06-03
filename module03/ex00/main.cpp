#include "ClapTrap.hpp"
#include <iostream>

/**
 * To debug ClapTrap:
 * std::cout << (ClapTrap &c)
 */
int	main(void)
{
	std::cout << "🔵 Test constructors:\n" << std::endl;
	ClapTrap bob;
	ClapTrap bip("Bip");
	ClapTrap bob2(bob);
	bob2 = bip;
	bob2.setName("BipCopy");

	std::cout << "\n🔵 Test actions:\n" << std::endl;
	bob.attack("unknown enemy");
	bob.takeDamage(5);
	bob.beRepaired(2);
	bob.takeDamage(3);
	bob.attack("a stupid other enemy");
	bob.takeDamage(3);
	bob.takeDamage(1337);
	bob.beRepaired(5);

	std::cout << "\n🔵 More actions:\n" << std::endl;

	bob2 = bob;
	bob2.setName("BobCopy");
	bob2.attack("a dummy robot");
	bob2.attack("another dummy");
	bob2.attack("dummy baby robot");
	bob2.takeDamage(42);
	bob2.beRepaired(3);
	bob2.beRepaired(1);
	bob2.takeDamage(4);
	bob2.beRepaired(3);
	bob2.beRepaired(3); // no more energy
	bob2.attack("blob"); // no more energy
	bob2.takeDamage(-4); // Negative int -> remove all remaining HPs

	std::cout << "\n🔵 Destructor:\n" << std::endl;
	return (0);
}