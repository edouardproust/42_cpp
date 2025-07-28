#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("Anonymous"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
	: _name(name), _grade(grade)
{
	if (_grade < 1) {
		throw GradeTooHighException();
	} else if (_grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const& src)
	: _name(src._name), _grade(src._grade) {}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& rhs)
{
	if (this != &rhs) {
		_grade = rhs._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}
	
std::string const&	Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::demote()
{
	if (_grade > 150) {
		throw GradeTooLowException();
	}
	_grade++;
}

void	Bureaucrat::promote()
{
	if (_grade < 1) {
		throw GradeTooHighException();
	}
	_grade--;
}

void	Bureaucrat::signForm(Form& f) const
{
	try {
		f.beSigned(*this);
		std::cout << *this << ", signed " << f << "." << std::endl;
	} catch (std::exception& e) {	
		std::cerr << *this << ", couldn't sign " << f << " because " << e.what() << "." << std::endl;
	}
}

char const*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("bureaucrat's grade is too low");
}

char const*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("bureaucrat's grade is too high");
}

std::ostream&	operator<<(std::ostream& lhs, Bureaucrat const& rhs)
{
	lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (lhs);
}
