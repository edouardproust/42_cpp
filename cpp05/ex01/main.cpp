#include "Bureaucrat.hpp"

int	main()
{
	int	exit_code = 0;

	try {
		Form f("28B", 0, 45); // error
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl; //Form::GradeTooHighException
		exit_code = 1;
	}

	try {
		Form f("28B", 72, 151); // error
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl; // Form::GradeTooLowException
		exit_code = 1;
	}
	
	try {
		Form f("28B", 72, 45); // ok
		Bureaucrat b("Eugene", 80); // ok
		b.signForm(f); // error
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl; // Bureaucrat::GradeTooLowException
		exit_code = 1;
	}

	try {
		Form f("28B", 72, 45); // ok
		Bureaucrat b("Eugene", 72); // ok
		b.signForm(f); // ok
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl; // not print
		exit_code = 1;
	}

	return (exit_code);
}
