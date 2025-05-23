#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	std::string	input;
	PhoneBook	phonebook;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::cin >> input;
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
	}
	return (0);
}