#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact
{
	public:

		Contact();
		Contact(int index, std::string firstname, std::string lastname,
			std::string nickname, std::string phone_number, std::string darkest_secret);

		void		create_contact(int index);
		std::string	display_contact(void) const;

	private:

		int			index_;
		std::string	firstname_;
		std::string	lastname_;
		std::string	nickname_;
		std::string	phone_number_;
		std::string	darkest_secret_;

};

#endif