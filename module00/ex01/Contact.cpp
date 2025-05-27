#include "Contact.hpp"

#include <iostream>
#include <sstream>

Contact::Contact(void)
{
	return;
}

Contact Contact::create_contact(int index)
{
	Contact c;
	c.index_ = index;
	c.firstname_ = get_input("Firstname: ");
	c.lastname_ = get_input("Lastname: ");
	c.nickname_ = get_input("Nickname: ");
	c.phone_number_ = get_input("Phone number: ");
	c.darkest_secret_ = get_input("Darkest secret: ");
	return (c);
}

void Contact::print_search_line(void) const
{
	std::cout << this->index_ + 1 << " | ";
	std::cout << truncate_field(this->firstname_) << " | ";
	std::cout << truncate_field(this->lastname_) << " | ";
	std::cout << truncate_field(this->nickname_) << std::endl;
}

void Contact::print_contact_infos(void) const
{
	std::cout << "Firstname: " << this->firstname_ << std::endl;
	std::cout << "Lastname: " << this->lastname_ << std::endl;
	std::cout << "Nickname: " << this->nickname_ << std::endl;
	std::cout << "Phone number: " << this->phone_number_ << std::endl;
	std::cout << "Darkest secret: " << this->darkest_secret_ << std::endl;
}

std::string Contact::get_input(const std::string &prompt)
{
	std::string str;
	while (true)
	{
		std::cout << prompt << std::flush;
		std::getline(std::cin, str);
		if (std::cin.eof() || !str.empty())
			break;
		std::cerr << "Input cannot be empty" << std::endl;
	}
	return (str);
}

std::string Contact::truncate_field(const std::string &field)
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field + std::string(10 - field.length(), ' '));
}
