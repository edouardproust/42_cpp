#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
: _isSorted(false)
, _unsorted() // empty in recursive instances (not used)
, _bigNbs()
, _smallNbs()
, _startTime()
, _endTime()
{}

PmergeMe::PmergeMe(PmergeMe const& other)
: _isSorted(other._isSorted)
, _unsorted(other._unsorted)
, _bigNbs(other._bigNbs)
, _smallNbs(other._smallNbs)
, _startTime()
, _endTime()
{}

PmergeMe&	PmergeMe::operator=(PmergeMe const& other)
{
	if (this != &other) {
		_isSorted = other._isSorted;
		_unsorted = other._unsorted;
		_bigNbs = other._bigNbs;
		_smallNbs = other._smallNbs;
		_startTime = timeval();
		_endTime = timeval();
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}

void	PmergeMe::setUnsorted(int n, char** nbs)
{
	if (n <= 0)
		throw std::runtime_error("Usage: ./PmergeMe <positive_integer1> [positive_integer2 ... positive_integerN]");

	for (int i = 0; i < n; ++i) {
		std::string s = nbs[i];
		if (s.empty())
			throw std::runtime_error("An integer is an empty string");

		// Check that all chars are digits
		for (size_t j = 0; j < s.size(); ++j) {
			if (!std::isdigit(static_cast <unsigned char>(s[j])))
				throw std::runtime_error("Invalid character in number: " + s);
		}

		unsigned long tmp = 0;
		std::stringstream ss(s);
		ss >> tmp;

		// Check int overflow
		if (ss.fail() || !ss.eof() || tmp > static_cast<unsigned long>(std::numeric_limits<int>::max()))
			throw std::runtime_error("Integer overflow: " + ss.str());

		_unsorted.push_back(tmp);
	}
}

void	PmergeMe::sort()
{
	if (_unsorted.empty())
		return;

	gettimeofday(&_startTime, NULL);
	_mergeInsertionSort();
	_isSorted = true;
	gettimeofday(&_endTime, NULL);
}

/**
 * Ford–Johnson merge-insertion sort (recursive).
 */
void	PmergeMe::_mergeInsertionSort()
{
	if (_unsorted.size() <= 1)
		return;

	// 1. Split input into 2 chains: _bigNbs (larger element of each pair) and _smallNbs (the smaller one)
	_splitData();

	// 2. If _bigNbs has more than 1 element, recursively sort it
	if (_bigNbs.size() > 1) {
		PmergeMe recursiveSort;
		recursiveSort._unsorted = _bigNbs; // deep copy of _bigNbs (parent level) into _unsorted (current level)

		if (DEBUG) std::cerr << "Recursion descent:\n" << recursiveSort << "\n" << std::endl;

		recursiveSort._mergeInsertionSort(); // <-- Recursive descent
		_bigNbs = recursiveSort._bigNbs; // _bigNbs is now sorted (after recursion unwind: see step 2. below)
		// (Here, in the deeper level of recursion (_bigNbs.size() == 1), _bigNbs ends up containing only the biggest element of the original unsorted list)

		if (DEBUG) std::cerr << "Recursion unwind:\n" << recursiveSort << "\n" << std::endl;
	}

	// 3. Recursion unwind: each level inserts its pending _smallNbs into the already sorted _bigNbs.
	_insertSmallNbs();

	// At this point, _bigNbs is sorted for this instance of PmergeMe.
}

/**
 * Ford–Johnson step #1 (inside recursive sort).
 * Split _unsorted into two chains:
 * - the larger elements of each pair (_bigNbs) -> main chain (recursively sorted in _mergeInsertionSort())
 * - the smaller ones (_smallNbs) -> pending insertions
 */
void	PmergeMe::_splitData()
{
	for (size_t i = 0; i + 1 < _unsorted.size(); i += 2) { // prevents underflow in case _unsorted.size() == 0
		// chains
		int big = std::max(_unsorted[i], _unsorted[i  + 1]);
        int small = std::min(_unsorted[i], _unsorted[i  + 1]);
		_bigNbs.push_back(big);
		_smallNbs.push_back(small);
	}
	// straggler
	if (_unsorted.size() % 2 != 0) {
		_smallNbs.push_back(_unsorted.back());
		// (straggler is not added into _pairing)
	}
}

// TODO
/**
 * Ford-Johnson step #2:
 * Insert small numbers into the main chain (big numbers),
 * using Jacobsthal order and binary search.
 */
void	PmergeMe::_insertSmallNbs()
{
	if (_smallNbs.empty())
		return;

	// Insert each smallNb into _bigNbs using binary search
	for (size_t i = 0; i < _smallNbs.size(); ++i) {

		// std::upper_bound is a Binary Search
		// (we use upper_bound to maintain stability: equal elements are inserted after existing ones)
		std::vector<int>::iterator pos = std::upper_bound(_bigNbs.begin(), _bigNbs.end(), _smallNbs[i]);
		_bigNbs.insert(pos, _smallNbs[i]);
	}
}

// GETTERS

std::vector<int> const&	PmergeMe::getUnsorted() const
{
	return _unsorted;
}

std::vector<int> const&	PmergeMe::getSorted() const
{
	return _bigNbs;
}

std::vector<int> const&	PmergeMe::getBigNbs() const
{
	return _bigNbs;
}

std::vector<int> const&	PmergeMe::getSmallNbs() const
{
	return _smallNbs;
}

double	PmergeMe::getElapsedTime() const
{
	long sec = _endTime.tv_sec - _startTime.tv_sec;
	long usec = _endTime.tv_usec - _startTime.tv_usec;
	return sec * 1e6 + usec;
}

// PRINT

std::ostream&	operator<<(std::ostream& os, std::vector<int> const& numbers)
{
	for(size_t i = 0; i < numbers.size(); ++i) {
		os << numbers[i];
		if (i != numbers.size() - 1)
			os << " ";
	}
	return os;
}

std::ostream&	operator<<(std::ostream& os, PmergeMe const& pmm)
{
	os << "Before: " << pmm.getUnsorted() << "\n";
	os << "After: " << pmm.getSorted() << "\n";

	// Elasped time
	os << "Time to process a range of " << pmm.getUnsorted().size() << " elements with std::vector : "
		<< std::fixed << std::setprecision(5) << pmm.getElapsedTime() << " us";

	return os;
}