#include "FragTrap.hpp"

int main(void) {
	std::cout << "=== Test 1: FragTrap construction ===" << std::endl;
	FragTrap frag1("Bomber");
	
	std::cout << "\n=== Test 2: FragTrap attacks ===" << std::endl;
	frag1.attack("Target");
	frag1.takeDamage(40);
	frag1.beRepaired(25);
	
	std::cout << "\n=== Test 3: High fives ===" << std::endl;
	frag1.highFivesGuys();
	
	std::cout << "\n=== Test 4: Heavy damage ===" << std::endl;
	frag1.takeDamage(90);
	frag1.attack("Someone");
	frag1.highFivesGuys();
	
	std::cout << "\n=== Test 5: Copy constructor ===" << std::endl;
	FragTrap frag2(frag1);
	frag2.highFivesGuys();
	
	std::cout << "\n=== Test 6: Assignment operator ===" << std::endl;
	FragTrap frag3("Temporary");
	frag3 = frag1;
	frag3.attack("Enemy");
	
	std::cout << "\n=== Destructors ===" << std::endl;
	return 0;
}
