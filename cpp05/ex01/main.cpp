#include "Bureaucrat.hpp"

int	main()
{
	int	exit_code = 0;

	try {
		Form f("28B", 0, 45);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl; // should be print
		exit_code = 1;
	}

	try {
		Form f("28B", 72, 151);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		exit_code = 1;
	}
	
	try {
		Form f("28B", 72, 45);
		Bureaucrat b("Eugene", 80);
		b.signForm(f);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl; // should be print
		exit_code = 1;
	}

	try {
		Form f("28B", 72, 45);
		Bureaucrat b("Eugene", 45);
		b.signForm(f);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl; // should not be print
		exit_code = 1;
	}

	return (exit_code);
}
