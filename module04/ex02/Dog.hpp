#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
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
