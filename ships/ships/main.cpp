#include <iostream>
#include <time.h>

using namespace std;

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
//place ship of size ship_size at direction direction, starts by point x, y
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
/*randomly place ships on the field
4 ships of size 1,
3 ships of size 2,
2 ships of size 3,
1 ship of size 4 */
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
			placeShip(field, ship_size, direction, x, y);
		}
	}
}
void printHeader()
{
	cout << "    ";
	for (int i = 0; i < SIZE; i++) cout << (char)(i + 'A') << " ";
	cout << endl << "   ";
	for (int i = 0; i < SIZE; i++) cout << " -";
	cout << endl;
}
void printFooter()
{
	cout << "   ";
	for (int i = 0; i < SIZE; i++) cout << " -";
	cout << endl << "    ";
	for (int i = 0; i < SIZE; i++) cout << (char)(i + 'A') << " ";
	cout << endl;
}
void printField(char field[][SIZE], bool cheat)
{
	printHeader();
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << " | ";
		for (int j = 0; j < SIZE; j++)
		{
			if (field[i][j] > 0) cout << (char)(field[i][j] + '0') << " ";
			else if (cheat && field[i][j] < 0) cout << (char)((-1) * field[i][j] + '0') << " ";
			else cout << "  ";
		}
		cout << " | " << i << endl;
	}
	printFooter();
}
bool shooted(int x, int y, char field[][SIZE])
{
	if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || field[x][y] == 0) return false;
	field[x][y] = abs(field[x][y]);
	return true;
}
void printInstruction()
{
	cout << "Choose an option: " << endl;
	cout << "S - shoot" << endl;
	cout << "C - cheat" << endl;
	cout << "Q - end" << endl;
}
void printGameScreen(char field[][SIZE])
{
	printInstruction();
	printField(field, false);
}
void shooting(char field[][SIZE])
{
	int x, y;
	cin >> x >> y;
	if (shooted(x, y, field)) cout << "\n Hit! \n";
	else cout << "\n Miss! \n";
}
void cheating(char field[][SIZE])
{
	printField(field, true);
	cout << endl;
}
void gameController(char field[][SIZE])
{
	char option;
	while(true)
	{
		printGameScreen(field);
		cin >> option;
		switch (option)
		{
		case 'S': shooting(field); break;
		case 'C': cheating(field); break;
		case 'Q': return;
		defaut: cout << "Invalid option\n";
		}
	}
}
int main(int argc, char* argv[])
{
	srand(time(NULL));
	//Declaration od the game field
	char field[SIZE][SIZE];
	fillField(field);
	placeShipsOnField(field);
	gameController(field);
	return 0;
}