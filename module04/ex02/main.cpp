#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	static size_t	N = 6;

	AAnimal	*animals[N];
	for(size_t i = 0; i < N/2; i++) {
		animals[i] = new Dog;
	}
	for (size_t i = N/2; i < N; i++) {
		animals[i] = new Cat;
	}
	for (size_t i = 0; i < N; i++) {
		std::cout << *animals[i];
	}
	for (size_t i = 0; i < N; i++) {
		delete animals[i];
	}

	// Now impossible (abstract class instanciation):
	// AAnimal a = new AAnimal;

	return (0);
}
