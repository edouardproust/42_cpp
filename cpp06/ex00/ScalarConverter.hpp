#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string> // std::string, std::string::erase(), std::string::find_last_not_of(), etc.
# include <iostream> // std::cout
# include <sstream> // std::ostringstream
# include <cstdlib> // std::strtod()
# include <limits> // std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), etc.
# include <cmath> // std::fabs(), std::isnan()
# include <iomanip> // std::fixed, std::setprecision()

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
