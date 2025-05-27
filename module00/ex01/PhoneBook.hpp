#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{

	public:
		PhoneBook(void);

		void add_contact(void);
		void search_contact(void) const;

	private:

		static const int capacity_ = 8;
		Contact contacts_[capacity_];
		int count_;

		int get_input_contact_index(const std::string &prompt) const;

};

#endif