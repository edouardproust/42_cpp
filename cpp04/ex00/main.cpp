#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "🔵 Valid test (heap):\n" << std::endl;
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	std::cout << i->getType() << ": ";
	i->makeSound();
	std::cout << j->getType() << ": ";
	j->makeSound();
	delete meta;
	delete i;
	delete j;

	std::cout << "\n🔵 Valid test (stack):\n" << std::endl;
	{
		Animal a;
		Cat c;
		Dog d;
		std::cout << a.getType() << ": ";
		a.makeSound();
		std::cout << c.getType() << ": ";
		c.makeSound();
		std::cout << d.getType() << ": ";
		d.makeSound();
	}

	std::cout << "\n🔵 Wrong test (heap):\n" << std::endl;
	const WrongAnimal*	meta2 = new WrongAnimal();
	const WrongAnimal*	k = new WrongCat();
	const WrongCat*		l = new WrongCat();
	std::cout << meta2->getType() << ": ";
	meta2->makeSound();
	std::cout << k->getType() << " (as WrongAnimal): ";
	k->makeSound();
	std::cout << l->getType() << " (as WrongCat): ";
	l->makeSound();
	delete meta2;
	delete k;
	delete l;

	return (0);
}
