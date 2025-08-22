#include "RPN.hpp"

int main(int ac, char** av)
{
	// Check input
	if (ac != 2) {
		std::cerr << "Usage: ./RPN <expression>\nExample: ./RPN \"7 12 * 2 /\"" << std::endl;
		return 2;
	}
	// Get result
	try {
		RPN rpn(av[1]);
		std::cout << rpn.getResult() << std::endl;
	} catch (std::exception const& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
