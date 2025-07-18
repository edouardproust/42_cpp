#include "Base.hpp"

/**
 * ex02: Use of `dynamic_cast` to identify the most virtual class.
 */
int	main()
{
	Base b;
	Base*	p = b.generate();
	b.identify(p);
	b.identify(*p);	
	return (0);
}
