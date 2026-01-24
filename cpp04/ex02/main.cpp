#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
	std::cout << "=== TEST 1: Cannot Instantiate Abstract Class ===" << std::endl;
	std::cout << "Trying to create Animal instance..." << std::endl;
	std::cout << "(This would cause compilation error if uncommented)" << std::endl;
	
	std::cout << "\n=== TEST 2: Create Derived Classes ===" << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << "\n=== TEST 3: Polymorphic Calls ===" << std::endl;
	std::cout << dog->getType() << " makes sound: ";
	dog->makeSound();
	std::cout << cat->getType() << " makes sound: ";
	cat->makeSound();
	
	std::cout << "\n=== TEST 4: Array of Animals ===" << std::endl;
	Animal* animals[4];
	
	for (int i = 0; i < 2; i++) {
		std::cout << "\n[Creating Dog " << i << "]" << std::endl;
		animals[i] = new Dog();
	}
	
	for (int i = 2; i < 4; i++) {
		std::cout << "\n[Creating Cat " << i << "]" << std::endl;
		animals[i] = new Cat();
	}
	
	std::cout << "\n=== TEST 5: Sound Test ===" << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}
	
	std::cout << "\n=== TEST 6: Deep Copy Verification ===" << std::endl;
	Dog original;
	original.getBrain()->setIdea(0, "Abstract polymorphism test");
	
	Dog copied(original);
	std::cout << "Brain addresses differ: " 
		<< (original.getBrain() != copied.getBrain() ? "YES" : "NO") << std::endl;
	std::cout << "Ideas copied: " 
		<< (original.getBrain()->getIdea(0) == copied.getBrain()->getIdea(0) ? "YES" : "NO") 
		<< std::endl;
	
	std::cout << "\n=== TEST 7: Cleanup ===" << std::endl;
	delete dog;
	delete cat;
	
	for (int i = 0; i < 4; i++) {
		std::cout << "\n[Deleting " << animals[i]->getType() << " " << i << "]" << std::endl;
		delete animals[i];
	}
	
	std::cout << "\n=== TEST 8: Stack Objects ===" << std::endl;
	
	return 0;
}
