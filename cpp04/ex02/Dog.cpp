#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog: Constructor called for a loyal companion" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src) {
	std::cout << "Dog: Copy constructor called" << std::endl;
	this->brain = new Brain(*src.brain);
}

Dog &Dog::operator=(Dog const &rhs) {
	std::cout << "Dog: Assignment operator called" << std::endl;
	if (this != &rhs) {
		Animal::operator=(rhs);
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return *this;
}

Dog::~Dog(void) {
	delete this->brain;
	std::cout << "Dog: Destructor called, goodbye friend" << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "Dog: Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain(void) const {
	return this->brain;
}
