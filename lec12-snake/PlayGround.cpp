#include <vector>
#include <cassert>
#include <cstdlib>
#include "PlayGround.h"

using namespace std;

PlayGround::PlayGround(int width, int height)
    : squares(height, vector<CellType>(width, CELL_EMPTY)),
      snake(this),
      status(GAME_RUNNING),
      score(0)
{
    addCherry();
}

PlayGround::~PlayGround()
{
    //dtor
}

void PlayGround::changeCellState(Position pos, CellType type)
{
    assert(pos.isInsideBox(0,0,getWidth(),getHeight()));
    squares[pos.y][pos.x] = type;
}

void PlayGround::processUserInput(UserInput input)
{
    snake.processUserInput(input);
}

void PlayGround::nextStep()
{
    snake.nextStep();
}

void PlayGround::addCherry()
{
    do {
        Position p(rand()%getWidth(), rand()%getHeight());
        if (getCellState(p) == CELL_EMPTY) {
            changeCellState(p, CELL_CHERRY);
            break;
        }
    } while (true);
}

void PlayGround::setGameStatus(GameStatus status)
{
    this->status = status;
}

