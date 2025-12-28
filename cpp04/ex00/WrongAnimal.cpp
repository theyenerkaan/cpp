#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
	std::cout << "WrongAnimal: Base constructor executed" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
	std::cout << "WrongAnimal: Copy constructor executed" << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs) {
	std::cout << "WrongAnimal: Assignment operator executed" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal: Base destructor executed" << std::endl;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal: Some weird noise..." << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}
