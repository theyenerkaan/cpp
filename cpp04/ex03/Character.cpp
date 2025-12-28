#include "Character.hpp"

Character::Character(void) : name("unnamed") {
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = 0;
	}
}

Character::Character(std::string const &charName) : name(charName) {
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = 0;
	}
}

Character::Character(Character const &src) : name(src.name) {
	for (int i = 0; i < 4; i++) {
		if (src.inventory[i]) {
			this->inventory[i] = src.inventory[i]->clone();
		} else {
			this->inventory[i] = 0;
		}
	}
}

Character &Character::operator=(Character const &rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		for (int i = 0; i < 4; i++) {
			if (this->inventory[i]) {
				delete this->inventory[i];
				this->inventory[i] = 0;
			}
			if (rhs.inventory[i]) {
				this->inventory[i] = rhs.inventory[i]->clone();
			}
		}
	}
	return *this;
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i]) {
			delete this->inventory[i];
		}
	}
}

std::string const &Character::getName(void) const {
	return this->name;
}

void Character::equip(AMateria* m) {
	if (!m) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (!this->inventory[i]) {
			this->inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && this->inventory[idx]) {
		this->inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && this->inventory[idx]) {
		this->inventory[idx]->use(target);
	}
}
