#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{

	std::string	ideas[100];

	public:

		Brain();
		Brain(Brain const& other);
		~Brain();

		Brain&	operator=(Brain const& other);

		void				addIdea(size_t index, std::string const& idea);
		std::string const&	getIdea(size_t index);

};

#endif
