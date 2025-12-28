#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	bool isFavorite;
	bool isBlocked;

public:
	Contact();
	~Contact();

	void setFirstName(std::string value);
	void setLastName(std::string value);
	void setNickname(std::string value);
	void setPhoneNumber(std::string value);
	void setDarkestSecret(std::string value);
	void setFavorite(bool value);
	void setBlocked(bool value);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
	bool getFavorite() const;
	bool getBlocked() const;

	void toggleFavorite();
	void toggleBlocked();
};

#endif
