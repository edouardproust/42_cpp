#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac < 1) {
		std::cerr << "Error: could not launch program." << std::endl;
		return 1;
	} else if (ac > 2) {
		std::cerr << "Usage: ./btn [file_path]" << std::endl;
		return 2;
	}

	try {
		BitcoinExchange btcEx("data.csv", ac == 2 ? av[1] : "");
		btcEx.printOutput();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
