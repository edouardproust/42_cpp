#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{

	public:

		Dog();
		Dog(Dog const& src);

		virtual	~Dog();

		Dog&	operator=(Dog const& other);

		virtual void	makeSound() const;

};

#endif
