#include "ScavTrap.hpp"

int main(void) {
	std::cout << "=== Test 1: ScavTrap construction ===" << std::endl;
	ScavTrap scav1("Guardian");
	
	std::cout << "\n=== Test 2: ScavTrap vs ClapTrap attack ===" << std::endl;
	ClapTrap clap1("Weak");
	clap1.attack("Enemy");
	scav1.attack("Enemy");
	
	std::cout << "\n=== Test 3: Guard Gate ===" << std::endl;
	scav1.guardGate();
	
	std::cout << "\n=== Test 4: Damage and repair ===" << std::endl;
	scav1.takeDamage(30);
	scav1.beRepaired(20);
	scav1.takeDamage(95);
	scav1.attack("Someone");
	
	std::cout << "\n=== Test 5: Copy constructor ===" << std::endl;
	ScavTrap scav2(scav1);
	scav2.guardGate();
	
	std::cout << "\n=== Test 6: Assignment operator ===" << std::endl;
	ScavTrap scav3("Temp");
	scav3 = scav1;
	scav3.attack("Target");
	
	std::cout << "\n=== Destructors ===" << std::endl;
	return 0;
}
