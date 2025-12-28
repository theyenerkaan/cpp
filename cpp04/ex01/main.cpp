#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
	std::cout << "=== TEST 1: Create Animal Array ===" << std::endl;
	const int arraySize = 6;
	Animal* animals[arraySize];
	
	for (int i = 0; i < arraySize / 2; i++) {
		std::cout << "\n[Creating Dog " << i << "]" << std::endl;
		animals[i] = new Dog();
	}
	
	for (int i = arraySize / 2; i < arraySize; i++) {
		std::cout << "\n[Creating Cat " << i << "]" << std::endl;
		animals[i] = new Cat();
	}
	
	std::cout << "\n=== TEST 2: Make Sounds ===" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		std::cout << animals[i]->getType() << " says: ";
		animals[i]->makeSound();
	}
	
	std::cout << "\n=== TEST 3: Deep Copy Test - Dog ===" << std::endl;
	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "I love bones!");
	originalDog.getBrain()->setIdea(1, "Chase the mailman!");
	
	std::cout << "\nCreating copy..." << std::endl;
	Dog copiedDog(originalDog);
	
	std::cout << "\nOriginal Dog's brain address: " << originalDog.getBrain() << std::endl;
	std::cout << "Copied Dog's brain address: " << copiedDog.getBrain() << std::endl;
	std::cout << "Original idea[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied idea[0]: " << copiedDog.getBrain()->getIdea(0) << std::endl;
	
	std::cout << "\nModifying copied dog's idea..." << std::endl;
	copiedDog.getBrain()->setIdea(0, "I prefer treats!");
	std::cout << "Original idea[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied idea[0]: " << copiedDog.getBrain()->getIdea(0) << std::endl;
	
	std::cout << "\n=== TEST 4: Deep Copy Test - Cat ===" << std::endl;
	Cat originalCat;
	originalCat.getBrain()->setIdea(0, "Knock things off tables");
	
	Cat assignedCat;
	std::cout << "\nAssigning cat..." << std::endl;
	assignedCat = originalCat;
	
	std::cout << "Original Cat's brain: " << originalCat.getBrain() << std::endl;
	std::cout << "Assigned Cat's brain: " << assignedCat.getBrain() << std::endl;
	std::cout << "Original idea: " << originalCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "Assigned idea: " << assignedCat.getBrain()->getIdea(0) << std::endl;
	
	std::cout << "\n=== TEST 5: Polymorphic Delete ===" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		std::cout << "\n[Deleting " << animals[i]->getType() << " " << i << "]" << std::endl;
		delete animals[i];
	}
	
	std::cout << "\n=== TEST 6: Cleanup Copies ===" << std::endl;
	
	return 0;
}
