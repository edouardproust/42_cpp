#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
{
	std::string const	_name;
	int					_grade;

	Bureaucrat();

	public:

		Bureaucrat(std::string const& name, int grade);
		Bureaucrat(Bureaucrat const& src);
		Bureaucrat&	operator=(Bureaucrat const& rhs);
		~Bureaucrat();
	
		std::string const&	getName() const;
		int					getGrade() const;

		void	promote();
		void	demote();

		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const*	what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& lhs, Bureaucrat const& rhs);

#endif
