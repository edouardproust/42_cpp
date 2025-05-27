#include "PhoneBook.hpp"
#include "Contact.hpp"

#include <iostream>
#include <string>

int	main(void)
{
	std::string	input;
	PhoneBook	phonebook;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input == "EXIT")
		{
			if (std::cin.eof())
				std::cout << std::endl;
			return (0);
		}
		else if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
	}
	return (0);
}