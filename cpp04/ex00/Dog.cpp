#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	this->type = "Dog";
	std::cout << "Dog: Constructor called for a loyal companion" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src) {
	std::cout << "Dog: Copy constructor called" << std::endl;
	*this = src;
}

Dog &Dog::operator=(Dog const &rhs) {
	std::cout << "Dog: Assignment operator called" << std::endl;
	if (this != &rhs) {
		Animal::operator=(rhs);
	}
	return *this;
}

Dog::~Dog(void) {
	std::cout << "Dog: Destructor called, goodbye friend" << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "Dog: Woof! Woof!" << std::endl;
}
