#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{

	public:

		Cat();
		Cat(const Cat &src);

		virtual	~Cat();

		Cat	&operator=(const Cat &other);

		virtual void	makeSound() const;

		std::string getType() const;

};

std::ostream	&operator<<(std::ostream &o, const Cat &c);

#endif