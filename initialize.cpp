#include <iostream>
#include "Snake.h"
#include "Utilities.hpp"
#include <conio.h>

int main()
{
    Snake snake;
    snake.fruitSetUp();
    snake.snakeSetUp();
    snake.draw();
    bool flag = true;
    char moveDir = ' ';
    int c = 0;
    while (flag)
    {
        if (c == 0)
        {
            moveDir = getChar();
            c = c + 1;
        }
        else
        {
            if (_kbhit())
            {
                moveDir = getChar();
            }
        }
        snake.moveLogic(moveDir);
        snake.draw();
        flag = snake.done();
    }
    placeXY(25, 25);
}
