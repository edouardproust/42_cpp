#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("presidential pardon", 25, 5), _target("John Doe") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target):
	AForm("presidential pardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src):
	AForm(src._name, src._gradeToSign, src._gradeToExecute), _target(src._target) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
{
	if (this != &rhs) {
		_isSigned = rhs._isSigned;
		_target = rhs._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

