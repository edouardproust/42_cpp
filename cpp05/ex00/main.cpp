#include "Bureaucrat.hpp"

int	main()
{
	int	exit_code = 0;

	try {
		Bureaucrat b("TooHigh", 0); // error
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl; // TooHighException
		exit_code = 1;
	}

	try {
		Bureaucrat b("TooLow", 151); // error
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl; // TooLowException
		exit_code = 1;
	}

	try {	
		Bureaucrat b("Eugene", 150); // ok
		b.demote(); // error
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl; // TooLowException
		exit_code = 1;
	}

	try {
		Bureaucrat b("Albert", 1); // ok
		b.promote(); // error
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl; // TooHighException
		exit_code = 1;
	}

	try {
		Bureaucrat b("Robert", 42); // ok
		b.promote(); // ok
		std::cout << b << std::endl; // print
		b.demote(); // ok
		std::cout << b << std::endl; // print
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl; // not print
		exit_code = 1;
	}
	return (exit_code);
}
