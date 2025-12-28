#include "Harl.hpp"
#include <iostream>

static int	getLevelIndex(std::string level)
{
	std::string	levels[4];
	int			i;

	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
	
	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
			return i;
		i++;
	}
	return -1;
}

int	main(int argc, char **argv)
{
	Harl	harl;
	int		levelIndex;

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
		return 1;
	}
	
	levelIndex = getLevelIndex(argv[1]);
	
	switch (levelIndex)
	{
		case 0:
			harl.complain("DEBUG");
			__attribute__((fallthrough));
		case 1:
			harl.complain("INFO");
			__attribute__((fallthrough));
		case 2:
			harl.complain("WARNING");
			__attribute__((fallthrough));
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	
	return 0;
}
