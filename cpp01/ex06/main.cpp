#include "Harl.hpp"
#include <iostream>
#include <string>

void harlFilter(Harl& harl, const std::string& level)
{
	int intLevel = -1;
	for(int i = 0; i < 4 && intLevel == -1; i++)
	{
		if (Harl::levels[i] == level)
			intLevel = i;
	}
	switch (intLevel)
	{
		case 0:
			harl.complain("DEBUG");
			std::cout << std::endl;
			/* fall through */
		case 1:
			harl.complain("INFO");
			std::cout << std::endl;
			/* fall through */
		case 2:
			harl.complain("WARNING");
			std::cout << std::endl;
			/* fall through */
		case 3:
			harl.complain("ERROR");
			break;
		default:
			harl.complain("invalid");
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: invalid number or arguments\n"
			<< "Usage: ./harlFilter <DEBUG|INFO|WARNING|ERROR|...>"<< std::endl;
		return (1);
	}

	Harl harl;
	harlFilter(harl, argv[1]);

	return (0);
}
