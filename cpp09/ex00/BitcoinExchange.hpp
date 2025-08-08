#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <string> // std::string, std::getline()
#include <map> // std::map<...>
#include <iostream> // std::cout|cerr|endl
#include <fstream> // std:ifstream()
#include <stdexcept> // std::runtime_error
#include <stdlib.h> // strtod()
#include <cstdlib> // std::atof()

#include <iomanip> // TODO remove after testing

class BitcoinExchange
{
	struct FileData {
		double			value;
		unsigned int	year;
		unsigned int	month;
		unsigned int	day;
	};

	typedef std::map<std::string, FileData>	BtcFile;

	char const*						_dataPath;
	char const*						_inputPath;
	BtcFile							_data;
	
	BitcoinExchange() {}


	bool	_isDateLine(std::string const& str) {
		if (str.empty()) {
			return false;
		}
		char* p;
		strtod(str.c_str(), &p);
		return (*p == '-');
	}

	bool	_parseDate(std::string const& s, FileData& fd) {
		size_t	dash1Pos = s.find("-");
		size_t	dash2Pos = s.find("-", dash1Pos + 1);
		if (dash1Pos == s.npos || dash2Pos == s.npos) {
			return false;
		}
		fd.year = std::atoi(s.substr(0, dash1Pos).c_str());
		fd.month = std::atoi(s.substr(dash1Pos + 1, dash2Pos).c_str());
		fd.day = std::atoi(s.substr(dash2Pos + 1, s.size()).c_str());
		return true;
	}

	void	_parseFile(std::ifstream& ifs, std::string const& sep, BtcFile& btcFile) {
		for (std::string line; std::getline(ifs, line);) {
			if (!_isDateLine(line)) continue; // skip lines without date
			size_t pos = line.find(sep);
			if (pos == line.npos) continue; // skip lines with only 1 column
			std::string lhs = line.substr(0, pos);
			std::string rhs = line.substr(pos + 1, line.size());
			FileData fd;
			if (!_parseDate(lhs, fd)) continue; // skip lines with invalid date format
			fd.value = std::atof(rhs.c_str());
			btcFile[lhs] = fd;
		}
	}

	void	_parseFiles() {
		// open files
		std::ifstream dataIfs(_dataPath);
		if (!dataIfs) {
			throw std::runtime_error("Invalid data file '" + std::string(_dataPath) + "'");
		}
		std::ifstream inputIfs(_inputPath);
		if (!inputIfs)  {
			throw std::runtime_error(std::string("Invalid input file '") + std::string(_inputPath) + "'");
		}
		// parse content
		_parseFile(dataIfs, ",", _data);
		for (BtcFile::const_iterator it = _data.begin(); it != _data.end(); ++it) {
			std::cout << it->first << ": " << it->second.year << " " << it->second.month << " " << it->second.day << " " << std::fixed << std::setprecision(2) << it->second.value << std::endl;
		}
	}

	public:

		BitcoinExchange(char const* dataPath, char const* inputPath):
			_dataPath(dataPath), _inputPath(inputPath) {
			_parseFiles();
		}
		BitcoinExchange(BitcoinExchange const& src):
			_dataPath(src._dataPath), _inputPath(src._inputPath) {
			_parseFiles();
		}
		BitcoinExchange&	operator=(BitcoinExchange const& rhs) {
			if (this != &rhs) {
				// TODO
			}
			return *this;
		}
		~BitcoinExchange() {
			// TODO
		}

		void	printOutput() const {
			std::cout << "Output here" << std::endl; //TODO
		}
};

#endif
