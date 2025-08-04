template <typename T>
Array<T>::Array(): _size(0), _items(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n): _size(n), _items(n ? new T[n]() : NULL) {}

template <typename T>
Array<T>::Array(Array<T> const& src): _size(src._size), _items(new T[src._size]) {
	for (unsigned int i = 0; i < _size; ++i) {
		_items[i] = src._items[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete[] _items;
}

template <typename T>
Array<T>&	Array<T>::operator=(Array<T> const& rhs) {
	if (this != &rhs) {
		_size = rhs._size;
		for (unsigned int i = 0; i < _size; ++i) {
			_items[i] = rhs._items[i];
		}
	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int index) {
	if (index >= _size) {
		throw std::out_of_range("Invalid index");
	}
	return (_items[index]);
}

template <typename T>
T const&	Array<T>::operator[](unsigned int index) const {
	if (index >= _size) {
		throw std::out_of_range("Invalid index");
	}
	return (_items[index]);
}

template <typename T>
unsigned int	Array<T>::size() const {
	return (_size);
}

