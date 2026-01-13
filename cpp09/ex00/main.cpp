#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Usage: ./btn <file_path>" << std::endl;
		return 2;
	}
	BitcoinExchange btcEx("data.csv", av[1]);
	btcEx.printOutput();
	return 0;
}
