#include "Snake.h"
#include "Utilities.hpp"
#include <iostream>

Snake::Snake():gameEnd{ false }, width{ 15 }, height{ 10 }, headX{ 0 }, headY{ 0 }, FruitX{ 0 }, FruitY{ 0 }, score{ 0 }{}



void Snake::draw()
{
	clearScreen();

	placeXY(0, 25);
	std::cout << "Score = " << score;

	placeXY(FruitX, FruitY);
	std::cout << "F";

	for (int i = 0; i <= Snake::width ; i++)
	{
		placeXY(i,0);
		std::cout << "*";
	}
	for (int i = 1; i < Snake::height; i++)
	{
		placeXY(0, i);
		std::cout << "*";
	}
	for (int i = 1; i < Snake::height; i++)
	{
		placeXY(Snake::width, i);
		std::cout << "*";
	}
	for (int i = 0; i <= Snake::width; i++)
	{
		placeXY(i, Snake::height);
		std::cout << "*";
	}

	placeXY(headX, headY);
	std::cout << "O";

	for (int k = 0;k < nTail ; k++)
	{
		placeXY(tailX[k], tailY[k]);
		std::cout << 'o';
	}

	
}

void Snake::fruitSetUp()
{
	randomNumberSeed();
	FruitX = (randomNumber()%10);
	randomNumberSeed();
	FruitY = (randomNumber()%10);
	if (FruitX == 0) 
	{ 
		FruitX = FruitX + 1; 
	}
	if (FruitY == 0) 
	{
		FruitY = FruitY + 1; 
	}
	if (headX == FruitX && headY == FruitY)
	{
		fruitSetUp();
	}
}

void Snake::snakeSetUp()
{
	headX = width / 2;
	headY = height / 2;
}

void Snake::moveLeft()
{

	headX = headX - 1;
	if (headX == 0)
	{
		headX = width - 1;
	}

}
	
void Snake::moveRight()
{
	headX = headX + 1;
	if (headX == width)
	{
		headX = 1;
	}
}

void Snake::moveUp()
{
	headY = headY - 1;
	if (headY == 0)
	{
		headY = height-1;
	}
}

void Snake::moveDown()
{
	headY = headY + 1;
	if (headY == height)
	{
		headY = 1;
	}
}

void Snake::moveLogic(char moveDir)
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = headX;
	tailY[0] = headY;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	
	if (moveDir == 'a')
	{
		moveLeft();
	}
	else if(moveDir == 'd')
	{
		moveRight();
	}
	else if (moveDir == 'w')
	{
		moveUp();
	}
	else if (moveDir == 's')
	{
		moveDown();
	}


	for (int i = 0; i < nTail; i++)
	{
		if (headX == tailX[i] && headY == tailY[i])
		{
			gameEnd = true;
		}
	}

	if (headX == FruitX && headY == FruitY)
	{
		score = score + 1;
		fruitSetUp();
		nTail++;
	}
}

bool Snake::done()
{
	if (gameEnd)
	{
		return(false);
	}
	else
	{
		return(true);
	}
}

