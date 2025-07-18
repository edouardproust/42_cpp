#include "iter.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

void	printSquare(int n)
{
	std::cout << n * n << std::endl;
}

void	printSqrt(float n)
{
	std::cout << std::sqrt(n) << std::endl;
}

void	capitalizeWord(std::string w)
{
	if (97 <= w[0] && w[0] <= 122) {
		w[0] -= 32;
	}
}

int	main()
{
	// printSquare(int)
	int ints[5] = {1, 2, 3, 5, 8};
	iter(ints, 5, printSquare);	

	// printSqrt(float)	
	float floats[5] = {12, 24, 36, 48, 50};
	iter(floats, 5, printSqrt);

	// capitalizeWord(std::string)
	std::string words[6] = {"Hello,", "World!", "My", "name", "is", "Ed"};
	iter(words, 6, capitalizeWord);
	for (int i = 0; i < 6; ++i) {
		std::cout << words[i] << (i < 5 ? " " : ".");
	}
	std::cout << std::endl;

	return (0);
}
