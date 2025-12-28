#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string diamondName;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string const &trapName);
		DiamondTrap(DiamondTrap const &other);
		DiamondTrap &operator=(DiamondTrap const &other);
		~DiamondTrap(void);

		void attack(std::string const &target);
		void whoAmI(void);
};

#endif
