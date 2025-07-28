#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template <typename T>
class Array
{
	T*	_arr;
	unsigned int	_size;

	public:

		Array(): _arr(NULL), _size(0) {}
		Array(unsigned int size): _arr(new T[size]), _size(size) {
			for (unsigned int i = 0; i < _size; ++i) {
				_arr[i] = 0;
			}
		}
		~Array() { delete[] _arr; }
		
		Array&	operator=(Array const& rhs) {
			if (this != &rhs) {
				_size = rhs._size;
				for (unsigned int i = 0; i < _size; ++i) {
					_arr[i] = rhs._arr[i];
				}
			}
			return (*this);
		}
		T&	operator[](unsigned int index) {
			if (index >= _size) {
				throw std::out_of_range("Error: index is out of range");
			}
			return (_arr[index]);
		}

		unsigned int	size() const {
			return (_size);
		}
};

#endif

