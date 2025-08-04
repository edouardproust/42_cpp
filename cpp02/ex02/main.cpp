#include "Fixed.hpp"
#include <iostream>


static	std::string	printBool(bool val)
{
	return (val ? "true" : "false");
}

int	main(void)
{
	// Init
	Fixed a(21);
	Fixed b(a);
	b = -30;
	Fixed c;

	// basic output
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	// Bool
	std::cout << "a > b: " << printBool(a > b) << std::endl;
	std::cout << "a < b: " << printBool(a < b) << std::endl;
	std::cout << "a >= b: " << printBool(a >= b) << std::endl;
	std::cout << "a <= b: " << printBool(a <= b) << std::endl;
	std::cout << "a == b: " << printBool(a == b) << std::endl;
	std::cout << "a != b: " << printBool(a != b) << std::endl;

	// ops
	std::cout << "a + b: " << (a + b) << std::endl;
	std::cout << "a - b: " << (a -b) << std::endl;
	std::cout << "a * b: " << (a * b) << std::endl;
	std::cout << "a / b: " << (a / b) << std::endl;
	// (division by zero)
	std::cout << "a / c: " << (a / c) << std::endl;

	// Post decrement/decrecment
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;
	// Pre decrement/decrecment
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "--a: " << --a << std::endl;

	// math utils
	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
	// (equal values)
	std::cout << "min(a, b): " << Fixed::min(a, a) << std::endl;
	std::cout << "max(a, b): " << Fixed::max(b, b) << std::endl;
}