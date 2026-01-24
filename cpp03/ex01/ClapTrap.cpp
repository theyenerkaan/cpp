#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const &trapName) : name(trapName), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " can't attack, it's broken!" << std::endl;
		return;
	}
	if (this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " strikes " << target 
		<< " for " << this->attackDamage << " damage points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " can't take more damage!" << std::endl;
		return;
	}
	this->hitPoints -= amount;
	if (this->hitPoints < 0)
		this->hitPoints = 0;
	std::cout << "ClapTrap " << this->name << " loses " << amount 
		<< " hit points (" << this->hitPoints << " remaining)" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is too damaged to repair itself!" << std::endl;
		return;
	}
	if (this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " doesn't have enough energy!" << std::endl;
		return;
	}
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " recovers " << amount 
		<< " hit points (total: " << this->hitPoints << ")" << std::endl;
}
