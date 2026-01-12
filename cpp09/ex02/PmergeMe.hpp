#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <iostream>
#include <limits>
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
		PmergeMe(PmergeMe const&);
		PmergeMe&	operator=(PmergeMe const&);
		~PmergeMe();

		static double		fjUpperBound(int);
		void				mergeInsertionSort(std::vector<int>&, size_t);
		void				mergeInsertionSort(std::deque<int>&, size_t);
};

template <typename Iter>
bool	PmergeMe::_compareIters(Iter const& a, Iter const& b) {
	totalComparisons++;
    return *a < *b;
}

#endif