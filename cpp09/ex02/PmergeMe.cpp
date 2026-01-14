#include "PmergeMe.hpp"

size_t	PmergeMe::totalComparisons = 0;

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(PmergeMe const&)
{}

PmergeMe&	PmergeMe::operator=(PmergeMe const&)
{
	return *this;
}

PmergeMe::~PmergeMe()
{}

/**
 * Theoretical upper bound of comparisons for Ford-Johnson algorithm.
 *
 * Formula: n*log2(n) - 1.329n
 */
double	PmergeMe::fjUpperBound(int n) {
	double upperBound = round(n * (std::log(n) / std::log(2.0)) - 1.329 * n);
	return upperBound < 0 ? 0 : upperBound;
}

/**
 * Get the nth Jacobsthal number.
 */
size_t	PmergeMe::_getJacobsthalNumber(size_t n)
{
	return (std::pow(2, n) - std::pow(-1, n)) / 3;
}

/**
 * [VECTOR VERSION]
 * Merge-Insertion Sort algorithm (Ford-Johnson) on a vector of ints.
 *
 * @note Used terminology:
 * - A "pair" contains is made of 2 "blocks".
 * - A block can contain numbers or sub-blocks.
 */
void	PmergeMe::mergeInsertionSort(std::vector<int>& v, size_t intsPerBlock)
{
	totalComparisons = 0; // reset counter
	typedef std::vector<int>::iterator Iter;
	size_t nbOfBlocks = v.size() / intsPerBlock;

	// Exit case
	if (nbOfBlocks < 2) // Check that we can make at least one pair of blocks
		return;

	bool hasOddNbOfBlocks = nbOfBlocks % 2 == 1; // ints that cannot even form a block are ignored in this count
	Iter firstInt = v.begin();
	Iter endOflastBlock = firstInt + nbOfBlocks * intsPerBlock;
	Iter endOflastPairableBlock = endOflastBlock - hasOddNbOfBlocks * intsPerBlock;

	/**
	 * 1. Order pairs of block recursively.
	 */

	for (Iter it = firstInt; it != endOflastPairableBlock ; it += 2 * intsPerBlock) { // `2 * intsPerBlock` is the size of a pair (2 blocks)
		Iter endOfFirstBlock = it + intsPerBlock;
		Iter lastIntOfFirstBlock = endOfFirstBlock - 1;
		Iter lastIntOfSecondBlock = lastIntOfFirstBlock + intsPerBlock;
		// If pair's first block > second block: we swap blocks
		// (We compare the last int of each block as it is the biggest one of the block)
		if (_compareIters(lastIntOfSecondBlock, lastIntOfFirstBlock)) {
			// Swap pair = swap each int of first block with the corresponding int of second block
			for (Iter it2 = it; it2 != endOfFirstBlock; ++it2) {
				std::iter_swap(it2, it2 + intsPerBlock);
			}
		}
	}
	mergeInsertionSort(v, intsPerBlock * 2); // recursive call (pair of pair of blocks, etc...)

	/**
	 * 2. Create theMain and thePend.
	 */

	std::vector<Iter> theMain;
	std::vector<Iter> thePend;

	// push last int of b1 to theMain
	theMain.push_back(v.begin() + intsPerBlock - 1);
	// push last int of a1 to theMain
	theMain.push_back(v.begin() + 2 * intsPerBlock - 1);

	// push the rest of last ints of `a` blocks into theMain and the rest of last ints of `b` blocks into thePend
	Iter firstIntOfThirdBlock = firstInt + 2 * intsPerBlock;
	size_t pairJump = 2 * intsPerBlock;
	for (Iter it = firstIntOfThirdBlock; it != endOflastPairableBlock; it += pairJump) {
		Iter blockLastInt = it + intsPerBlock - 1;
		thePend.push_back(blockLastInt);
		theMain.push_back(blockLastInt + intsPerBlock);
	}
	// Push the odd block into thePend
	if (hasOddNbOfBlocks) {
		Iter lastIntOfLastBlock = endOflastBlock - 1;
		thePend.push_back(lastIntOfLastBlock);
	}

	/**
	 * 3. Insert thePend into theMain using Jacobsthal order.
	 */

	// Jacobsthal order
	size_t prevJacobsthalNb = 1; // We start at j(2) = 1 (we skip j(0) and j(1): base cases for the sequence construction)
	size_t insertedIters = 0;
	for(size_t n = 3; true; ++n) { // Loop from j(3)
		size_t currJacobsthalNb = _getJacobsthalNumber(n);
		size_t ItersToInsert = currJacobsthalNb - prevJacobsthalNb; // We insert the iterator to the last int of each block
		if (ItersToInsert > thePend.size())
			break; // We exit if there is not enough blocks in the pend for this Jacobsthal number

		std::vector<Iter>::iterator IntInPend = thePend.begin() + ItersToInsert - 1;
		std::vector<Iter>::iterator boundInMain = theMain.begin() + currJacobsthalNb + insertedIters;

		size_t offset = 0;
		for (size_t i = ItersToInsert; i > 0; --i) {
			std::vector<Iter>::iterator insertPos = std::upper_bound(theMain.begin(), boundInMain, *IntInPend, _compareIters<Iter>);
			insertPos = theMain.insert(insertPos, *IntInPend);
			IntInPend = thePend.erase(IntInPend);
			IntInPend--;
			offset += static_cast<size_t>(insertPos - theMain.begin()) == (currJacobsthalNb + insertedIters);
			boundInMain = theMain.begin() + currJacobsthalNb + insertedIters - offset;
		}
		prevJacobsthalNb = currJacobsthalNb;
		insertedIters += ItersToInsert;
	}
	// Insert the b's leftovers (above last Jacobthal number)
	for (size_t i = thePend.size(); i > 0; --i) {
		std::vector<Iter>::iterator IntInPend = thePend.begin() + i - 1;
		std::vector<Iter>::iterator boundInMain = theMain.end() - thePend.size() + i - 1 + hasOddNbOfBlocks;
		std::vector<Iter>::iterator insertPos = std::upper_bound(theMain.begin(), boundInMain, *IntInPend, _compareIters<Iter>);
		insertPos = theMain.insert(insertPos, *IntInPend);
	}

	/**
	 * 4. Replace values in the original vector.
	 */

	std::vector<int> tmp;
	tmp.reserve(v.size());
	for (std::vector<Iter>::iterator it = theMain.begin(); it != theMain.end(); ++it) {
		Iter firstIntOfBlock = *it - intsPerBlock + 1;
		for (size_t j = 0; j < intsPerBlock; ++j) {
			tmp.push_back(*(firstIntOfBlock + j));
		}
	}
	for (size_t i = 0; i < tmp.size(); ++i) {
		v[i] = tmp[i];
	}
}

