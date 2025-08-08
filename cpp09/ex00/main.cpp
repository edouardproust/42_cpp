#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Usage: ./btn <inputFile>" << std::endl;
		return 2;
	}
	try {
		BitcoinExchange btcEx("data.csv", av[1]);
		btcEx.printOutput();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
