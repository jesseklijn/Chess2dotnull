#pragma once
#include "Tile.h"
class Tile
{
public:
	
	//
	int amountOfConnections = 0;
	bool used = false;
	Tile **connectedTiles;
	int xPos = 0 , yPos = 0;
	Tile();
	~Tile();
	
	void Disable();
	void CalculateConnections(Tile **tileMap);
};

