#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
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
