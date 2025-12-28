#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const &trapName) : ClapTrap(trapName) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
}

void ScavTrap::attack(std::string const &target) {
	if (this->energyPoints <= 0) {
		std::cout << "ScavTrap " << this->name << " has no energy to attack!" << std::endl;
		return;
	}
	if (this->hitPoints <= 0) {
		std::cout << "ScavTrap " << this->name << " is already destroyed!" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ScavTrap " << this->name << " fiercely attacks " << target 
		<< ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}
