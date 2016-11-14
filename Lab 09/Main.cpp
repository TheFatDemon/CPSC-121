// Mario Segura
// CS 121 Fall 16
// Includes our other files and briefly uses them
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Fight.h"

using namespace std;

int main()
{
	srand(time(NULL));
	Fight brawl;
	brawl.getFighters();
	int choice;
	do
	{
		brawl.runFight();
		std::cout << "Would you like a rematch?\n1. Yes\t2. No\n";
		std::cin >> choice;
		if (choice == 1)
			continue;
		else
		{
			std::cout << "Would you like to host another fight?\n1. Yes\t2. No\n";
			std::cin >> choice;
			if (choice == 1)
				brawl.getFighters();
		}
	} while (choice != 2);
	system("pause");
	return 0;
}