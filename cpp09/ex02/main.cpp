#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>

/**
 * Validate arguments.
 *
 * @note May throw an exception.
 */
void	validateArgs(int ac, char** av)
{
	if (ac < 2)
		throw std::invalid_argument("Usage: ./PmergeMe <positive_integer1> [positive_integer2 ... positive_integerN]");

	// Validate each arg
	for (int i = 1; i < ac; ++i) {
		if (!av[i] || av[i][0] == '\0')
			throw std::invalid_argument("Empty argument");
		// Validate characters (only digits allowed: "-", "+", etc. are forbidden)
		for (int j = 0; av[i][j]; ++j) {
			if (!std::isdigit(static_cast<unsigned char>(av[i][j]))) // static_cast to prevent UB is char is negative
				throw std::invalid_argument("Invalid character in argument");
		}
		// Validate overflow
		long nb = std::strtol(av[i], NULL, 10); // no need to check `*endptr != '\0'`: we have only digits at this point
		if (nb > std::numeric_limits<int>::max()) // no need to check `errno == ERANGE`: nb is always positive at this point
			throw std::out_of_range("Number too large");
	}
}

std::vector<int>	argsToVector(int ac, char** av)
{
	std::vector<int> vec;
	vec.reserve(ac - 1);
	for (int i = 1; i < ac; ++i)
		vec.push_back(static_cast<int>(std::strtol(av[i], NULL, 10)));
	return vec;
}

std::deque<int>	argsToDeque(int ac, char** av)
{
	std::deque<int> deq;
	for (int i = 1; i < ac; ++i)
		deq.push_back(static_cast<int>(std::strtol(av[i], NULL, 10)));
	return deq;
}

template <typename Container>
void	printContainer(Container values, size_t n)
{
	for (size_t i = 0; i < n; ++i) {
		if (i == 11)
			std::cout << " [...]";
		if (i <= 10 || i >= n - 10)
			std::cout << " " << values[i];
	}
}

double	elapsedTime(clock_t const& start, clock_t const& end)
{
	return 1000000.0 * (end - start) / CLOCKS_PER_SEC;
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

	// Check args

	try {
		validateArgs(ac, av);
	} catch (std::exception& e){
		std::cerr << e.what() << std::endl;
		exit(2);
	}

	PmergeMe pm;

	// Vector

	clock_t startVec = std::clock();
	std::vector<int> vec = argsToVector(ac, av);
	pm.mergeInsertionSort(vec, 1);
	size_t totalComparisons = PmergeMe::totalComparisons;
	clock_t endVec = std::clock();

	// Deque

	clock_t startDeq = std::clock();
	std::deque<int> deq = argsToDeque(ac, av);
	pm.mergeInsertionSort(deq, 1);
	clock_t endDeq = std::clock();

	// Print result

	std::cout << "Before:"; printContainer(&av[1], ac - 1);
    std::cout << "\nAfter:"; printContainer(vec, vec.size());
    std::cout << "\nTime to process a range of " << vec.size() << " elements with std::vector: " << elapsedTime(startVec, endVec) << " us";
    std::cout << "\nTime to process a range of " << deq.size() << " elements with std::deque: " << elapsedTime(startDeq, endDeq) << " us";
	std::cout << "\nTotal comparisons: " << totalComparisons << " (Ford-Johnson theorical: " << pm.fjUpperBound(vec.size()) << ")";
	std::cout << std::endl;

	return 0;
}