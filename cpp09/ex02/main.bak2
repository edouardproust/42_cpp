#include "PmergeMe.hpp"

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
int	main(int ac, char**av)
{
	PmergeMe pmm;

	try
	{
		// vector
		pmm.setUnsorted(ac - 1, &av[1]);
		pmm.sort();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	std::cout << pmm << std::endl; // Print

	return 0;
}