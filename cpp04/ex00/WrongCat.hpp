#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{

	public:

		WrongCat();
		WrongCat(const WrongCat &src);

		~WrongCat();

		WrongCat	&operator=(const WrongCat &other);

		void	makeSound() const;

};

#endif
