#include <iostream>
#include <time.h>

#define SIZE 10
//fill field with 0 - which means empty place on map
void fillField(char field[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			field[i][j] = 0;
}

//check if the ship can be placed on the position - if not, return false
bool checkPosition(char field[][SIZE], int ship_size, int direction, int x, int y) {

	for (int i = 0; i < ship_size; i++)
	{
		if (x >= SIZE || y >= SIZE || x < 0 || y < 0 || field[x][y] != 0) return false;
		if (direction == 0) //horizontal
			x++;
		else //vertical
			y++;
	}
	return true;
}
/*randomly place ships on the field 
4 ships of size 1, 
3 ships of size 2, 
2 ships of size 3, 
1 ship of size 4 */ 
void placeShip(char field[][SIZE], int ship_size, int direction, int x, int y)
{
	for (int i = 0; i < ship_size; i++)
	{
		if (direction == 0) //horizontal
			field[x + i][y] = (-1)*ship_size;
		else //vertical
			field[x][y + i] = (-1)*ship_size;
	}
}

void placeShipsOnField(char field[][SIZE])
{
	for (int ship_size = 1; ship_size <= 4; ship_size++)
	{
		int ship_count = 5 - ship_size;
		for (int j = 1; j <= ship_count; j++)
		{
			int direction, x, y;
			do
			{
				direction = rand() % 2;
				x = rand() % SIZE;
				y = rand() % SIZE;
			} while (!checkPosition(field, ship_size, direction, x, y));
		}
	}
}
int main(int argc, char* argv[])
{
	srand(time(NULL));
	//Declaration od the game field
	char field[SIZE][SIZE];
	return 0;
}