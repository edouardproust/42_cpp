#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include <fstream> // std::ofstream, std::ofstream::fail()

class ShrubberyCreationForm: public AForm
{
	std::string	_target;

	ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(std::string const& target);
		ShrubberyCreationForm(ShrubberyCreationForm const& src);
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& rhs);
		virtual ~ShrubberyCreationForm();

		virtual void	executeAction() const;
};

#endif
