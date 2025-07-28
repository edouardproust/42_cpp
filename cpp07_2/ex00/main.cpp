#include "whatever.hpp"
#include <iostream>
#include <string>

class Awesome {
	double _d;
	public:
		Awesome(): _d(0.0) {}
		Awesome(double d): _d(d) {}
		~Awesome() {}
		Awesome&	operator=(Awesome const& rhs) {
			if (this != &rhs) _d = rhs._d;
			return (*this);
		}
		bool	operator<=(Awesome const& rhs) {
			return (_d <= rhs._d);
		}
		bool	operator>=(Awesome const& rhs) {
			return (_d >= rhs._d);
		}
		double	getD() const { return _d; }
};
std::ostream&	operator<<(std::ostream& o, Awesome const& rhs) {
	o << rhs.getD(); return (o);
}

int	main()
{
	// Integers
	int a = 21, b = 42;
	::swap(a, b);
	std::cout << "a = " << a << "; b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	// Float
	float c = 21.1f, d = 42.2f;
	::swap(c, d);
	std::cout << "c = " << c << "; d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	// String
	std::string e = "Hello", f = "World";
	::swap(e, f);
	std::cout << "e = " << e << "; f = " << f << std::endl;
	std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
	std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

	// Complex type

	Awesome g(1), h(2);
	swap(g, h);
	std::cout << "g = " << g  << "; h = " << h << std::endl;
	std::cout << "min(g, h) = " << ::min(g, h) << std::endl;
	std::cout << "max(g, h) = " << ::max(g, h) << std::endl;

	return (0);
}

