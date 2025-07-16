#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include "Data.hpp"
# include <stdint.h>

class Serializer
{
	Serializer();
	Serializer(Serializer const& src);
	Serializer&	operator=(Serializer const& rhs);
	~Serializer();

	public:

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif

