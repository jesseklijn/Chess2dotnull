#include "stdafx.h"
#include "Board.h"
#include "Tile.h"
#include "BoardDisplay.h"
#include <iostream>


Board::~Board()
{
}
//Default constructor  when board class is initialized
Board::Board()
{
	Tile **tileMap = new Tile*[height]();
	for (int y = 0; y < height; ++y) {
		tileMap[y] = new Tile[width]();
	}

	//geef posities aan tiles
	const int BOUNDS = 2;
	int x = 0, y = 0;
	int amounOfOptions = 0;
	while (x < height)
	{
		while (y < width) {
			tileMap[x][y].xPos = x;
			tileMap[x][y].yPos = y;

			if (CheckConnection(-2, -1, x, y) == true) {
				amounOfOptions++;
			}
			if (CheckConnection(-2, -2, x, y) == true) {
				amounOfOptions++;
			}
			if (CheckConnection(-2, 1, x, y) == true) {
				amounOfOptions++;
			}
			if (CheckConnection(-1, 2, x, y) == true) {
				amounOfOptions++;
			}
			if (CheckConnection(+1, 2, x, y) == true) {
				amounOfOptions++;
			}
			if (CheckConnection(+2, 1, x, y) == true) {
				amounOfOptions++;
			}
			if (CheckConnection(+2, -1, x, y) == true) {
				amounOfOptions++;
			}
			if (CheckConnection(+1, -2, x, y) == true) {

				amounOfOptions++;
			}

			//Create new connections y the size of the options
			tileMap[x][y].connectedTiles = new Tile*[amounOfOptions];
			tileMap[x][y].amountOfConnections = amounOfOptions;
			tileMap[x][y].CalculateConnections(tileMap);

			//Reset
			amounOfOptions = 0;



			//Display all chess pieces

				//std::cout << "Length of array["<< x << y << +  "]= " << tileMap[x][y].amountOfConnections << std::endl;


			y++;
		}
		y = 0;
		x++;
	}

	//cout << width << " * " << height << " = " << width * height << endl;

	display = new string[(height*ySize) + BOUNDS];
	for (size_t y = 0; y < sizeof(display) / sizeof(display[0]); y++)
	{
		if (y == 0) {
			//opener

		}
		else if(y != 0 && y != height) {
			//contents
		}
		else {
			//closer
		}

	}

	for (size_t i = 0; i <  sizeof(display) / sizeof(display[0]); i++)
	{
		cout << display[i];
	}
	cout << endl;
	system("pause");

}

//Add one or more connections to tiles
bool Board::CheckConnection(int xInc, int yInc, int x, int y)
{
	// 1 < 0 == false 
	if ((xInc + x) > 0 && (yInc + y) > 0) {
		//printf("true ");
		return true;

	}
	else {
		//printf("false ");
		return false;

	}
}





