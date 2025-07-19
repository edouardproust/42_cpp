#include "iter.hpp"

class Custom
{
	double	_n;

	public:
		Custom(): _n(0) {}
		Custom(double n): _n(n) {}
		double get() const { return (_n); }
};
std::ostream& operator<<(std::ostream& o, Custom const& rhs) {
	o << rhs.get(); return o;
}

template< typename T >
void print(T const& x) {
	std::cout << x << " ";
}

int	main() {
	int			arr0[] = {0, 1, 2, 3, 4};
	float		arr1[] = {0.0f, 1.1f, 2.2f, 3.3f, 4.4f};
	std::string	arr2[] = {"Hello", "World", "I", "am", "Edouard"};
	Custom		a, b(1.1), c(2.2), d(3.3), e(4.4);
	Custom		arr3[5] = {a, b, c, d, e};
	iter(arr0, 5, print); std::cout << std::endl;
	iter(arr1, 5, print); std::cout << std::endl;
	iter(arr2, 5, print); std::cout << std::endl;
	iter(arr3, 5, print); std::cout << std::endl;
	return (0);
}

