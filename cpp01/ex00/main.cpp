#include "Zombie.hpp"

int	main(void)
{
	Zombie*	heapZombie;

	heapZombie = newZombie("Heap Walker");
	heapZombie->announce();
	
	randomChump("Stack Dweller");
	
	heapZombie->announce();
	delete heapZombie;
	
	return 0;
}
