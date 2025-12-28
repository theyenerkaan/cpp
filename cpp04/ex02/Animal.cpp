#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {
	std::cout << "Animal: Default constructor invoked" << std::endl;
}

Animal::Animal(Animal const &src) {
	std::cout << "Animal: Copy constructor invoked" << std::endl;
	*this = src;
}

Animal &Animal::operator=(Animal const &rhs) {
	std::cout << "Animal: Assignment operator invoked" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

Animal::~Animal(void) {
	std::cout << "Animal: Destructor invoked" << std::endl;
}

std::string Animal::getType(void) const {
	return this->type;
}
