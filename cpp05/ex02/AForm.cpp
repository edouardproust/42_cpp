
#include "Bureaucrat.hpp"

AForm::AForm():
	_name("Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string const& name, int const gradeToSign, int const gradeToExecute):
	_name(name), _isSigned(false), _gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1) {
		throw GradeTooHighException();
	} else if (_gradeToSign > 150) {
		throw GradeTooLowException();
	}
	if (_gradeToExecute < 1) {
		throw GradeTooHighException();
	} else if (_gradeToExecute > 150) {
		throw GradeTooLowException();
	}
}

AForm::AForm(AForm const& src):
	_name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute) {}

AForm&	AForm::operator=(AForm const& rhs)
{
	if (this != &rhs) {
		_isSigned = rhs._isSigned;
	}
	return (*this);
}

AForm::~AForm() {}

std::string const&	AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	AForm::beSigned(Bureaucrat const& b)
{
	if (_gradeToSign >= b.getGrade()) {
		_isSigned = true;
	} else {
		throw Bureaucrat::GradeTooLowException();
	}
}

void	AForm::execute(Bureaucrat const& b) const
{
	if (!_isSigned) {
		throw NotSignedException();
	} else if (b.getGrade() > _gradeToExecute) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		executeAction();
	}
}

char const*	AForm::GradeTooLowException::what() const throw()
{
	return ("Error: form's grade is too low");
}

char const*	AForm::GradeTooHighException::what() const throw()
{
	return ("Error: form's grade is too high");
}

char const*	AForm::NotSignedException::what() const throw()
{
	return ("Error: form is not signed");
}

std::ostream&	operator<<(std::ostream& lhs, AForm const& rhs)
{
	lhs << rhs.getName() << " form"; 
	return (lhs);
}

