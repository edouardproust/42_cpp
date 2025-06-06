#ifndef WRONG_A_ANIMAL_HPP
# define WRONG_A_ANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{

	protected:

		std::string	type;

	public:

		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);

		~WrongAnimal();

		WrongAnimal	&operator=(const WrongAnimal &other);

		void	makeSound() const;

		std::string getType() const;

};

std::ostream	&operator<<(std::ostream &o, const WrongAnimal &a);

#endif
