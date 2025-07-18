#include "Serializer.hpp"
#include <iostream>

/**
 * ex01: Use of `reinterpret_cast` to do reinterpretation (pointer to pointer).
 */
int	main()
{
	Data*	d = new Data;
	d->firstname = "Isaac";
	d->lastname = "Newton";
	d->age = 381;
	d->grade = 'S';

	uintptr_t	serializedData = Serializer::serialize(d);
	Data*		res = Serializer::deserialize(serializedData);

	std::cout << "firstname: " << res->firstname
			<< "\nlastname: " << res->lastname
			<< "\nage: " << res->age
			<< "\ngrade: " << res->grade
			<< std::endl;

	delete d;
	return (0);
}
