#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	this->type = "Cat";
	std::cout << "Cat: A mysterious feline has appeared" << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src) {
	std::cout << "Cat: Copy constructor invoked" << std::endl;
	*this = src;
}

Cat &Cat::operator=(Cat const &rhs) {
	std::cout << "Cat: Assignment operator invoked" << std::endl;
	if (this != &rhs) {
		Animal::operator=(rhs);
	}
	return *this;
}

Cat::~Cat(void) {
	std::cout << "Cat: The feline departs silently" << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << "Cat: Meow! Meow!" << std::endl;
}
