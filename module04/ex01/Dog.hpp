#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{

	Brain	*brain;

	public:

		Dog();
		Dog(const Dog &src);

		virtual	~Dog();

		Dog	&operator=(const Dog &other);

		virtual void	makeSound() const;

};

#endif
