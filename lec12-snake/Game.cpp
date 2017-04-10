#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include "Game.h"

using namespace std;

Game::Game(int _width, int _height)
    : width(_width), height(_height),
	  squares(_height, vector<CellType>(_width, CELL_EMPTY)),
      snake(*this, Position(_width/2, _height/2)),
      status(GAME_RUNNING),
      score(0),
      currentDirection(Direction::RIGHT)
{
	addCherry();
}

Game::~Game()
{
    //dtor
}

void Game::snakeMoveTo(Position pos) {
	switch(getCellType(pos)) {
		case CELL_OFF_BOARD:
		case CELL_SNAKE: status = GAME_OVER; break;
		case CELL_CHERRY: score++; snake.eatCherry(); addCherry();
		default: setCellType(pos, CELL_SNAKE);
	}
}

void Game::snakeLeave(Position position)
{
	setCellType(position,CELL_EMPTY);
}

void Game::processUserInput(Direction direction)
{
    inputQueue.push(direction);
}

bool Game::canChange(Direction current, Direction next) const {
	if (current == UP || current == DOWN)
		return next == LEFT || next == RIGHT;
	return next == UP || next == DOWN;
}

void Game::nextStep()
{
	while (!inputQueue.empty()) {
        Direction next = inputQueue.front();
        inputQueue.pop();
        if (canChange(currentDirection, next)) {
        	currentDirection = next;
        	break;
		}
    }
    snake.move(currentDirection);
}

void Game::setCellType(Position pos, CellType cellType)
{
	if (pos.isInsideBox(0, 0, width, height)) squares[pos.y][pos.x] = cellType;
}

CellType Game::getCellType(Position pos) const
{
	return pos.isInsideBox(0, 0, width, height) ? squares[pos.y][pos.x] : CELL_OFF_BOARD;
}

void Game::addCherry()
{
    do {
        Position p(rand() % width, rand() % height);
        if (getCellType(p) == CELL_EMPTY) {
        	setCellType(p, CELL_CHERRY);
        	cherryPosition = p;
       		break;
        }
    } while (true);
}

vector<Position> Game::getSnakePositions() const
{
    return snake.getPositions();
}
