#include "ClapTrap.hpp"

int main(void) {
	std::cout << "=== Test 1: Basic construction ===" << std::endl;
	ClapTrap trap1("Robot");
	
	std::cout << "\n=== Test 2: Attack and take damage ===" << std::endl;
	trap1.attack("Enemy");
	trap1.takeDamage(5);
	trap1.beRepaired(3);
	
	std::cout << "\n=== Test 3: Energy depletion ===" << std::endl;
	for (int i = 0; i < 10; i++) {
		trap1.attack("Target");
	}
	trap1.attack("Target");
	
	std::cout << "\n=== Test 4: HP depletion ===" << std::endl;
	ClapTrap trap2("Fragile");
	trap2.takeDamage(10);
	trap2.attack("Someone");
	trap2.beRepaired(5);
	
	std::cout << "\n=== Test 5: Copy constructor ===" << std::endl;
	ClapTrap trap3("Original");
	ClapTrap trap4(trap3);
	trap4.attack("Clone target");
	
	std::cout << "\n=== Test 6: Assignment operator ===" << std::endl;
	ClapTrap trap5("First");
	ClapTrap trap6("Second");
	trap6 = trap5;
	trap6.attack("Assigned target");
	
	std::cout << "\n=== Destructors ===" << std::endl;
	return 0;
}
