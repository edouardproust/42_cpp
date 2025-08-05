#pragma once

#include <algorithm>
#include <sstream>

template <typename Container>
int	easyfind (Container&, int);

class NotFoundException: public std::exception {
	public:
		char const* what() const throw();
};

#include "easyfind.tpp"

