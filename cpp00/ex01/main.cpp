#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, FAV, BLOCK, EXIT): ";
		std::getline(std::cin, command);

		if (std::cin.eof())
			break;

		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "FAV")
			phoneBook.markFavorite();
		else if (command == "BLOCK")
			phoneBook.blockContact();
		else if (command == "EXIT")
			break;
		else if (!command.empty())
			std::cout << "Invalid command!" << std::endl;
	}

	return (0);
}
