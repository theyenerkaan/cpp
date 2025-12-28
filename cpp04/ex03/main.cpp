#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void) {
	std::cout << "=== TEST 1: Subject Test ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	
	std::cout << "\n=== TEST 2: Inventory Full ===" << std::endl;
	IMateriaSource* source = new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	
	ICharacter* hero = new Character("Hero");
	
	AMateria* overflow = 0;
	for (int i = 0; i < 5; i++) {
		std::cout << "Equipping slot " << i << std::endl;
		AMateria* m = source->createMateria("ice");
		if (i == 4) {
			overflow = m;
		} else {
			hero->equip(m);
		}
	}
	
	std::cout << "Deleting overflow materia that couldn't be equipped" << std::endl;
	delete overflow;
	
	delete hero;
	delete source;
	
	std::cout << "\n=== TEST 3: Unequip Test ===" << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	
	Character* player = new Character("Player");
	ICharacter* enemy = new Character("Enemy");
	
	AMateria* ice1 = src2->createMateria("ice");
	AMateria* cure1 = src2->createMateria("cure");
	AMateria* ice2 = src2->createMateria("ice");
	
	player->equip(ice1);
	player->equip(cure1);
	player->equip(ice2);
	
	std::cout << "\nUsing materias before unequip:" << std::endl;
	player->use(0, *enemy);
	player->use(1, *enemy);
	player->use(2, *enemy);
	
	std::cout << "\nUnequipping slot 1:" << std::endl;
	player->unequip(1);
	
	std::cout << "\nUsing materias after unequip:" << std::endl;
	player->use(0, *enemy);
	player->use(1, *enemy);
	player->use(2, *enemy);
	
	std::cout << "\nManually deleting unequipped materia:" << std::endl;
	delete cure1;
	
	delete enemy;
	delete player;
	delete src2;
	
	std::cout << "\n=== TEST 4: Deep Copy Test ===" << std::endl;
	Character original("Original");
	
	IMateriaSource* src3 = new MateriaSource();
	src3->learnMateria(new Ice());
	src3->learnMateria(new Cure());
	
	original.equip(src3->createMateria("ice"));
	original.equip(src3->createMateria("cure"));
	
	std::cout << "\nCreating copy..." << std::endl;
	Character copied(original);
	
	ICharacter* target = new Character("Target");
	
	std::cout << "\nOriginal uses materias:" << std::endl;
	original.use(0, *target);
	original.use(1, *target);
	
	std::cout << "\nCopied uses materias:" << std::endl;
	copied.use(0, *target);
	copied.use(1, *target);
	
	delete target;
	delete src3;
	
	std::cout << "\n=== TEST 5: Unknown Materia Type ===" << std::endl;
	IMateriaSource* src4 = new MateriaSource();
	src4->learnMateria(new Ice());
	
	AMateria* unknown = src4->createMateria("fire");
	if (unknown == 0) {
		std::cout << "Cannot create unknown materia type 'fire'" << std::endl;
	}
	
	delete src4;
	
	std::cout << "\n=== TEST 6: Invalid Use ===" << std::endl;
	Character tester("Tester");
	ICharacter* dummy = new Character("Dummy");
	
	std::cout << "Using empty slot:" << std::endl;
	tester.use(0, *dummy);
	
	std::cout << "Using invalid index:" << std::endl;
	tester.use(-1, *dummy);
	tester.use(10, *dummy);
	
	delete dummy;
	
	std::cout << "\n=== Cleanup ===" << std::endl;
	return 0;
}
