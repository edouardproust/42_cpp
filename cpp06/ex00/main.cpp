#include "ScalarConverter.hpp"

/**
 * ex00: Use of `static_cast` to do conversions between literals
 */
int	main(int ac, char** av)
{
	if (ac != 2) {
		std::cout << "Wrong number of args. Usage: ./convert <literal>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	
	return (0);
}
