#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <limits>

PhoneBook::PhoneBook(void): _count(0), _oldest(0)
{
	return;
}

void PhoneBook::addContact(void)
{
	int	new_index;

	if (this->_count < this->_capacity)
		new_index = this->_count;
	else
		new_index = this->_oldest;
	this->contacts_[new_index] = Contact::createContact(new_index);
	if (this->_count < this->_capacity)
		this->_count++;
	if(this->_oldest == this->_capacity - 1)
		this->_oldest = 0;
	else
		this->_oldest++;
}

void PhoneBook::searchContact(void) const
{
	int contact_index;

	if (this->_count == 0)
	{
		std::cout << "Phonebook is empty\n";
		return;
	}
	for (int i = 0; i < this->_count; i++)
		this->contacts_[i].printSearchLine();
	contact_index = this->_getInputContactIndex("Type index of contact: ");
	if (contact_index != -1)
		this->contacts_[contact_index].printContactInfos();
}

int PhoneBook::_getInputContactIndex(const std::string &prompt) const
{
    int index;

	std::cout << prompt << std::flush;
	if(std::cin >> index && index > 0 && index <= this->_count)
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (index - 1);
	}
	std::cerr << "Invalid index\n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (-1);
}
