#include "Harl.hpp"
#include <iostream>

int main(void)
{
	Harl harl;

	for(size_t i = 0; i < (sizeof(Harl::levels) / sizeof(Harl::levels[0])); i++)
	{
		harl.complain(Harl::levels[i]);
		std::cout << std::endl;
	}
	harl.complain("invalid complain");

	return (0);
}
