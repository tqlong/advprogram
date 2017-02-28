#ifndef GAMEGROUND_H
#define GAMEGROUND_H

#include <vector>
#include "snake.h"

enum CELL_TYPE {
    EMPTY_CELL = 0,
    SNAKE_CELL,
    CHERRY_CELL
};

struct Position
{
    int x;
    int y;
};

class PlayGround
{
    std::vector<std::vector<CELL_TYPE> > squares;
    Snake snake;
public:
    PlayGround();
    ~PlayGround();

    void changeCellState(Position pos, CELL_TYPE type);
};

#endif // GAMEGROUND_H
