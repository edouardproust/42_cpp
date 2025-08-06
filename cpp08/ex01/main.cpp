#include "Span.hpp"
#include <cstdlib> // std::srand(), std::rand()
#include <ctime> // time()

int main(int ac, char** av) {

	if (ac <= 1) {
		std::cerr << "Usage: ./span <int1> <int2> ..." << std::endl;
		return 1;
	}

	// test with input

	Span span1(ac - 1);
	try {
		for (int i = 1; i < ac; ++i) {
			span1.addNumber(atoi(av[i]));
		}
		std::cout << span1.getSize() << " input numbers (added 1 by 1): " << span1 << std::endl;
		std::cout << "shortest span: " << span1.shortestSpan() << std::endl;
		std::cout << "longest span: " << span1.longestSpan() << std::endl;
	} catch (std::exception& e) {	
		std::cerr << e.what() << std::endl;
	}


	// test with 10000+ random numbers

	std::cout << std::endl;
	unsigned int n = 20000;
	Span span2(n);
	try {
		std::srand(time(0));
		for (unsigned int i = 0; i < n; ++i) {
			span2.addNumber(std::rand());
		}
		std::cout << span2.getSize() << " random numbers: " << span2 << std::endl;
		std::cout << "shortest span: " << span2.shortestSpan() << std::endl;
		std::cout << "longest span: " << span2.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// test by using iterators

	std::cout << std::endl;
	const size_t size = 10;
	int	r1[size] = {-50, -40, -30, -20, -10, 0, 10, 20, 30, 40};
	Span span3(size);
	try {
		span3.addNumbers(r1, r1 + size);
		std::cout << "range of " << size << " numbers: " << span3 << std::endl;
		std::cout << "shortest span: " << span3.shortestSpan() << std::endl;
		std::cout << "longest span: " << span3.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// test by adding out of capacity

	std::cout << std::endl;
	Span span4(0);
	try {
		span4.addNumber(1);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::vector<int> r2;
	r2.push_back(1);
	try {
		span4.addNumbers(r2.begin(), r2.end());
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
