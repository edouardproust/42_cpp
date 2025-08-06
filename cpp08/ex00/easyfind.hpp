#pragma once

#include <algorithm>
#include <sstream>

template <typename T>
int	easyfind (T&, int);

class NotFoundException: public std::exception {
	public:
		char const* what() const throw();
};

#include "easyfind.tpp"

