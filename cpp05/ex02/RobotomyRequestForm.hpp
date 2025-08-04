#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	std::string	_target;

	RobotomyRequestForm();

	public:
		RobotomyRequestForm(std::string const& target);
		RobotomyRequestForm(RobotomyRequestForm const& src);
		RobotomyRequestForm&	operator=(RobotomyRequestForm const& rhs);
		virtual ~RobotomyRequestForm();

		virtual void	executeAction() const;
};

#endif
