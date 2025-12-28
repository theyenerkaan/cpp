#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		this->templates[i] = 0;
	}
}

MateriaSource::MateriaSource(MateriaSource const &src) {
	for (int i = 0; i < 4; i++) {
		if (src.templates[i]) {
			this->templates[i] = src.templates[i]->clone();
		} else {
			this->templates[i] = 0;
		}
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			if (this->templates[i]) {
				delete this->templates[i];
				this->templates[i] = 0;
			}
			if (rhs.templates[i]) {
				this->templates[i] = rhs.templates[i]->clone();
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		if (this->templates[i]) {
			delete this->templates[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (!this->templates[i]) {
			this->templates[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (this->templates[i] && this->templates[i]->getType() == type) {
			return this->templates[i]->clone();
		}
	}
	return 0;
}
