#include "Span.hpp"

Span::Span(): _numbers(), _size(0) {}

Span::Span(unsigned int size): _numbers(), _size(size) {}

Span::Span(Span const& src): _numbers(src._numbers), _size(src._size) {}
// using copy constructor of std::vector

Span&	Span::operator=(Span const& rhs) {
	if (this != &rhs) {
		_numbers = rhs._numbers; // using copy operator of std::vector
		_size = rhs._size;
	}
	return *this;
}

Span::~Span() {}

Nbs const&	Span::getNumbers() const {
	return _numbers;
}

unsigned int const&	Span::getSize() const {
	return _size;
}

void	Span::addNumber(int n) {
	if (_numbers.size() < _size) {
		_numbers.push_back(n);
	} else {
		throw std::runtime_error("Container is full");
	}
}

template <typename Iterator>
void	Span::addNumbers(Iterator begin, Iterator end) {
	if (_numbers.size() + std::distance(begin, end) <= _size) {
		for (Iterator it = begin; it != end; ++it) {
			this->addNumber(*it);
		}
	} else {
		throw std::runtime_error("Container is too small");
	}
}

unsigned int	Span::shortestSpan() const {
	unsigned int shortest = std::numeric_limits<int>::max();
	NbsSet const s(_numbers.begin(), _numbers.end());
	NbsSetIt current = s.begin();
	NbsSetIt next = s.begin();
	++next;
	while (next != s.end()) {
		unsigned int tmp = std::abs(*current - *next);
		if (tmp < shortest) {
			shortest = tmp;
		}
		++current;
		++next;
	}
	return shortest;
}

unsigned int	Span::longestSpan() const {
	NbsIt min = std::min_element(_numbers.begin(), _numbers.end());
	NbsIt max = std::max_element(_numbers.begin(), _numbers.end());
	return (std::abs(*max - *min));
}

std::ostream&	operator<<(std::ostream& o, Span const& rhs) {
	Nbs nbs = rhs.getNumbers();
	unsigned int size = rhs.getSize();
	if (size > 10) size = 10;
	for (unsigned int i = 0; i < size; ++i) {
		o << nbs[i] << (i < (size - 1) ? ", " : "");
	}
	if (rhs.getSize() > 10) o << " ... ";
	return o;
}
