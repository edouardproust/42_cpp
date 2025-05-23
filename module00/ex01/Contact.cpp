#include <iostream>
#include <sstream>
#include "Contact.hpp"


Contact::Contact(void)
{
	return;
}

Contact::Contact(int index, std::string firstname, std::string lastname,
	std::string nickname, std::string phone_number, std::string darkest_secret):
		index_(index),
		firstname_(firstname),
		lastname_(lastname),
		nickname_(nickname),
		phone_number_(phone_number),
		darkest_secret_(darkest_secret)
{
	return;
}

void	Contact::create_contact(int index)
{
	this->index_ = index;
	std::cout << "Firstname: ";
	std::getline(std::cin, this->firstname_);
	std::cout << "Lastname: ";
	std::getline(std::cin, this->lastname_);
	std::cout << "Nickname: ";
	std::getline(std::cin, this->nickname_);
	std::cout << "Phone number: ";
	std::getline(std::cin, this->phone_number_);
	std::cout << "Darkest secret: ";
}

std::string	Contact::display_contact(void) const
{
	std::stringstream ss;
	ss << this->index_ << " | " << this->firstname_ << " | " << this->lastname_ << " | " << this->nickname_;
	return (ss.str());
}

