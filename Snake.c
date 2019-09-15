#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

bool gameover;
const int width = 20;
const int height = 20;

int x, y, food_x, food_y, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;

void setup() {
	gameover = false;
	dir = STOP;
	
	x = width / 2; //center
	y = width / 2;

	food_x = rand() % width;
	food_y = rand() % height;

	score = 0;
}

void draw() {
	system("cls"); //system("clear");
	for (int i = 0; i < height; i++)
	{
		cout << "\n";
		for (int j = 0; j < width; j++)
		{
			// Print @ if this is first row 
			// or last row. Or this column 
			// is first or last. 
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
			{
				cout << "@";
			}
			else if (i == x && j == y) // printing the snake head
				{
					cout << "o";
				}
			else if (i == food_x && j == food_y) 
				{
				cout << "x";
				}

			else
				cout << " ";
		}
	}
}


void logic() {


}

void input() {
	    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}


void printRectangle(int h, int w)
{
	for (int i = 0; i < h; i++)
	{
		cout << "\n";
		for (int j = 0; j < w; j++)
		{
			// Print @ if this is first row 
			// or last row. Or this column 
			// is first or last. 
			if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
				cout << "@";
			else
				cout << " ";
		}
	}
}
int main() {
	//printRectangle(10, 10);
	setup();
	while (!gameover)
	{
		draw();
		input();
		logic();
		Sleep(10);
	}

	return 0;
}
