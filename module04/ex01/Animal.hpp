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
		Animal(Animal const& src);

		virtual	~Animal();

		Animal&	operator=(Animal const& other);

		virtual void	makeSound() const;

		std::string const&			getType() const;
		virtual std::string const&	getIdea(size_t index) const;
		virtual void				setIdea(size_t index, std::string const& idea);

};

#endif
