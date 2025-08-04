#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class Intern
{
	typedef AForm*	(*formCreator)(std::string const&);
	static AForm*	_createShrubberyForm(std::string const& target);
	static AForm*	_createRobotomyForm(std::string const& target);
	static AForm*	_createPresidentialForm(std::string const& target);

	struct formMapItem {
		std::string const	name;
		formCreator			creator;
	};
	static formMapItem const	_formMap[3];

	public:
		
		Intern();
		Intern(Intern const& src);
		Intern&	operator=(Intern const& rhs);
		~Intern();

		AForm*	makeForm(std::string const& name, std::string const& target);

};

#endif

