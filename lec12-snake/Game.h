#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Position.h"

enum GameStatus {
    GAME_RUNNING = 1,
    GAME_STOP = 2,
    GAME_WON = 4 | GAME_STOP,
    GAME_OVER = 8 | GAME_STOP,
};

enum CellType {
    CELL_EMPTY = 0, CELL_SNAKE, CELL_CHERRY, CELL_OFF_BOARD
};

class Game
{
    std::vector< std::vector<CellType> > squares;
    Snake snake;
    GameStatus status;
    int score;
    std::queue<Direction> inputQueue;
    Direction currentDirection;
    Position cherryPosition;
public:
	const int width;
	const int height;
	
    Game(int _width, int _height);
    ~Game();

    bool isGameRunning() const { return status == GAME_RUNNING; }
    bool isGameOver() const { return status == GAME_OVER; }
    void processUserInput(Direction direction);
    void nextStep();
    const std::vector< std::vector<CellType> >& getSquares() const { return squares; }
    CellType getCellType(Position p) const;
    void setGameStatus(GameStatus status);

    std::vector<Position> getSnakePositions() const;
    Position getCherryPosition() const { return cherryPosition; }
    int getScore() const { return score; }
    bool canChange(Direction current, Direction next) const;    
    
    void snakeMoveTo(Position position);
    void snakeLeave(Position position);
private:
	void addCherry();  
	void setCellType(Position pos, CellType cellType);
};

#endif // GAMEGROUND_H
