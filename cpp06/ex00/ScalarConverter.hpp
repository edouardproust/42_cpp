#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <cstdlib>
# include <limits>
# include <cmath>
# include <iomanip>

class ScalarConverter
{
	public:
	
		static void	convert(std::string const& literal);

	private:

		ScalarConverter();
		ScalarConverter(ScalarConverter const& src);
		ScalarConverter&	operator=(ScalarConverter const& rhs);
		~ScalarConverter();

		static std::string	_dtoc(double d, bool isValid);
		static std::string	_dtoi(double d, bool isValid);
		static std::string	_dtof(double d, bool isValid);
		static std::string	_formatd(double d, bool isValid);
};
#endif
