#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <iostream>
#include <stdexcept>
#include <limits>
#include <cstdlib>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>

class PmergeMe
{
	template <typename Iter>
	static bool		_compareIters(Iter const&, Iter const&);
	static size_t	_getJacobsthalNumber(size_t);

	public:

		static size_t	totalComparisons;

		PmergeMe();
		~PmergeMe();

		static void			validateArgs(int, char**);
		static double		fjUpperBound(int);
		std::vector<int>	argsToVector(int, char**);
		std::deque<int>		argsToDeque(int, char**);
		void				mergeInsertionSort(std::vector<int>&, size_t);
		void				mergeInsertionSort(std::deque<int>&, size_t);
		size_t				getTotalComparisons() const;
};

template <typename Iter>
bool	PmergeMe::_compareIters(Iter const& a, Iter const& b) {
	totalComparisons++;
    return *a < *b;
}

#endif