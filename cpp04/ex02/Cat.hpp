#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{

	Brain	*brain;

	public:

		Cat();
		Cat(Cat const& src);

		virtual	~Cat();

		Cat&	operator=(Cat const& other);

		virtual void				makeSound() const;
		virtual std::string const&	getIdea(size_t index) const;
		virtual void				setIdea(size_t index, std::string const& idea);

};

#endif
