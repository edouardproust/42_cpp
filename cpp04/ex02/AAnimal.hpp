#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class AAnimal
{

	protected:

		std::string	type;

	public:

		AAnimal();
		AAnimal(AAnimal const& src);

		virtual	~AAnimal();

		AAnimal&	operator=(AAnimal const& other);

		virtual void	makeSound() const = 0;

		std::string const&			getType() const;
		virtual std::string const&	getIdea(size_t index) const = 0;
		virtual void				setIdea(size_t index, std::string const& idea) = 0;

};

#endif
