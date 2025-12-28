#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
}

Ice::Ice(Ice const &src) : AMateria(src) {
}

Ice &Ice::operator=(Ice const &rhs) {
	if (this != &rhs) {
		AMateria::operator=(rhs);
	}
	return *this;
}

Ice::~Ice(void) {
}

AMateria* Ice::clone(void) const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
