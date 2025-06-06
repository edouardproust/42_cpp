#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

# include <string>
# include <iostream>

class AAnimal
{

	protected:

		std::string	type;

	public:

		AAnimal();
		AAnimal(const AAnimal &src);

		virtual	~AAnimal();

		AAnimal	&operator=(const AAnimal &other);

		virtual void	makeSound() const = 0;

		std::string getType() const;

};

std::ostream	&operator<<(std::ostream &o, const AAnimal &a);

#endif
