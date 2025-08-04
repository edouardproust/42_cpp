#ifndef A_FORM_HPP
# define A_FORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class AForm
{
	AForm();

	protected:

		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;

		virtual void	executeAction() const = 0;

	public:

		AForm(std::string const& name, int const gradeToSign, int const gradeToExecute);
		AForm(AForm const& src);
		AForm&	operator=(AForm const& rhs);
		virtual ~AForm();

		std::string const&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void			beSigned(Bureaucrat const& b);
		void			execute(Bureaucrat const& b) const;

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

		class NotSignedException: public std::exception
		{
			public:
				virtual char const* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& lhs, AForm const& rhs);

#endif
