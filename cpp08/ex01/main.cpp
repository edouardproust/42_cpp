#include "Span.hpp"
#include <iostream>
#include <cstdlib>

int main(int ac, char** av) {
	if (ac <= 1) {
		std::cout << "Usage: ./span <number> <number> ..." << std::endl;
		return 1;
	}
	Span span(10);
	for (int i = 0; i < ac; ++i) {
		span.addNumber(atoi(av[i]));
	}
	std::cout << "longest span: " << span.longestSpan() << std::endl;
	return 0;
}
