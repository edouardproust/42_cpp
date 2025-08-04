#include "Contact.hpp"

#include <iostream>
#include <sstream>

Contact::Contact(void)
{
	return;
}

Contact Contact::createContact(int index)
{
	Contact c;
	c.index_ = index;
	c._firstname = _getInput("Firstname: ");
	c._lastname = _getInput("Lastname: ");
	c._nickname = _getInput("Nickname: ");
	c._phone_number_ = _getInput("Phone number: ");
	c._darkest_secret_ = _getInput("Darkest secret: ");
	return (c);
}

void Contact::printSearchLine(void) const
{
	std::cout << this->index_ + 1 << " | ";
	std::cout << _truncateField(this->_firstname) << " | ";
	std::cout << _truncateField(this->_lastname) << " | ";
	std::cout << _truncateField(this->_nickname) << std::endl;
}

void Contact::printContactInfos(void) const
{
	std::cout << "Firstname: " << this->_firstname << "\n";
	std::cout << "Lastname: " << this->_lastname << "\n";
	std::cout << "Nickname: " << this->_nickname << "\n";
	std::cout << "Phone number: " << this->_phone_number_ << "\n";
	std::cout << "Darkest secret: " << this->_darkest_secret_ << std::endl;
}

std::string Contact::_getInput(const std::string &prompt)
{
	std::string str;
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, str);
		if (std::cin.eof() || !str.empty())
			break;
		std::cerr << "Input cannot be empty\n";
	}
	return (str);
}

std::string Contact::_truncateField(const std::string &field)
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field + std::string(10 - field.length(), ' '));
}
