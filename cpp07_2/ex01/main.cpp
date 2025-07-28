#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void	print(T a) {
	std::cout << a << std::endl;
}

class Awesome {
	int	_n;
	public:
		Awesome(): _n(0) {}
		Awesome(int n): _n(n) {}
		~Awesome() {}
		int	getN() const { return _n; }
};
std::ostream&	operator<<(std::ostream& o, Awesome const& rhs) {
	o << rhs.getN(); return (o);
}

int	main()
{
	int arr1[4] = {1, 2, 3, 4};
	float arr2[4] = {1.1, 2.2, 3.3, 4.4};
	std::string arr3[2] = {"Hello", "World"};
	Awesome a, b(1), c(2);
	Awesome	arr4[3] = {a, b, c};
	iter(arr1, 4, print);
	iter(arr2, 4, print);
	iter(arr3, 2, print);
	iter(arr4, 3, print);

	return(0);
}
