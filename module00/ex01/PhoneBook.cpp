#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>

PhoneBook::PhoneBook(void): count_(0)
{
	return;
}

void PhoneBook::add_contact(void)
{
	int	index;

	if (this->count_ >= this->capacity_)
		index = 0;
	else
	{
		index = this->count_;
		this->count_++;
	}
	this->contacts_[index] = Contact::create_contact(index);
	return;
}

void PhoneBook::search_contact(void) const
{
	int contact_index;

	if (this->count_ == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return;
	}
	for (int i = 0; i < this->count_; i++)
		this->contacts_[i].print_search_line();
	contact_index = this->get_input_contact_index("Type index of contact: ");
	if (contact_index != -1)
		this->contacts_[contact_index].print_contact_infos();
}

int PhoneBook::get_input_contact_index(const std::string &prompt) const
{
    int index;

	std::cout << prompt << std::flush;
	if(std::cin >> index && index > 0 && index <= this->count_)
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (index - 1);
	}
	std::cerr << "Invalid index" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (-1);
}
