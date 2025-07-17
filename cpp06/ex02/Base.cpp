#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base() {}

Base::~Base() {}

Base*	Base::generate(void)
{
	std::srand(time(0));
	switch (std::rand() % 3) {
		case 0: return (new A());
		case 1: return (new B());
		default: return (new C());
	}
}

void	Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unknown class" << std::endl;
	}
}

void	Base::identify(Base& p)
{
	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (...) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (...) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (...) {}
} 

