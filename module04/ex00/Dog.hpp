#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{

	public:

		Dog();
		Dog(const Dog &src);

		virtual	~Dog();

		Dog	&operator=(const Dog &other);

		virtual void	makeSound() const;

		std::string getType() const;

};

std::ostream	&operator<<(std::ostream &o, const Dog &d);

#endif