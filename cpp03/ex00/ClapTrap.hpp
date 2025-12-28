#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap {
	private:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;

	public:
		ClapTrap(void);
		ClapTrap(std::string const &trapName);
		ClapTrap(ClapTrap const &other);
		ClapTrap &operator=(ClapTrap const &other);
		~ClapTrap(void);

		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
