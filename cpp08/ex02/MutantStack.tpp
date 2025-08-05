template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const& src): std::stack<T>(src) {}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(MutantStack const& rhs) {
	if (this != &rhs) {
		std::stack<T>::operator=(rhs);
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const {
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const {
	return std::stack<T>::c.end();
}

