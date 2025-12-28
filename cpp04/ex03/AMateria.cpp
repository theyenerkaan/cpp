#include "AMateria.hpp"

AMateria::AMateria(void) : type("unknown") {
}

AMateria::AMateria(std::string const &materialType) : type(materialType) {
}

AMateria::AMateria(AMateria const &src) {
	*this = src;
}

AMateria &AMateria::operator=(AMateria const &rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

AMateria::~AMateria(void) {
}

std::string const &AMateria::getType(void) const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}
