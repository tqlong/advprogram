#ifndef GAMEGROUND_H
#define GAMEGROUND_H

#include <vector>
#include "snake.h"

enum CellType {
    CELL_EMPTY = 0, CELL_SNAKE, CELL_CHERRY
};

enum UserInput {
    NO_INPUT = 0, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

enum GameStatus {
    GAME_RUNNING = 1,
    GAME_STOP = 2,
    GAME_WON = 4 | GAME_STOP,
    GAME_LOST = 8 | GAME_STOP,
};

struct Position
{
    int x;
    int y;
};

class PlayGround
{
    std::vector< std::vector<CellType> > squares;
    Snake snake;
    GameStatus status;
    int score;
public:
    PlayGround(int width, int height);
    ~PlayGround();

    bool isGameRunning() const { return status == GAME_RUNNING; }
    void processUserInput(UserInput input) { }
    void nextStep() { }
    void changeCellState(Position pos, CellType type);
    void addCherry() { }
};

#endif // GAMEGROUND_H
