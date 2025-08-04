#include "Zombie.hpp"

int	main(void)
{
	Zombie *heapZombie = newZombie("Heap Zombie");
	randomChump("Stack Zombie");
	delete heapZombie;
	return (0);
}