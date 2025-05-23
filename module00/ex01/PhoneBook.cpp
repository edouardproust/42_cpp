#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook(void): count_(0)
{
	return;
}

void	PhoneBook::add_contact(void)
{
	Contact	new_contact;
	this->count_++;
	new_contact.create_contact(this->count_);
	return;
}

void	PhoneBook::search_contact(void) const
{
	for (int i = 0; i < this->count_; i++)
		std::cout << this->contacts_[i].display_contact() << std::endl;
}