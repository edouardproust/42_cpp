#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	int	exit_code = 0;

	AForm*		f1 = new ShrubberyCreationForm("office");
	Bureaucrat*	b11 = new Bureaucrat("Landscape designer", 146);
	Bureaucrat*	b12 = new Bureaucrat("Gardener", 138);
	AForm*		f2 = new RobotomyRequestForm("office");
	Bureaucrat*	b21 = new Bureaucrat("Architect", 73);
	Bureaucrat*	b22 = new Bureaucrat("Builder", 46);
	AForm*		f3 = new PresidentialPardonForm("Edouard's evaluator");
	Bureaucrat*	b31 = new Bureaucrat("Presidential advisor", 26);
	Bureaucrat*	b32 = new Bureaucrat("Zaphod Beeblebrox", 6);

	try {
		b11->executeForm(*f1); // Form::NotSignedException
		b11->signForm(*f1); // Bureaucrat::GradeTooLowException
		b11->promote();
		b11->signForm(*f1); // ok
		b12->executeForm(*f1); // Bureaucrat::GradeTooLowException	
		b12->promote();
		b12->executeForm(*f1); // ok
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		exit_code = 1;
	}
	std::cout << std::endl;

	try {
		b21->executeForm(*f2); // Form::NotSignedException
		b21->signForm(*f2); // Bureaucrat::GradeTooLowException
		b21->promote();
		b21->signForm(*f2); // ok
		b22->executeForm(*f2); // Bureaucrat::GradeTooLowException	
		b22->promote();
		b22->executeForm(*f2); // ok
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		exit_code = 1;
	}
	std::cout << std::endl;

	try {
		b31->executeForm(*f3); // Form::NotSignedException
		b31->signForm(*f3); // Bureaucrat::GradeTooLowException
		b31->promote();
		b31->signForm(*f3); // ok
		b32->executeForm(*f3); // Bureaucrat::GradeTooLowException	
		b32->promote();
		b32->executeForm(*f3); // ok
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		exit_code = 1;
	}

	delete f1;
	delete f2;
	delete f3;
	delete b11;
	delete b12;
	delete b21;
	delete b22;
	delete b31;
	delete b32;

	return (exit_code);
}
