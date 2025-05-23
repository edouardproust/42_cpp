#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{

	public:
		PhoneBook(void);

		void				add_contact(void);
		void				search_contact(void) const;

	private:
		static const int	capacity_ = 8;
		int					count_;
		Contact				contacts_[capacity_];

};

#endif