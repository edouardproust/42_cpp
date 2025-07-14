#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const Intern::formMapItem	Intern::_formMap[3] = {
	{"shrubbery creation", Intern::_createShrubberyForm},
	{"robotomy request", Intern::_createRobotomyForm},
	{"presidential pardon", Intern::_createPresidentialForm}
};

Intern::Intern() {}

Intern::Intern(Intern const& src)
{
	(void)src;
}

Intern&	Intern::operator=(Intern const& rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern() {}

AForm*	Intern::makeForm(std::string const& name, std::string const& target)
{
	for (int i = 0; i < 3; ++i) {
		if (name == _formMap[i].name) {
			AForm*	newForm = _formMap[i].creator(target);
			std::cout << "Intern creates " << *newForm << std::endl;
			return (newForm);
		}
	}
	std::cerr << "Error: incorrect form name." << std::endl;
	return (NULL);
}

AForm*	Intern::_createShrubberyForm(std::string const& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::_createRobotomyForm(std::string const& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::_createPresidentialForm(std::string const& target)
{
	return (new PresidentialPardonForm(target));
}

