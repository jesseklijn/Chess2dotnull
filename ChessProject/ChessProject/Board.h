#pragma once
class Board
{
public:
	
	Board();
	~Board();
	bool CheckConnection(int xInc, int yInc, int x, int y);
	int width = 5, height = 5, xSize = 5, ySize = 5;
	string *display;



};

