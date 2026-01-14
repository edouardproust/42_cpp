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
 * Key idea: Minimize comparisons by:
 * 1. Creating pairs and sorting them recursively (largest element known per pair)
 * 2. Building a sorted "main chain" from the larger elements
 * 3. Inserting smaller elements using binary search in optimal Jacobsthal order
 *
 * @param v	Vector to sort
 * @param intsPerBlock	Size of each block (starts at 1, doubles each recursion)
 */
void	PmergeMe::mergeInsertionSort(std::vector<int>& v, size_t intsPerBlock)
{
	totalComparisons = 0; // reset counter
	typedef std::vector<int>::iterator Iter;
	size_t nbOfBlocks = v.size() / intsPerBlock;

	// Base case: need at least 2 blocks to form a pair
	if (nbOfBlocks < 2)
		return;

	bool hasOddNbOfBlocks = nbOfBlocks % 2 == 1; // ints that cannot even form a block are ignored in this count
	Iter firstInt = v.begin();
	Iter endOflastBlock = firstInt + nbOfBlocks * intsPerBlock;
	Iter endOflastPairableBlock = endOflastBlock - hasOddNbOfBlocks * intsPerBlock;

	/**
	 * STEP 1: Create pairs and ensure larger element is in second position.
	 *
	 * For each pair of blocks (b, a):
	 * - Compare last elements (they represent the max of each block)
	 * - If b > a, swap entire blocks so that a > b
	 * - This guarantees: after this step, second block always has larger max
	 */

	for (Iter it = firstInt; it != endOflastPairableBlock ; it += 2 * intsPerBlock) { // `2 * intsPerBlock` is the size of a pair (2 blocks)
		Iter endOfFirstBlock = it + intsPerBlock;
		Iter lastIntOfFirstBlock = endOfFirstBlock - 1;
		Iter lastIntOfSecondBlock = lastIntOfFirstBlock + intsPerBlock;

		// Compare block maximums (last element of each block)
		if (_compareIters(lastIntOfSecondBlock, lastIntOfFirstBlock)) {
			// Second block is smaller: swap the entire blocks
			for (Iter it2 = it; it2 != endOfFirstBlock; ++it2) {
				std::iter_swap(it2, it2 + intsPerBlock);
			}
		}
	}

	// Recursive call: treat each pair as a single "super-block"
	// This builds a hierarchy where we know relative ordering at each level
	mergeInsertionSort(v, intsPerBlock * 2);

	/**
	 * STEP 2: Build main chain and pend chain.
	 *
	 * After recursion, pairs are ordered by their larger element.
	 * Notation: pair (b₁, a₁), (b₂, a₂), (b₃, a₃)... where aᵢ > bᵢ
	 * Main chain: b₁, a₁, a₂, a₃, a₄... (all 'a' elements + first 'b')
	 *             └─────┘  └──────────┘
	 *             smallest   sorted larger elements
	 * Pend chain: b₂, b₃, b₄... (remaining 'b' elements to insert)
	 * Key insight: We know b₁ is smallest (a₁ > b₁, and a₁ is smallest 'a')
	 */

	std::vector<Iter> theMain;
	std::vector<Iter> thePend;

	// First 'b' is guaranteed smallest → goes first in main chain
	theMain.push_back(v.begin() + intsPerBlock - 1);
	// First 'a' is smallest of all 'a' elements → goes second
	theMain.push_back(v.begin() + 2 * intsPerBlock - 1);

	// Handle unpaired block (if odd number of blocks)
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
	 * STEP 3: Insert pend elements into main chain using Jacobsthal order.
	 *
	 * Why Jacobsthal sequence? It minimizes worst-case comparisons.
	 * J(n) = 1, 1, 3, 5, 11, 21, 43, 85...
	 *
	 * Insertion order: Group elements by Jacobsthal differences
	 * - Between J(2)=1 and J(3)=3: insert elements at indices 2,3 (2 elements)
	 * - Between J(3)=3 and J(4)=5: insert elements at indices 4,5 (2 elements)
	 * - Between J(4)=5 and J(5)=11: insert elements at indices 10,9,8,7,6 (5 elements, reverse!)
	 *
	 * Within each group: insert in DESCENDING order to limit search range
	 * For bᵢ, we know: bᵢ < aᵢ, so search only up to aᵢ's position in main chain
	 */

	size_t prevJacobsthalNb = 1;  // J(2) = 1
	size_t insertedIters = 0; // Count how many we've inserted so far

	for(size_t n = 3; true; ++n) { // Loop from j(3)
		size_t currJacobsthalNb = _getJacobsthalNumber(n);
		size_t ItersToInsert = currJacobsthalNb - prevJacobsthalNb; // We insert the iterator to the last int of each block
		if (ItersToInsert > thePend.size())
			break; // Not enough elements left in pend

		// Process this Jacobsthal group in reverse order
		std::vector<Iter>::iterator IntInPend = thePend.begin() + ItersToInsert - 1;
		std::vector<Iter>::iterator boundInMain = theMain.begin() + currJacobsthalNb + insertedIters;
		size_t offset = 0;
		for (size_t i = ItersToInsert; i > 0; --i) {
			// Binary search: find insertion point
			// Search only up to boundInMain (position of paired 'a' element)
			std::vector<Iter>::iterator insertPos = std::upper_bound(theMain.begin(), boundInMain, *IntInPend, _compareIters<Iter>);
			insertPos = theMain.insert(insertPos, *IntInPend);
			// Remove from pend and adjust iterator
			IntInPend = thePend.erase(IntInPend);
			IntInPend--;
			// Adjust bound: if we inserted exactly at the bound, shrink search range
			offset += static_cast<size_t>(insertPos - theMain.begin()) == (currJacobsthalNb + insertedIters);
			boundInMain = theMain.begin() + currJacobsthalNb + insertedIters - offset;
		}
		prevJacobsthalNb = currJacobsthalNb;
		insertedIters += ItersToInsert;
	}

	// Insert remaining elements (beyond last Jacobsthal number)
	for (size_t i = thePend.size(); i > 0; --i) {
		std::vector<Iter>::iterator IntInPend = thePend.begin() + i - 1;
		std::vector<Iter>::iterator boundInMain = theMain.end() - thePend.size() + i - 1 + hasOddNbOfBlocks;
		std::vector<Iter>::iterator insertPos = std::upper_bound(theMain.begin(), boundInMain, *IntInPend, _compareIters<Iter>);
		insertPos = theMain.insert(insertPos, *IntInPend);
	}

	/**
	 * STEP 4: Reconstruct sorted vector from main chain.
	 *
	 * theMain contains iterators to last element of each block in sorted order
	 * Rebuild vector by extracting all elements of each block in sequence
	 */

	std::vector<int> tmp;
	tmp.reserve(v.size());

	for (std::vector<Iter>::iterator it = theMain.begin(); it != theMain.end(); ++it) {
		// Get first element of this block (last element - block size + 1)
		Iter firstIntOfBlock = *it - intsPerBlock + 1;
		// Copy entire block to tmp
		for (size_t j = 0; j < intsPerBlock; ++j) {
			tmp.push_back(*(firstIntOfBlock + j));
		}
	}

	// Copy sorted result back to original vector
	for (size_t i = 0; i < tmp.size(); ++i) {
		v[i] = tmp[i];
	}
}

/**
 * [DEQUE VERSION]
 * Merge-Insertion Sort algorithm (Ford-Johnson) on a deque of ints.
 *
 * @param d	Deque to sort
 * @param intsPerBlock	Size of each block (starts at 1, doubles each recursion)
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

	/* STEP 1: Create pairs and ensure larger element is in second position. */

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

	/* STEP 2: Build main chain and pend chain. */

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

	/* STEP 3: Insert pend elements into main chain using Jacobsthal order. */

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

	/* STEP 4: Reconstruct sorted deque from main chain. */

	std::deque<int> tmp; // Unlike with vector we cannot do reserve() for deque
	for (std::deque<Iter>::iterator it = theMain.begin(); it != theMain.end(); ++it) {
		// We need to turn the iterator to an index for deque
		size_t blockLastIntIdx = *it - d.begin();
		size_t firstIntOfBlockIdx = blockLastIntIdx - intsPerBlock + 1;
		for (size_t j = 0; j < intsPerBlock; ++j)
			tmp.push_back(d[firstIntOfBlockIdx + j]);
	}
	for (size_t i = 0; i < tmp.size(); ++i)
		d[i] = tmp[i];
}
