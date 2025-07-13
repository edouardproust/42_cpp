#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():
	_name("Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(std::string const& name, int const gradeToSign, int const gradeToExecute):
	_name(name), _isSigned(false), _gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1) {
		throw GradeTooHighException("Form's grade to be signed is too high");
	} else if (_gradeToSign > 150) {
		throw GradeTooLowException("Form's grade to be signed is too low");
	}
	if (_gradeToExecute < 1) {
		throw GradeTooHighException("Form's grade to be executed is too high");
	} else if (_gradeToExecute > 150) {
		throw GradeTooLowException("Form's grade to be executed is too low");
	}
}

Form::Form(Form const& src):
	_name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute) {}

Form&	Form::operator=(Form const& rhs)
{
	if (this != &rhs) {
		_isSigned = rhs._isSigned;
	}
	return (*this);
}

Form::~Form() {}

std::string const&	Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	Form::beSigned(Bureaucrat const& b)
{
	if (_gradeToSign >= b.getGrade()) {
		_isSigned = true;
	} else {
		throw GradeTooLowException("Bureaucrat's grade is too low");
	}
}

Form::GradeTooHighException::GradeTooHighException(std::string const& msg):
	_msg(msg) {}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

char const*	Form::GradeTooHighException::what() const throw()
{
	return (_msg.c_str());
}

Form::GradeTooLowException::GradeTooLowException(std::string const& msg):
	_msg(msg) {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

char const*	Form::GradeTooLowException::what() const throw()
{
	return (_msg.c_str());
}

std::ostream&	operator<<(std::ostream& lhs, Form const& rhs)
{
	lhs << "Form " << rhs.getName() << ": "; 
	lhs << (rhs.getIsSigned() ? "signed" : "not signed");
	lhs << ", signed from grade " << rhs.getGradeToSign();
	lhs << ", executed from grade " << rhs.getGradeToExecute(); 
	return (lhs);
}

