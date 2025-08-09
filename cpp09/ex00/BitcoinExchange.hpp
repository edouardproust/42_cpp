#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <string> // std::string, std::getline()
#include <map> // std::map<>
#include <iostream> // std::cout|cerr|endl
#include <fstream> // std:ifstream()
#include <stdexcept> // std::runtime_error
#include <stdlib.h> // strtod()
#include <cstdlib> // std::atof()

class BitcoinExchange
{
	typedef std::map<std::string, double>	Data;

	char const*	_dataPath;
	char const*	_inputPath;
	Data		_data;
	
	BitcoinExchange();

	void			_parseData();
	double			_getResult(std::string const& date, double const& value) const;

	static bool		_isLineWithDate(std::string const& str);
	static bool		_splitLine(std::string const& line, std::string const& sep,
						std::string& lhs, std::string& rhs);
	static void		_checkDate(std::string const& s);
	static void		_checkInputLineValue(double const& value);

	public:

		BitcoinExchange(char const* dataPath, char const* inputPath);
		BitcoinExchange(BitcoinExchange const& src);
		BitcoinExchange&	operator=(BitcoinExchange const& rhs);
		~BitcoinExchange();

		void	printOutput() const;
};

#endif
