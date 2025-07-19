#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	unsigned int	_n;
	T*				_arr;

	public:
		Array<T>();
		Array<T>(unsigned int n);
		Array<T>(Array<T> const& src);
		~Array<T>();

		Array<T>&	operator=(Array<T> const& rhs);
		T&			operator[](unsigned int index);

		unsigned int	size() const;
};

# include "Array.tpp"

#endif
