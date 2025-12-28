#include "Contact.hpp"

Contact::Contact()
{
	this->isFavorite = false;
	this->isBlocked = false;
}

Contact::~Contact()
{
}

void Contact::setFirstName(std::string value)
{
	this->firstName = value;
}

void Contact::setLastName(std::string value)
{
	this->lastName = value;
}

void Contact::setNickname(std::string value)
{
	this->nickname = value;
}

void Contact::setPhoneNumber(std::string value)
{
	this->phoneNumber = value;
}

void Contact::setDarkestSecret(std::string value)
{
	this->darkestSecret = value;
}

std::string Contact::getFirstName() const
{
	return (this->firstName);
}

std::string Contact::getLastName() const
{
	return (this->lastName);
}

std::string Contact::getNickname() const
{
	return (this->nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (this->phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (this->darkestSecret);
}

void Contact::setFavorite(bool value)
{
	this->isFavorite = value;
}

void Contact::setBlocked(bool value)
{
	this->isBlocked = value;
}

bool Contact::getFavorite() const
{
	return (this->isFavorite);
}

bool Contact::getBlocked() const
{
	return (this->isBlocked);
}

void Contact::toggleFavorite()
{
	this->isFavorite = !this->isFavorite;
}

void Contact::toggleBlocked()
{
	this->isBlocked = !this->isBlocked;
}
