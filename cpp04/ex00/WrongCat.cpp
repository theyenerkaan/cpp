#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	this->type = "WrongCat";
	std::cout << "WrongCat: Constructor executed" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src) {
	std::cout << "WrongCat: Copy constructor executed" << std::endl;
	*this = src;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs) {
	std::cout << "WrongCat: Assignment operator executed" << std::endl;
	if (this != &rhs) {
		WrongAnimal::operator=(rhs);
	}
	return *this;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat: Destructor executed" << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << "WrongCat: Wrong meow sound!" << std::endl;
}
