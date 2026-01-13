#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
: _dataPath("")
, _inputPath("")
, _data()
{}

BitcoinExchange::BitcoinExchange(char const* dataPath, char const* inputPath)
: _dataPath(dataPath)
, _inputPath(inputPath)
{
	_parseData();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& other)
: _dataPath(other._dataPath)
, _inputPath(other._inputPath)
, _data(other._data)
{}

BitcoinExchange&	BitcoinExchange::BitcoinExchange::operator=(BitcoinExchange const& other)
{
	if (this != &other) {
		_dataPath = other._dataPath;
		_inputPath = other._inputPath;
		_data = other._data; // Use of std::map's operator=()
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::printOutput() const
{
	// Check that file exist and can be open
	std::ifstream ifs(_inputPath);
	if (!ifs) {
		throw std::runtime_error("Error: could not open file.");
	}
	// Read each line of the input file
	for (std::string line; std::getline(ifs, line);) {
		try {
			std::string date, value;
			_splitLine(line, " | ", date, value);
			if (date == "date" && value == "value") // skip header line
				continue;
			_checkDate(date);
			double dValue = _checkValue(value);
			double res = _getResult(date, dValue);
			std::cout << date << " => " << dValue << " = " << res << std::endl;
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
			continue; // continue to next line
		}
	}
};

/**
 * @note Dates are strings with format YYYY-MM-DD (lexicographic order = chronological order).
 * So we can use comparison operators on them.
 */
double	BitcoinExchange::_getResult(std::string const& date, double const& value) const
{
	Data::const_iterator current = _data.begin();
	if (current->first > date)
		throw std::runtime_error("Error: no result.");

	Data::const_iterator next = ++_data.begin();
	while (next != _data.end()) {
		if (current->first == date || next->first > date) {
			return current->second * value;
		} else if (next->first == date) {
			return next->second * value;
		}
		++current;
		++next;
	}

	// Date is after the latest one
	return current->second * value;
}

/**
 * @note We consider the dates are in increasing order and are correctly formated.
 */
void	BitcoinExchange::_parseData()
{
	std::ifstream ifs(_dataPath);
	if (!ifs) {
		throw std::runtime_error("Error: invalid data file '" + std::string(_dataPath) + "'");
	}
	for (std::string line; std::getline(ifs, line);) {
		try {
			std::string date, value;
			_splitLine(line, ",", date, value);
			_checkDate(date);
			char* end;
			_data[date] = std::strtod(value.c_str(), &end);
		} catch (...) {
			continue; // skip lines with invalid date format
		}
	}
}

// Static functions

void	BitcoinExchange::_splitLine(std::string const& line, std::string const& sep, std::string& lhs, std::string& rhs)
{
	// Check if the line is empty or contains only spaces
	if (line.empty())
		throw std::runtime_error("Error: empty line.");
	size_t pos = line.find(sep);
	if (pos == line.npos) // line has only 1 column
		throw std::runtime_error("Error: bad input => " + line);
	lhs = line.substr(0, pos);
	rhs = line.substr(pos + sep.size(), line.size());
}

bool	hasValidFebruaryDay(int year, int day)
{
	// Check for leap year
	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	return isLeapYear ? day <= 29 : day <= 28;
}

/**
 * @note Bitcoin was created in 2008, so any date before that is invalid.
 * Also checks for month/day validity.
 */
void	BitcoinExchange::_checkDate(std::string const& s)
{
	size_t	dash1Pos = s.find("-");
	size_t	dash2Pos = s.find("-", dash1Pos + 1);
	if (dash1Pos == s.npos || dash2Pos == s.npos) {
		throw std::runtime_error("Error: invalid date => " + s);
	}
	int year = _checkDatePart(s.substr(0, dash1Pos));
	int month = _checkDatePart(s.substr(dash1Pos + 1, dash2Pos - dash1Pos - 1));
	int day = _checkDatePart(s.substr(dash2Pos + 1));
	if (year < 2008 || month < 1 || month > 12 || day < 1 || day > 31
		|| ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		|| (month == 2 && !hasValidFebruaryDay(year, day))) {
			throw std::runtime_error("Error: invalid date => " + s);
	}
}

/**
 * @return -1 if the part is invalid.
 */
int	BitcoinExchange::_checkDatePart(std::string const& part)
{
	if (part.size() < 2) {
		return -1;
	}
	char* end;
	long val = std::strtol(part.c_str(), &end, 10);
	if (*end != '\0') {
		return -1;
	}
	return static_cast<int>(val);
}

double	BitcoinExchange::_checkValue(std::string const& value)
{
	char* end;
	double dValue = std::strtod(value.c_str(), &end);
	if (*end != '\0')
		throw std::runtime_error("Error: invalid number.");
	if (dValue < 0) {
		throw std::runtime_error("Error: not a positive number.");
	} else if (dValue > 1000){
		throw std::runtime_error("Error: too large number.");
	}
	return dValue;
}

