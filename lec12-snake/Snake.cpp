#include "Snake.h"
#include "PlayGround.h"

Snake::Snake(PlayGround* playGround)
    : position(playGround->getWidth() / 2, playGround->getHeight() / 2),
      playGround(playGround),
      direction(Direction::RIGHT)
{
    playGround->changeCellState(position, CELL_SNAKE);
}

Snake::~Snake()
{
    //dtor
}

void Snake::processUserInput(UserInput input)
{
    inputQueue.push(input);
}

Direction Snake::changeDirection(UserInput input)
{
    switch (input) {
    case KEY_UP:    return direction != DOWN ? UP : direction;
    case KEY_DOWN:  return direction != UP ? DOWN : direction;
    case KEY_LEFT:  return direction != RIGHT ? LEFT : direction;
    case KEY_RIGHT: return direction != LEFT ? RIGHT : direction;
    default:        return direction;
    }
}

void Snake::nextStep()
{
    while (!inputQueue.empty()) {
        UserInput input = inputQueue.front();
        inputQueue.pop();
        Direction newDirection = changeDirection(input);
        if (newDirection != direction) {
            direction = newDirection;
            break;
        }
    }
    Position newPosition = position.move(direction);
    playGround->changeCellState(position, CELL_EMPTY);
    position = newPosition;
    playGround->changeCellState(position, CELL_SNAKE);
}
