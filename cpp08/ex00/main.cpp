#include "easyfind.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>

template <typename Container>
void	printResult(std::string containerName, Container c, int needle) {
	typedef typename Container::const_iterator Iterator;
	std::cout << containerName << ": ";
	if (!c.empty()) {
		Iterator last = --c.end(); // tip for getting a pointer to the last element
		for (Iterator it = c.begin(); it != c.end(); ++it) {
			std::cout << *it << (it != last ? ", " : "");
		}
	}
	std::cout << std::endl;
	try {
		std::cout << "result: " << easyfind(c, needle) << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << " (" << needle << ")" << std::endl;
	}
}

int main(int ac, char** av) {
	if (ac <= 1) {
		std::cout << "Usage: ./easyfind <int1> <int2> ... <needle>" << std::endl;
		return 1;
	}

	std::vector<int>	v;
	std::set<int>		s;

	for (int i = 1; i < ac - 1; ++i) {
		int	n = atoi(av[i]);
		v.push_back(n);
		s.insert(n);
	}
	printResult("vector", v, atoi(av[ac - 1]));
	printResult("set", s, atoi(av[ac - 1]));

	return 0;
}
