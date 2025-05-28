#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{

	public:
		PhoneBook(void);

		void addContact(void);
		void searchContact(void) const;

	private:

		static const int _capacity = 8;
		Contact contacts_[_capacity];
		int _count;
		int	_oldest;

		int _getInputContactIndex(const std::string &prompt) const;

};

#endif