#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "🔵 Valid test (heap):\n" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << *i;
	std::cout << *j;
	delete i;
	delete j;
	delete meta;

	std::cout << "\n🔵 Valid test (stack):\n" << std::endl;
	Animal a;
	Cat c;
	Dog d;
	a.makeSound();
	c.makeSound();
	d.makeSound();

	std::cout << "\n🔵 Wrong test (heap):\n" << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal*	k = new WrongCat();
	std::cout << *k;
	std::cout << *meta2;
	delete k;
	delete meta2;

	return (0);
}
