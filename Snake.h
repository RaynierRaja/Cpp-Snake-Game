#pragma once
#include <vector>
class Snake
{
	bool gameEnd;
	const int width;
	const int height;
	int headX;
	int headY;
	int FruitX;
	int FruitY;
	int score;
	int tailX[100];
	int tailY[100];
	int nTail = 0;
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

public:
	Snake();
	void draw();
	void fruitSetUp();
	void snakeSetUp();;
	void moveLogic(char moveDir);
	bool done();
};
