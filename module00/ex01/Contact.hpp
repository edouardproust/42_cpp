#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	public:

		Contact();

		static Contact create_contact(int index);
		void print_search_line(void) const;
		void print_contact_infos(void) const;

	private:

		int index_;
		std::string firstname_;
		std::string lastname_;
		std::string nickname_;
		std::string phone_number_;
		std::string darkest_secret_;

		static std::string get_input(const std::string &prompt);
		static std::string truncate_field(const std::string &field);

};

#endif