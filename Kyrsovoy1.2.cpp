// Kyrsovoy1.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
using namespace std;


char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void drawBoard() 
{
    cout << "   1  2  3" << "\n";
    for (int i = 0; i < 3; i++)
	{
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) 
		{
            cout << "[" << board[i][j] << "]";
        }
        cout << "\n";
    }
}
void comp(char board[3][3])
{
	
    int a = 0, b = 0;
    do
    {
        a = rand() % 3;
        b = rand() % 3;
    } while (board[a][b] != ' ');

    board[a][b] = 'O';

}
bool game_over(char board[3][3], char val)
{
	int c0 = 0;
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[j][i] == val)
				c0++;
			if (board[i][j] == val)
				c1++;
			if (board[j][j] == val)
				c2++;
			if (board[2 - j][j] == val)
				c3++;
		}
		if (c0 == 3 || c1 == 3 || c2 == 3 || c3 == 3)
		{

			return true;
			break;
		}
		c0 = 0;
		c1 = 0;
		c2 = 0;
		c3 = 0;
	}


	return false;
}

int main()
{
    setlocale(0, "");
	srand(time(NULL));
	int a = 0, b = 0;
	cout << "************Добро пожаловать на турнир по игре престолов <Крестики нолики> ************* " << "\n";
	drawBoard();

	while (true)
	{
		cout << "Введите координаты на поле боя, Джон Сноу ";
		cin >> a >> b;
		board[a-1][b-1] = 'X';
		drawBoard();

		if (game_over(board, 'X') )
		{
			cout << "Вы победили! Да здравствует король севера!!!" << "\n";

			break;
		}
		bool boardFull = true;
		for (int i = 0; i < 3; i++) 
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == ' ') 
				{
					boardFull = false;
					break;
				}
			}
		}
		if (boardFull)
		{
			cout << "Ничья! Игра окончена! Всем Дракарис!" << "\n";
			break;
		}
		cout << "Ход Короля Ночи....." << "\n";
		comp(board);
		drawBoard();
		if (game_over(board, 'O') )
		{
			cout << "Ничего ты не знаешь, Джон Сноу!! Белые ходоки обрушили стену!" << "\n";

			break;
		}
		
	}


}









