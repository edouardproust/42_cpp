#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// Now impossible (abstract class instanciation):
	/*
	AAnimal*	a = new AAnimal;
	delete a;
	*/

	static size_t	N = 6;

	std::cout << "\n🔵 Heap test:\n" << std::endl;
	AAnimal* animals[N];
	for(size_t i = 0; i < N/2; i++) {
		animals[i] = new Dog;
	}
	for (size_t i = N/2; i < N; i++) {
		animals[i] = new Cat;
	}
	animals[0]->setIdea(0, "I am a dog");
	animals[0]->setIdea(1, "Snoopy is my name");
	animals[0]->setIdea(2, "I love to sleep and do nothing");
	animals[3]->setIdea(0, "I am Nyan Cat");
	animals[3]->setIdea(1, "I love Jpop and rainbows");
	for (size_t i = 0; i < N; i++) {
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
		for (int j = 0; j < 100; j++) {
			if (!animals[i]->getIdea(j).empty()) {
				std::cout << " * " << animals[i]->getIdea(j) << " *" << std::endl;
			}
		}
	}
	for (size_t i = 0; i < N; i++) {
		delete animals[i];
	}

	std::cout << "\n🔵 Deep copy test (operator=):\n" << std::endl;
	{
		Dog originDog;
		Dog copiedDog;
		originDog.setIdea(0, "I am a dog");
		copiedDog = originDog;
		copiedDog.setIdea(0, "I am a copied dog");
		std::cout << "originDog: " << originDog.getIdea(0) << std::endl;
		std::cout << "copiedDog: " << copiedDog.getIdea(0) << std::endl;
	}

	std::cout << "\n🔵 Deep copy test (copy constructor):\n" << std::endl;
	{
		Dog originDog;
		originDog.setIdea(0, "I am a dog");
		Dog copiedDog(originDog);
		copiedDog.setIdea(0, "I am a copied dog");
		std::cout << "originDog: " << originDog.getIdea(0) << std::endl;
		std::cout << "copiedDog: " << copiedDog.getIdea(0) << std::endl;
	}

	return (0);
}
