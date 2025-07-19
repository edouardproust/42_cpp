#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

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

		class OutOfBoundsException: public std::exception {
			public:
				virtual char const*	what() const throw();
		};
};

# include "Array.tpp"

#endif
