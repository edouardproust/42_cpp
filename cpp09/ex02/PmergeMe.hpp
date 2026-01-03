#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <string>
#include <iostream> // std::ostream, std::cout, std::endl, std::fixed
#include <vector>
#include <sstream>
#include <limits>
#include <stdexcept>
#include <sys/time.h>
#include <iomanip> // std::fixed, std::setprecision
#include <algorithm> // std::lower_bound, std::upper_bound

#ifndef DEBUG
#define DEBUG 1
#endif

class PmergeMe
{
	bool						_isSorted;
	std::vector<int>			_unsorted;	// original unsorted numbers
	std::vector<int>			_bigNbs;	// main chain (working data)
	std::vector<int>			_smallNbs;	// pend to insert into main chain
	struct timeval				_startTime;	// timing: algorithm start
	struct timeval				_endTime;	// timing: algorithm end

	void	_mergeInsertionSort();
	void	_splitData();
	void	_insertSmallNbs();

	public:

		PmergeMe();
		PmergeMe(PmergeMe const&);
		PmergeMe&	operator=(PmergeMe const&);
		~PmergeMe();

		void	setUnsorted(int, char**);
		void	sort();

		std::vector<int> const&			getUnsorted() const;
		std::vector<int> const&			getSorted() const;
		std::vector<int> const&			getBigNbs() const;
		std::vector<int> const&			getSmallNbs() const;
		double							getElapsedTime() const;
};

// Print

std::ostream&	operator<<(std::ostream&, std::vector<int> const&);
std::ostream&	operator<<(std::ostream&, PmergeMe const&);

#endif