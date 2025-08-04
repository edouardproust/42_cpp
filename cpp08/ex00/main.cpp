#include "easyfind.hpp"
#include <cstdlib>
#include <iostream>

int	main(int ac, char **av) {
	if (ac <= 1) {
		std::cerr
		<< "Usage: ./easyfind <haystack_item1> <haystack_item2> ... <needle>"
		<< std::endl;
		return 1;
	}
	std::vector<int> vec;
	try {
		for (int i = 0; i < ac - 1; ++i) {
			vec.push_back(atoi(av[i]));
		}	
		std::cout << easyfind(vec, atoi(av[ac - 1])) << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
