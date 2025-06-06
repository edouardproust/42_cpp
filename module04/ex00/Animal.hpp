#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{

	protected:

		std::string	type;

	public:

		Animal();
		Animal(const Animal &src);

		virtual	~Animal();

		Animal	&operator=(const Animal &other);

		virtual void	makeSound() const;

		std::string getType() const;

};

std::ostream	&operator<<(std::ostream &o, const Animal &a);

#endif