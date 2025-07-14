#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm():
	AForm("robotomy request", 72, 45), _target("home") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target):
	AForm("robotomy request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src):
	AForm(src._name, src._gradeToSign, src._gradeToExecute), _target(src._target) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
{
	if (this != &rhs) {
		_isSigned = rhs._isSigned;
		_target = rhs._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::executeAction() const
{
	std::srand(time(0));
	std::cout << "ZZzzzRRrrr... (drilling noise)" << std::endl;
	if (std::rand() % 2 == 0) { // 50% probability
		std::cout << _target << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << "Robotomy failed on " << _target << "." << std::endl;
	}
}

