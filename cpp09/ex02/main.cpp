#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>

template <typename Container>
void	printContainer(Container values, size_t n)
{
	for (size_t i = 1; i < n; ++i) {
		if (i == 11)
			std::cout << " [...]";
		if (i <= 10 || i >= n - 10)
			std::cout << " " << values[i];
	}
}

/**
 * Merge-Insertion Sort (Ford–Johnson algorithm) can be described as:
 * a "Binary Insertion Sort" with an optimized insertion order (Jacobsthal)
 * to reduce the total number of comparisons.
 *
 * Program usage examples:
 * ./PmergeMe 3 5 9 7 4 -> OK
 * ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "` -> OK
 * ./PmergeMe "-1" "2" -> Error
 */
int	main(int ac, char** av)
{
	PmergeMe pm;

	// Check args

	try {
		pm.validateArgs(ac, av);
	} catch (std::exception& e){
		std::cerr << e.what() << std::endl;
		exit(2);
	}

	// Vector

	clock_t startVec = std::clock();
	std::vector<int> vec = pm.argsToVector(ac, av);
	pm.mergeInsertionSort(vec, 1);
	size_t totalComparisons = PmergeMe::totalComparisons;
	clock_t endVec = std::clock();

	// Deque

	clock_t startDeq = std::clock();
	std::deque<int> deq = pm.argsToDeque(ac, av);
	pm.mergeInsertionSort(deq, 1);
	clock_t endDeq = std::clock();

	// Print result

	std::cout << "Before:"; printContainer(av, ac);
    std::cout << "\nAfter:"; printContainer(vec, vec.size());
    std::cout << "\nTime to process a range of " << vec.size() << " elements with std::vector: " << 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC << " us";
    std::cout << "\nTime to process a range of " << deq.size() << " elements with std::deque: " << 1000000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC << " us";
	std::cout << "\nTotal comparisons: " << totalComparisons << " (Ford-Johnson theorical: " << pm.fjUpperBound(vec.size()) << ")";
	std::cout << std::endl;

	return 0;
}