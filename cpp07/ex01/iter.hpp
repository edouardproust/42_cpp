#ifndef ITER_HPP
# define ITER_HPP

# include <string>
# include <iostream>

template <typename T>
void	iter(T* arr, int len, void (*f)(T const&))
{
	for (int i = 0; i < len; ++i) {
		f(arr[i]);
	}
}

#endif
