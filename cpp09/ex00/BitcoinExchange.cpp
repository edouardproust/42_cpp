#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(char const* dataPath, char const* inputPath)
: _dataPath(dataPath), _inputPath(inputPath)
{
	_parseData();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& src)
: _dataPath(src._dataPath), _inputPath(src._inputPath), _data(src._data) {}

BitcoinExchange&	BitcoinExchange::BitcoinExchange::operator=(BitcoinExchange const& rhs)
{
	if (this != &rhs) {
		_dataPath = rhs._dataPath;
		_inputPath = rhs._inputPath;
		_data = rhs._data; // Use of std::map's operator=()
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::printOutput() const {
	// Check that file exist and can be open
	std::ifstream ifs(_inputPath);
	if (!ifs) {
		throw std::runtime_error("Error: invalid input file '" + std::string(_inputPath) + "'");
	}
	// Loop through each line of the input file
	for (std::string line; std::getline(ifs, line);) {
		// Skip lines without date
		if (!_isLineWithDate(line)) {
			continue;
		}
		// Split line into date and value 
		std::string date, value;
		if (!_splitLine(line, " | ", date, value)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		// Check date validity
		try {
			_checkDate(date);
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
			continue;
		}
		// Convert value into a float + check value validity
		float fValue= static_cast<float>(std::atof(value.c_str()));
		try {
			_checkInputLineValue(fValue);
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
			continue;
		}
		// Calculate and display result for this line
		double res = _getResult(date, fValue);
		std::cout << date << " => " << fValue << " = " << res << std::endl;
	}
};

double	BitcoinExchange::_getResult(std::string const& date, double const& value) const
{
	Data::const_iterator current = _data.begin();
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
	throw std::runtime_error("Error: no result found");
}

void	BitcoinExchange::_parseData()
{
	std::ifstream ifs(_dataPath);
	if (!ifs) {
		throw std::runtime_error("Error: invalid data file '" + std::string(_dataPath) + "'");
	}
	for (std::string line; std::getline(ifs, line);) {
		std::string date, value;
		if (!_splitLine(line, ",", date, value)) continue; // skip lines that cannot be split
		try {
			_checkDate(date);
		} catch (...) {
			continue; // skip lines with invalid date format
		}
		_data[date] = std::atof(value.c_str());
	}
}

// Static functions

bool	BitcoinExchange::_isLineWithDate(std::string const& str)
{
	if (str.empty()) {
		return false;
	}
	char* p;
	strtod(str.c_str(), &p);
	return (*p == '-');
}

bool	BitcoinExchange::_splitLine(std::string const& line, std::string const& sep,
std::string& lhs, std::string& rhs)
{
	if (!_isLineWithDate(line)) return false; // line has no date
	size_t pos = line.find(sep);
	if (pos == line.npos) return false; // line has 1 column
	lhs = line.substr(0, pos);
	rhs = line.substr(pos + sep.size(), line.size());
	return true;
}

void	BitcoinExchange::_checkDate(std::string const& s)
{
	size_t	dash1Pos = s.find("-");
	size_t	dash2Pos = s.find("-", dash1Pos + 1);
	if (dash1Pos == s.npos || dash2Pos == s.npos) {	
		throw std::runtime_error("Error: invalid date format => " + s + " (should be YYYY-MM-DD)");
	}
	int year = std::atoi(s.substr(0, dash1Pos).c_str());
	int month = std::atoi(s.substr(dash1Pos + 1, dash2Pos).c_str());
	int day = std::atoi(s.substr(dash2Pos + 1, s.size()).c_str());
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31
		|| ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		|| (month == 2 && day > 29)) {
			throw std::runtime_error("Error: invalid date => " + s);
		}
	}

void	BitcoinExchange::_checkInputLineValue(double const& value)
{
	if (value < 0) {
		throw std::runtime_error("Error: not a positive number");
	} else if (value > 1000){
		throw std::runtime_error("Error: too large number");
	}
}

