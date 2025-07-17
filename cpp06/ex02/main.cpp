#include "Base.hpp"

int	main()
{
	Base b;
	Base*	p = b.generate();
	b.identify(p);
	b.identify(*p);	
	return (0);
}