/**
 * [DEQUE VERSION]
 * Merge-Insertion Sort algorithm (Ford-Johnson) on a deque of ints.
 *
 * @return size_t Total number of comparisons made during the sort.
 */
void	PmergeMe::mergeInsertionSort(std::deque<int>& d, size_t intsPerBlock)
{
	totalComparisons = 0;
	typedef std::deque<int>::iterator Iter;
	size_t nbOfBlocks = d.size() / intsPerBlock;
	if (nbOfBlocks < 2)
		return;

	bool hasOddNbOfBlocks = nbOfBlocks % 2 == 1;
	Iter firstInt = d.begin();
	Iter endOflastBlock = firstInt + nbOfBlocks * intsPerBlock;
	Iter endOflastPairableBlock = endOflastBlock - hasOddNbOfBlocks * intsPerBlock;

	/* 1. Order pairs of block recursively. */

	for (Iter it = firstInt; it != endOflastPairableBlock ; it += 2 * intsPerBlock) {
		Iter endOfFirstBlock = it + intsPerBlock;
		Iter lastIntOfFirstBlock = endOfFirstBlock - 1;
		Iter lastIntOfSecondBlock = lastIntOfFirstBlock + intsPerBlock;
		if (_compareIters(lastIntOfSecondBlock, lastIntOfFirstBlock)) {
			for (Iter it2 = it; it2 != endOfFirstBlock; ++it2)
				std::iter_swap(it2, it2 + intsPerBlock);
		}
	}
	mergeInsertionSort(d, intsPerBlock * 2);

	/* 2. Create theMain and thePend. */

	std::deque<Iter> theMain;
	std::deque<Iter> thePend;

	theMain.push_back(d.begin() + intsPerBlock - 1);
	theMain.push_back(d.begin() + 2 * intsPerBlock - 1);

	Iter firstIntOfThirdBlock = firstInt + 2 * intsPerBlock;
	size_t pairJump = 2 * intsPerBlock;
	for (Iter it = firstIntOfThirdBlock; it != endOflastPairableBlock; it += pairJump) {
		Iter blockLastInt = it + intsPerBlock - 1;
		thePend.push_back(blockLastInt);
		theMain.push_back(blockLastInt + intsPerBlock);
	}

	if (hasOddNbOfBlocks) {
		Iter lastIntOfLastBlock = endOflastBlock - 1;
		thePend.push_back(lastIntOfLastBlock);
	}

	/* 3. Insert thePend into theMain using Jacobsthal order. */

	size_t prevJacobsthalNb = 1;
	size_t insertedIters = 0;
	for(size_t n = 3; true; ++n) { // Loop from j(3)
		size_t currJacobsthalNb = _getJacobsthalNumber(n);
		size_t ItersToInsert = currJacobsthalNb - prevJacobsthalNb; // We insert the iterator to the last int of each block
		if (ItersToInsert > thePend.size())
			break;
		std::deque<Iter>::iterator IntInPend = thePend.begin() + ItersToInsert - 1;
		std::deque<Iter>::iterator boundInMain = theMain.begin() + currJacobsthalNb + insertedIters;
		size_t offset = 0;
		for (size_t i = ItersToInsert; i > 0; --i) {
			std::deque<Iter>::iterator insertPos = std::upper_bound(theMain.begin(), boundInMain, *IntInPend, _compareIters<Iter>);
			insertPos = theMain.insert(insertPos, *IntInPend);
			IntInPend = thePend.erase(IntInPend);
			IntInPend--;
			offset += static_cast<size_t>(insertPos - theMain.begin()) == (currJacobsthalNb + insertedIters);
			boundInMain = theMain.begin() + currJacobsthalNb + insertedIters - offset;
		}
		prevJacobsthalNb = currJacobsthalNb;
		insertedIters += ItersToInsert;
	}

	for (size_t i = thePend.size(); i > 0; --i) {
		std::deque<Iter>::iterator IntInPend = thePend.begin() + i - 1;
		std::deque<Iter>::iterator boundInMain = theMain.end() - thePend.size() + i - 1 + hasOddNbOfBlocks;
		std::deque<Iter>::iterator insertPos = std::upper_bound(theMain.begin(), boundInMain, *IntInPend, _compareIters<Iter>);
		insertPos = theMain.insert(insertPos, *IntInPend);
	}

	/* 4. Replace values in the original deque. */

	std::deque<int> tmp;
	for (std::deque<Iter>::iterator it = theMain.begin(); it != theMain.end(); ++it) {
		size_t blockLastIntIdx = *it - d.begin();
		size_t firstIntOfBlockIdx = blockLastIntIdx - intsPerBlock + 1;
		for (size_t j = 0; j < intsPerBlock; ++j)
			tmp.push_back(d[firstIntOfBlockIdx + j]);
	}
	for (size_t i = 0; i < tmp.size(); ++i)
		d[i] = tmp[i];
}
