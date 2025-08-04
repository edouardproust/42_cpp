#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cmath>

typedef std::vector<int> 					Numbers;
typedef std::vector<int>::iterator 			NumbersIt;
typedef std::vector<int>::const_iterator 	NumbersConstIt;

class Span {

	Numbers			_numbers;
	unsigned int	_size;

	public:

		Span();
		Span(unsigned int);
		Span(Span const&);
		Span&	operator=(Span const&);

		void			addNumber(int);
		//unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
};

#endif
