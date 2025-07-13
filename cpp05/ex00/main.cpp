#include "Bureaucrat.hpp"

int	main()
{
	int	exit_code = 0;

	try {
		Bureaucrat b("TooHigh", 0);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl; // Should be print
		exit_code = 1;
	}

	try {
		Bureaucrat b("TooLow", 151);	
	} catch (std::exception& e) {	
		std::cout << e.what() << std::endl; // Should be print
		exit_code = 1;
	}

	try {	
		Bureaucrat b("Eugene", 150);	
		b.demote();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl; // Should be print
		exit_code = 1;
	}

	try {
		Bureaucrat b("Albert", 1);	
		b.promote();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl; // Should be print
		exit_code = 1;
	}

	return (exit_code);
}
