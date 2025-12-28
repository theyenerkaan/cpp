#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook()
{
	this->contactCount = 0;
	this->oldestIndex = 0;
}

PhoneBook::~PhoneBook()
{
}

std::string PhoneBook::truncateField(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::displayContactList() const
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < this->contactCount; i++)
	{
		if (this->contacts[i].getFavorite())
			std::cout << std::setw(9) << i << "*|";
		else
			std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncateField(this->contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncateField(this->contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncateField(this->contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::displayContactDetails(int index) const
{
	if (this->contacts[index].getBlocked())
	{
		std::cout << "==========================================" << std::endl;
		std::cout << "This contact is BLOCKED!" << std::endl;
		std::cout << "Name: " << this->contacts[index].getFirstName() << " "
			<< this->contacts[index].getLastName() << std::endl;
		std::cout << "Details are hidden for blocked contacts." << std::endl;
		std::cout << "==========================================" << std::endl;
		return;
	}

	std::cout << "==========================================" << std::endl;
	if (this->contacts[index].getFavorite())
		std::cout << "*** FAVORITE CONTACT ***" << std::endl;
	std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
	std::cout << "==========================================" << std::endl;
}

bool PhoneBook::isValidIndex(std::string input, int *index) const
{
	if (input.length() == 0)
		return (false);

	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] < '0' || input[i] > '9')
			return (false);
	}

	std::stringstream ss(input);
	ss >> *index;

	if (*index < 0 || *index >= this->contactCount)
		return (false);

	return (true);
}

bool PhoneBook::isValidPhoneNumber(std::string phoneNumber) const
{
	if (phoneNumber.length() < 7 || phoneNumber.length() > 15)
		return (false);

	for (size_t i = 0; i < phoneNumber.length(); i++)
	{
		if (phoneNumber[i] < '0' || phoneNumber[i] > '9')
			return (false);
	}

	return (true);
}

bool PhoneBook::isDuplicatePhoneNumber(std::string phoneNumber) const
{
	for (int i = 0; i < this->contactCount; i++)
	{
		if (this->contacts[i].getPhoneNumber() == phoneNumber)
			return (true);
	}
	return (false);
}

bool PhoneBook::isEmptyOrWhitespace(std::string str) const
{
	if (str.empty())
		return (true);

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (false);
	}

	return (true);
}

bool PhoneBook::containsSubstring(std::string str, std::string sub) const
{
	if (sub.empty())
		return (false);

	if (str.length() < sub.length())
		return (false);

	for (size_t i = 0; i <= str.length() - sub.length(); i++)
	{
		bool match = true;
		for (size_t j = 0; j < sub.length(); j++)
		{
			char c1 = str[i + j];
			char c2 = sub[j];
			if (c1 >= 'A' && c1 <= 'Z')
				c1 = c1 + 32;
			if (c2 >= 'A' && c2 <= 'Z')
				c2 = c2 + 32;
			if (c1 != c2)
			{
				match = false;
				break;
			}
		}
		if (match)
			return (true);
	}
	return (false);
}

void PhoneBook::displayPartialSearchResults(std::string query) const
{
	int matchCount = 0;

	for (int i = 0; i < this->contactCount; i++)
	{
		if (containsSubstring(this->contacts[i].getFirstName(), query) ||
			containsSubstring(this->contacts[i].getLastName(), query) ||
			containsSubstring(this->contacts[i].getNickname(), query))
		{
			if (matchCount == 0)
			{
				std::cout << std::setw(10) << "Index" << "|";
				std::cout << std::setw(10) << "First Name" << "|";
				std::cout << std::setw(10) << "Last Name" << "|";
				std::cout << std::setw(10) << "Nickname" << std::endl;
			}
			std::cout << std::setw(10) << i << "|";
			std::cout << std::setw(10) << truncateField(this->contacts[i].getFirstName()) << "|";
			std::cout << std::setw(10) << truncateField(this->contacts[i].getLastName()) << "|";
			std::cout << std::setw(10) << truncateField(this->contacts[i].getNickname()) << std::endl;
			matchCount++;
		}
	}

	if (matchCount == 0)
		std::cout << "No contacts found matching '" << query << "'" << std::endl;
	else
		std::cout << "Found " << matchCount << " contact(s)" << std::endl;
}

void PhoneBook::addContact()
{
	std::string input;
	int index;

	if (this->contactCount < 8)
		index = this->contactCount;
	else
		index = this->oldestIndex;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	if (isEmptyOrWhitespace(input))
	{
		std::cout << "Field cannot be empty or contain only whitespace!" << std::endl;
		return;
	}
	this->contacts[index].setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	if (isEmptyOrWhitespace(input))
	{
		std::cout << "Field cannot be empty or contain only whitespace!" << std::endl;
		return;
	}
	this->contacts[index].setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	if (isEmptyOrWhitespace(input))
	{
		std::cout << "Field cannot be empty or contain only whitespace!" << std::endl;
		return;
	}
	this->contacts[index].setNickname(input);

	while (true)
	{
		std::cout << "Enter phone number (7-15 digits): ";
		std::getline(std::cin, input);
		
		if (std::cin.eof())
			return;
			
		if (isEmptyOrWhitespace(input))
		{
			std::cout << "Field cannot be empty or contain only whitespace!" << std::endl;
			continue;
		}
		if (!isValidPhoneNumber(input))
		{
			std::cout << "Invalid phone number! Must contain only digits (7-15 characters)." << std::endl;
			continue;
		}
		if (isDuplicatePhoneNumber(input))
		{
			std::cout << "This phone number already exists in the phonebook!" << std::endl;
			continue;
		}
		break;
	}
	this->contacts[index].setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	if (isEmptyOrWhitespace(input))
	{
		std::cout << "Field cannot be empty or contain only whitespace!" << std::endl;
		return;
	}
	this->contacts[index].setDarkestSecret(input);

	this->contacts[index].setFavorite(false);
	this->contacts[index].setBlocked(false);

	if (this->contactCount < 8)
		this->contactCount++;

	this->oldestIndex = (this->oldestIndex + 1) % 8;
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContact() const
{
	if (this->contactCount == 0)
	{
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}

	displayContactList();

	std::string input;
	int index;

	std::cout << "Enter index to display (or name to search): ";
	std::getline(std::cin, input);

	if (input.empty())
	{
		std::cout << "Input cannot be empty!" << std::endl;
		return;
	}

	if (isValidIndex(input, &index))
	{
		displayContactDetails(index);
	}
	else
	{
		displayPartialSearchResults(input);
	}
}

void PhoneBook::markFavorite()
{
	if (this->contactCount == 0)
	{
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}

	displayContactList();

	std::string input;
	int index;

	std::cout << "Enter index to mark/unmark as favorite: ";
	std::getline(std::cin, input);

	if (!isValidIndex(input, &index))
	{
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	this->contacts[index].toggleFavorite();

	if (this->contacts[index].getFavorite())
		std::cout << "Contact marked as FAVORITE!" << std::endl;
	else
		std::cout << "Contact removed from favorites." << std::endl;
}

void PhoneBook::blockContact()
{
	if (this->contactCount == 0)
	{
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}

	displayContactList();

	std::string input;
	int index;

	std::cout << "Enter index to block/unblock: ";
	std::getline(std::cin, input);

	if (!isValidIndex(input, &index))
	{
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	this->contacts[index].toggleBlocked();

	if (this->contacts[index].getBlocked())
		std::cout << "Contact BLOCKED!" << std::endl;
	else
		std::cout << "Contact unblocked." << std::endl;
}
