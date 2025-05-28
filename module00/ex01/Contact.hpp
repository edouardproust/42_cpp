#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	public:

		Contact();

		static Contact createContact(int index);
		void printSearchLine(void) const;
		void printContactInfos(void) const;

	private:

		int index_;
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phone_number_;
		std::string _darkest_secret_;

		static std::string _getInput(const std::string &prompt);
		static std::string _truncateField(const std::string &field);

};

#endif