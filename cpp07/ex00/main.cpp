#include "whatever.hpp"
#include <iostream>
#include <string>

class Awesome
{
	int _n;

	public:

		Awesome(void) : _n(0) {}
		Awesome( int n ) : _n(n) {}
		Awesome & operator= (Awesome & a) {
			_n = a._n;
			return (*this);
		}

		bool operator>=(Awesome const& rhs) const {
			return (this->_n >= rhs._n);
		}
		bool operator<=(Awesome const& rhs) const {
			return (this->_n <= rhs._n);
		}

		int get_n() const { 
			return (_n); 
		}
};

std::ostream & operator<<(std::ostream & o, const Awesome &a) {
	o << a.get_n(); return o;
}

int	main()
{
	// Int
	int	a = 21, b = 42;
	std::cout << "Before swap(a, b): a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap(a, b): a = " << a << ", b = " << b << "\n"
		<< "min(a, b): " << ::min(a, b) << "\n"
		<< "max(a, b): " << ::max(a, b) << "\n" << std::endl;
	
	// Float
	float	c = -21.21f, d = 42.42f;
	std::cout << "Before swap(c, d): c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "After swap(c, d): c = " << c << ", d = " << d << "\n"
		<< "min(c, d): " << ::min(c, d) << "\n"
		<< "max(c, d): " << ::max(c, d) << "\n" << std::endl;	

	// String
	std::string e = "Hello", f = "World";
	std::cout << "Before swap(e, f): e = " << e << ", f = " << f << std::endl;
	::swap(e, f);
	std::cout << "After swap(e, f): e = " << e << ", f = " << f << "\n"
		<< "min(e, f): " << ::min(e, f) << "\n"
		<< "max(e, f): " << ::max(e, f) << "\n" << std::endl;	

	// Complex type
	Awesome g(123), h(321);
	std::cout << "Before swap(g, h): g = " << g << ", h = " << h << std::endl;
	::swap(g, h);
	std::cout << "After swap(e, f): g = " << g << ", h = " << h << "\n"
		<< "min(g, h): " << ::min(g, h) << "\n"
		<< "max(g, h): " << ::max(g, h) << std::endl;	

	return (0);
}
