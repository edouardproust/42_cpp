#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{

	Brain	*brain;

	public:

		Cat();
		Cat(const Cat &src);

		virtual	~Cat();

		Cat	&operator=(const Cat &other);

		virtual void	makeSound() const;

};

#endif
