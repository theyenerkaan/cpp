#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), diamondName("default") {
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &trapName) : ClapTrap(trapName + "_clap_name"), ScavTrap(trapName), FragTrap(trapName), diamondName(trapName) {
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << this->diamondName << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		this->diamondName = other.diamondName;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << this->diamondName << " destructor called" << std::endl;
}

void DiamondTrap::attack(std::string const &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap name: " << this->diamondName << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
