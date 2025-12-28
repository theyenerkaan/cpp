#include "DiamondTrap.hpp"

int main(void) {
	std::cout << "=== Test 1: DiamondTrap construction ===" << std::endl;
	DiamondTrap diamond1("Hybrid");
	
	std::cout << "\n=== Test 2: whoAmI function ===" << std::endl;
	diamond1.whoAmI();
	
	std::cout << "\n=== Test 3: Attack (ScavTrap version) ===" << std::endl;
	diamond1.attack("Enemy");
	
	std::cout << "\n=== Test 4: Inherited functions ===" << std::endl;
	diamond1.guardGate();
	diamond1.highFivesGuys();
	diamond1.takeDamage(50);
	diamond1.beRepaired(30);
	
	std::cout << "\n=== Test 5: Copy constructor ===" << std::endl;
	DiamondTrap diamond2(diamond1);
	diamond2.whoAmI();
	
	std::cout << "\n=== Test 6: Assignment operator ===" << std::endl;
	DiamondTrap diamond3("Temp");
	diamond3 = diamond1;
	diamond3.whoAmI();
	diamond3.attack("Target");
	
	std::cout << "\n=== Destructors ===" << std::endl;
	return 0;
}
