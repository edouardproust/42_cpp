#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const& src)
{
	(void)src;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const& rhs)
{
	(void)rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string const& literal)
{
	char*	end = NULL;
	double	d = std::strtod(literal.c_str(), &end);
	bool	isValid = *end == '\0' || (*end != '\0' && *end == 'f' && *(end + 1) == '\0');

	std::cout << "char: " << _dtoc(d, isValid) << "\n";
	std::cout << "int: " << _dtoi(d, isValid) << "\n";
	std::cout << "float: " << _dtof(d, isValid) << "\n";
	std::cout << "double: " << _formatd(d, isValid) << std::endl;
}

std::string	ScalarConverter::_dtoc(double d, bool isValid)
{
	std::ostringstream o;
	if (!isValid || d < 0 || d > 127 || std::isnan(d)) {
		o << "impossible";
	} else if (d == 127 || (0 <= d && d < 32)) {
		o << "non displayable";
	} else {
		o << "'" << static_cast<char>(d) << "'";
	}
	return (o.str());
}

std::string	ScalarConverter::_dtoi(double d, bool isValid)
{
	std::ostringstream o;
	if (!isValid || d < std::numeric_limits<int>::min()
		|| d > std::numeric_limits<int>::max() || std::isnan(d)) {
		o << "impossible";
	} else {
		o << static_cast<int>(d);
	}
	return (o.str());
}

std::string	ScalarConverter::_dtof(double d, bool isValid)
{
	std::ostringstream o;
	if (!isValid) {
		o << "impossible";
	} else if (d > std::numeric_limits<float>::max()) {
		o << "inff";
	} else if (d < -std::numeric_limits<float>::max()) {
		o << "-inff";
	} else if (std::abs(d) < std::numeric_limits<float>::min()) {
		o << "DEBUG: " << d << "\n";
		o << (d < 0.0 ? "-0.0" : "0.0");
    } else {
		o << std::fixed << std::setprecision(6);
		o << static_cast<float>(d);
		std::string s = o.str();
		s.erase(s.find_last_not_of('0') + 1);
		if (s[s.size() - 1] == '.') s += '0';
		return (s + "f");
	}
	return (o.str());
}

std::string	ScalarConverter::_formatd(double d, bool isValid)
{
	std::ostringstream o;
	if (!isValid) {
		o << "impossible";
		return (o.str());
	}
	o << std::fixed << std::setprecision(15) << d;
	std::string s = o.str();
	s.erase(s.find_last_not_of('0') + 1);
	if (s[s.size() - 1] == '.') s+= '0';
	return (s);
}

