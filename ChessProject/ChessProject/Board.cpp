#include "stdafx.h"
#include "Board.h"
#include "Tile.h"
#include "BoardDisplay.h"
#include <iostream>

BoardDisplay display;

//Default constructor  when board class is initialized
Board::Board()
{
	Tile **ary = new Tile*[height]();
	for (int y = 0; y < height; ++y) {
		ary[y] = new Tile[width]();
	}

	//geef posities aan tiles
	for (size_t i = 0; i < height; i++)
	{
		for (size_t i = 0; i < width; i++)
		{

		}
	}

	//gebruik tiles 

	//Geef tiles aan display


	system("pause");
	
}


Board::~Board()
{
}
