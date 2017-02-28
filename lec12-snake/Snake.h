#ifndef SNAKE_H
#define SNAKE_H

#include <queue>

#include "Position.h"

class PlayGround;

enum UserInput {
    NO_INPUT = 0, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

class Snake
{
    Position position;
    PlayGround* playGround;
    Direction direction;
    std::queue<UserInput> inputQueue;
public:
    Snake(PlayGround* playGround);
    ~Snake();

    void processUserInput(UserInput input);
    void nextStep();
private:
    Direction changeDirection(UserInput input);
};

#endif // SNAKE_H
