#ifndef SNAKE_H
#define SNAKE_H

#include <queue>

#include "Position.h"

class PlayGround;

enum UserInput {
    NO_INPUT = 0, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

enum CellType {
    CELL_EMPTY = 0, CELL_SNAKE, CELL_CHERRY
};

struct SnakeNode
{
    Position position;
    SnakeNode* next;

    SnakeNode(Position p, SnakeNode* n = nullptr) : position(p), next(n) {}

    static SnakeNode* insertHead(SnakeNode* head, Position p)
    {
        SnakeNode* newHead = new SnakeNode(p, head);
        return newHead;
    }
};

class Snake
{
    SnakeNode* head;
    PlayGround* playGround;
    Direction direction;
    std::queue<UserInput> inputQueue;

    int cherry;
public:
    Snake(PlayGround* playGround);
    ~Snake();

    void processUserInput(UserInput input);
    void nextStep();
    bool checkPosition(Position pos);
    SnakeNode* getHead() const { return head; }
private:
    Direction changeDirection(UserInput input);
    void changePlayGroundState(CellType type);
};

#endif // SNAKE_H
