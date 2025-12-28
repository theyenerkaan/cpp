#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int contactCount;
	int oldestIndex;

	std::string truncateField(std::string str) const;
	void displayContactList() const;
	void displayContactDetails(int index) const;
	bool isValidIndex(std::string input, int *index) const;
	bool isValidPhoneNumber(std::string phoneNumber) const;
	bool isDuplicatePhoneNumber(std::string phoneNumber) const;
	bool isEmptyOrWhitespace(std::string str) const;
	bool containsSubstring(std::string str, std::string sub) const;
	void displayPartialSearchResults(std::string query) const;

public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContact() const;
	void markFavorite();
	void blockContact();
};

#endif
