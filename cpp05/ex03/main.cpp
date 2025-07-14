#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main()
{
	int	exit_code = 0;

	Intern	intern;
	AForm*		f0 = intern.makeForm("incorrect form", "1337");
	(void)f0;

	AForm*		f1 = intern.makeForm("shrubbery creation", "office"); // form is now created by intern
	Bureaucrat*	b11 = new Bureaucrat("Landscape designer", 146);
	Bureaucrat*	b12 = new Bureaucrat("Gardener", 138);
	AForm*		f2 = intern.makeForm("robotomy request", "office"); // also here
	Bureaucrat*	b21 = new Bureaucrat("Architect", 73);
	Bureaucrat*	b22 = new Bureaucrat("Builder", 46);
	AForm*		f3 = intern.makeForm("presidential pardon", "Edouard's evaluator"); // also here
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
		std::cout << e.what() << std::endl;
		exit_code = 1;
	}

	try {
		b21->executeForm(*f2); // Form::NotSignedException
		b21->signForm(*f2); // Bureaucrat::GradeTooLowException
		b21->promote();
		b21->signForm(*f2); // ok
		b22->executeForm(*f2); // Bureaucrat::GradeTooLowException	
		b22->promote();
		b22->executeForm(*f2); // ok
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		exit_code = 1;
	}

	try {
		b31->executeForm(*f3); // Form::NotSignedException
		b31->signForm(*f3); // Bureaucrat::GradeTooLowException
		b31->promote();
		b31->signForm(*f3); // ok
		b32->executeForm(*f3); // Bureaucrat::GradeTooLowException	
		b32->promote();
		b32->executeForm(*f3); // ok
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
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
