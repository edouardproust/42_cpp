template <typename T>
Array<T>::Array(): _n(0), _arr(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n): _n(n), _arr(n ? new T[n]() : NULL) {}

template <typename T>
Array<T>::Array(Array<T> const& src): _n(src._n), _arr(new T[src._n]) {
	for (int i = 0; i < _n; ++i) {
		_arr[i] = src._arr[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete[] _arr;
}

template <typename T>
Array<T>&	Array<T>::operator=(Array<T> const& rhs) {
	if (this != &rhs) {
		_n = rhs._n;
		for (int i = 0; i < _n; ++i) {
			_arr[i] = rhs._arr[i];
		}
	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int index) {
	if (index >= _n) {
		throw OutOfBoundsException();
	}
	return (_arr[index]);
}

template <typename T>
unsigned int	Array<T>::size() const {
	return (_n);
}

template <typename T>
char const*	Array<T>::OutOfBoundsException::what() const throw() {
	return ("Error: Trying to access an out-of-bounds index");
}

