#include "Array.hpp"
#include <iostream>

class Awesome
{
	int	_n;
	public:
		Awesome(): _n(42) {}
		Awesome(int n): _n(n) {}
		~Awesome() {}
		int	getN() const { return (_n); }
};
std::ostream&	operator<<(std::ostream& o, Awesome const& rhs) {
	o << rhs.getN(); return (o);
}

int	main()
{
	// Out of range access
	Array<int> arr1;
	try {
		std::cout << arr1[0] << std::endl;	
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	// Correct access
	Array<float> arr2(3);
	try {
		arr2[0] = 1;
		arr2[1] = 2;
		arr2[2] = 3;
		for (unsigned int i = 0; i < arr2.size(); ++i) {
			std::cout << arr2[i] << std::endl;
		}
		arr2[3] = 1337;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// Complex type
	Array<Awesome> arr3(3);
	try {
		arr3[0] = Awesome();
		arr3[1] = Awesome(-21);
		arr3[2] = Awesome(10);
		arr3[3] = Awesome(1337);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	for (unsigned int i = 0; i < 3; ++i) {
		std::cout << arr3[i] << std::endl;
	}
	
	return (0);
}
