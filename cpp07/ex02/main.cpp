#include "Array.hpp"

int	main()
{
	Array<int> arr1;
	try {
		std::cout << "arr1.size() = " << arr1.size() << std::endl;
		std::cout << "arr1[0] = " << arr1[0] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	Array<int> arr2(2);
	try {
		std::cout << "arr2.size() = " << arr2.size() << std::endl;
		std::cout << "arr2[0] = " << arr2[0] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	Array<int> arr3(3);
	try {
		arr3[0] = 42;
		arr3[1] = -42;
		arr3[2] = 123;
		std::cout << "arr3.size() = " << arr3.size() << std::endl;
		std::cout << "arr3[0] = " << arr3[0] << std::endl;
		arr3[1337] = 10; // exception
	} catch (std::exception& e) {	
		std::cout << e.what() << std::endl;
	}

	// const array
	Array<int> const arr4 = arr3;
	try {
		std::cout << "arr4.size() = " << arr4.size() << std::endl;
		std::cout << "arr4[0] = " << arr4[0] << std::endl;
		//arr4[0] = 1337; // compilation error
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
	
}
