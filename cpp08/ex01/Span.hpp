#pragma once

#include <iostream> // std::cout, std::endl,...
#include <vector> // std::vector<T>
#include <set> // std:set<T>
#include <iterator> // std::distance()
#include <stdexcept> // std::runtime_error()
#include <algorithm> // std::min_element(), std::max_element()
#include <cmath> // std::abs()
#include <limits> // std::numeric_limits<T>::min(),max()

typedef std::vector<int>					Nbs;
typedef std::vector<int>::const_iterator	NbsIt;
typedef std::set<int>						NbsSet;
typedef std::set<int>::const_iterator		NbsSetIt;

class Span
{
	Nbs				_numbers;
	unsigned int	_size;

	public:

		Span();
		Span(unsigned int);
		Span(Span const&);
		Span&	operator=(Span const&);
		~Span();

		Nbs const& 			getNumbers() const;
		unsigned int const&	getSize() const;

		void			addNumber(int);

		template <typename Iterator>
		void			addNumbers(Iterator begin, Iterator end);

		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
};

std::ostream&	operator<<(std::ostream& o, Span const&);

#include "Span.cpp"

