#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat: A mysterious feline has appeared" << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src) {
	std::cout << "Cat: Copy constructor invoked" << std::endl;
	this->brain = new Brain(*src.brain);
}

Cat &Cat::operator=(Cat const &rhs) {
	std::cout << "Cat: Assignment operator invoked" << std::endl;
	if (this != &rhs) {
		Animal::operator=(rhs);
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return *this;
}

Cat::~Cat(void) {
	delete this->brain;
	std::cout << "Cat: The feline departs silently" << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << "Cat: Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain(void) const {
	return this->brain;
}
