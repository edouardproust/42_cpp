#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	std::string	_target;

	PresidentialPardonForm();

	public:
		PresidentialPardonForm(std::string const& target);
		PresidentialPardonForm(PresidentialPardonForm const& src);
		PresidentialPardonForm&	operator=(PresidentialPardonForm const& rhs);
		virtual ~PresidentialPardonForm();

		virtual void	executeAction() const;
};

#endif
