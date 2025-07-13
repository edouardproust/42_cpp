#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\n🔵 Subject test:\n" << std::endl;
	{
		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
	}

	std::cout << "\n🔵 More tests:\n" << std::endl;
	{
		Character* joe = new Character("joe");

		// Adding materias in avail. slots + beyond limit
		for (int i = 0; i < 6; i++) {
			AMateria* m = src->createMateria("ice");
			joe->equip(m);
		}

		// Using materias from valid slot + invalid slots
		joe->use(3, *joe); // should do something
		joe->use(4, *joe); // out of bounds (should do nothing)
		joe->use(-1, *joe); // same as above

		delete joe;
	}

	std::cout << "\n🔵 Deep copy test (operator=):\n" << std::endl;
	{
		Character a("A");
		Character b("B");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		a.equip(tmp);
		tmp = src->createMateria("cure");
		a.equip(tmp);

		b = a;

		a.unequip(0);
		a.unequip(1);

		b.use(0, a); // should still work
		b.use(1, a); // same
	}

	std::cout << "\n🔵 Deep copy test (copy constructor):\n" << std::endl;
	{
		Character a("A");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		a.equip(tmp);
		tmp = src->createMateria("cure");
		a.equip(tmp);

		Character b(a);

		a.unequip(0);
		a.unequip(1);

		b.use(0, a); // should still work
		b.use(1, a); // same
	}

	delete src;

	return 0;
}