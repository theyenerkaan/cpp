#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
	std::cout << "=== TEST 1: Basic Animal Construction ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << "\n=== TEST 2: Type Checking ===" << std::endl;
	std::cout << "Type: " << dog->getType() << std::endl;
	std::cout << "Type: " << cat->getType() << std::endl;
	
	std::cout << "\n=== TEST 3: Polymorphic Sound (VIRTUAL) ===" << std::endl;
	std::cout << "Generic animal: ";
	meta->makeSound();
	std::cout << "Dog says: ";
	dog->makeSound();
	std::cout << "Cat says: ";
	cat->makeSound();
	
	std::cout << "\n=== TEST 4: Cleanup ===" << std::endl;
	delete meta;
	delete dog;
	delete cat;
	
	std::cout << "\n=== TEST 5: Wrong Classes (NO VIRTUAL) ===" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << "\nType: " << wrongCat->getType() << std::endl;
	std::cout << "WrongAnimal pointer -> WrongAnimal sound: ";
	wrongMeta->makeSound();
	std::cout << "WrongAnimal pointer -> WrongCat (but calls base!): ";
	wrongCat->makeSound();
	
	std::cout << "\n=== TEST 6: Direct WrongCat ===" << std::endl;
	const WrongCat* directWrongCat = new WrongCat();
	std::cout << "Direct WrongCat pointer: ";
	directWrongCat->makeSound();
	
	std::cout << "\n=== TEST 7: Wrong Cleanup ===" << std::endl;
	delete wrongMeta;
	delete wrongCat;
	delete directWrongCat;
	
	std::cout << "\n=== TEST 8: Copy Constructor ===" << std::endl;
	Dog originalDog;
	Dog copiedDog(originalDog);
	std::cout << "Original: ";
	originalDog.makeSound();
	std::cout << "Copied: ";
	copiedDog.makeSound();
	
	return 0;
}
