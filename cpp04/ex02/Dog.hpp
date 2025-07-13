#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
{

	Brain	*brain;

	public:

		Dog();
		Dog(Dog const& src);

		virtual	~Dog();

		Dog	&operator=(Dog const& other);

		virtual void				makeSound() const;
		virtual std::string const&	getIdea(size_t index) const;
		virtual void				setIdea(size_t index, std::string const& idea);

};

#endif
