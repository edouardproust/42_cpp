#include "Span.hpp"

Span::Span(): _numbers(), _size() {}

Span::Span(unsigned int size): _numbers(), _size(size) {}

Span::Span(Span const& src): _numbers(src._numbers), _size(src._size){}

Span&	Span::operator=(Span const& rhs) {
	if (this != &rhs) {
		_numbers = rhs._numbers;
		_size = rhs._size;
	}
	return *this;
}

void	Span::addNumber(int n) {
	if (_numbers.size() < _size) {
		_numbers.push_back(n);
	} else {
		throw std::out_of_range("List is full");
	}
}
/*
unsigned int	Span::shortestSpan() const {
	
}
*/
unsigned int	Span::longestSpan() const {	
	NumbersConstIt min = std::min_element(_numbers.begin(), _numbers.end());
	NumbersConstIt max = std::max_element(_numbers.begin(), _numbers.end());
	return std::abs(*max - *min);	
}

