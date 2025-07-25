#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class Form
{
	std::string const	_name;
	bool				_isSigned;
	int const			_gradeToSign;
	int const			_gradeToExecute;

	Form();

	public:

		Form(std::string const& name, int const gradeToSign, int const gradeToExecute);
		Form(Form const& src);
		Form&	operator=(Form const& rhs);
		~Form();

		std::string const&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void	beSigned(Bureaucrat const& b);

		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const*	what() const throw();
		};

		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const*	what() const throw();
		};	
};

std::ostream&	operator<<(std::ostream& lhs, Form const& rhs);

#endif
