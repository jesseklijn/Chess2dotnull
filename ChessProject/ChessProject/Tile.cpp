#include "stdafx.h"
#include "Tile.h"
#include "Settings.h"

/*

[00][01][02][03][04]
[10][11][12][13][14]
[20][21][22][23][24]
[30][31][32][33][34]
[40][41][42][43][44]
*/
/*
//1  [22] -[21] ->[01]  = [-2,-1]
//2  [22] -[12] ->[10]  = [-1,-2]
//3  [22] -[19] ->[03]  = [-2,+1]
//4  [22] -[08] ->[14]  = [-1,+2]
//5  [22] +[12] ->[34]  = [+1,+2]
//6  [22] +[21] ->[43]  = [+2,+1]
//7  [22] +[19] ->[41]  = [+2,-1]
//8  [22] +[08] ->[30]  = [+1,-2]

*/


Tile::Tile()
{

	xPos = 0;
	yPos = 0;
	amountOfConnections = 0;
	//Create connectedTiles
	Settings settings;

}


Tile::~Tile()
{
}



void Tile::Disable()
{
	used = true;

	//After the tile has been used, delete it to free memory space.
	delete[] connectedTiles;
}

void Tile::CalculateConnections(Tile **tileMap)
{
	for (size_t i = 0; i < amountOfConnections; i++)
	{
		if (i == 0) connectedTiles[0] = &tileMap[-2 + xPos][-2 + yPos];
		if (i == 1) connectedTiles[1] = &tileMap[-2 + xPos][1 + yPos];
		if (i == 2) connectedTiles[2] = &tileMap[-1 + xPos][2 + yPos];
		if (i == 3) connectedTiles[3] = &tileMap[1 + xPos][2 + yPos];
		if (i == 4) connectedTiles[4] = &tileMap[2 + xPos][1 + yPos];
		if (i == 5) connectedTiles[5] = &tileMap[2 + xPos][-1 + yPos];
		if (i == 6) connectedTiles[6] = &tileMap[1 + xPos][-2 + yPos];
		if (i == 6) connectedTiles[7] = &tileMap[-2 + xPos][-1 + yPos];
	}
}

