#include "Zombie.hpp"

int	main(void)
{
	Zombie*	horde;
	int		count;
	int		i;

	count = 5;
	horde = zombieHorde(count, "Horde Member");
	
	if (!horde)
		return 1;
	
	i = 0;
	while (i < count)
	{
		horde[i].announce();
		i++;
	}
	
	delete[] horde;
	
	return 0;
}
