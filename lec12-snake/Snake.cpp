#include "Snake.h"
#include "PlayGround.h"

Snake::Snake(PlayGround* playGround)
    : head( new SnakeNode (
              Position(playGround->getWidth() / 2, playGround->getHeight() / 2)
            ) ),
      playGround(playGround),
      direction(Direction::RIGHT),
      cherry(0)
{
    changePlayGroundState(CELL_SNAKE);
}

Snake::~Snake()
{
    for (SnakeNode* p = head; p != nullptr; ) {
        SnakeNode* tmp = p->next;
        delete p;
        p = tmp;
    }
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

    Position newPosition = head->position.move(direction);
    if (!checkPosition(newPosition)) {
        playGround->setGameStatus(GAME_LOST);
        return;
    }

    CellType type = playGround->getCellState(newPosition);

    changePlayGroundState(CELL_EMPTY);
    if (cherry > 0) {
        cherry--;
        head = new SnakeNode(newPosition, head);
    } else {
        for (SnakeNode* p = head; p != nullptr; p = p->next) {
            std::swap(p->position, newPosition);
        }
    }
    changePlayGroundState(CELL_SNAKE);

    if (type == CELL_CHERRY) {
        cherry++;
        playGround->addCherry();
        playGround->addScore(1);
    }
}

void Snake::changePlayGroundState(CellType type)
{
    for (SnakeNode* p = head; p != nullptr; p = p->next) {
        playGround->changeCellState(p->position, type);
    }
}

bool Snake::checkPosition(Position pos)
{
    if ( !pos.isInsideBox(0,0,playGround->getWidth(),playGround->getHeight()) )
        return false;

    for (SnakeNode* p = head; p->next != nullptr; p = p->next)
        if (p->position == pos) return false;

    return true;
}
