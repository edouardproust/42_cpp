#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{

	public:

		Cat();
		Cat(Cat const& src);

		virtual	~Cat();

		Cat&	operator=(Cat const& other);

		virtual void	makeSound() const;

};

#endif
