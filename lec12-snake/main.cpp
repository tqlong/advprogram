#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>

#include "SDL_utils.h"
#include "Game.h"
#include "Gallery.h"

using namespace std;

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 600;
const char WINDOW_TITLE[] = "Snake Game";

const int BOARD_WIDTH = 30;
const int BOARD_HEIGHT = 20;
const int CELL_SIZE = 30;

const SDL_Color BOARD_COLOR = {128, 0, 128};
const SDL_Color LINE_COLOR = {255, 255, 255};

const double STEP_DELAY = 0.2;
#define CLOCK_NOW chrono::system_clock::now
typedef chrono::duration<double> ElapsedTime;

void renderSplashScreen();
void renderGamePlay(SDL_Renderer*, const Game& game);
void renderGameOver(SDL_Renderer* renderer, const Game& game);
void interpretEvent(SDL_Event e, Game& game);
void updateRankingTable(const Game& game);

Gallery* gallery = nullptr; // global picture manager

int main(int argc, char* argv[])
{
    srand(time(0));
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    gallery = new Gallery(renderer);
    renderSplashScreen();
    Game game(BOARD_WIDTH, BOARD_HEIGHT);

    cout << "Play Ground initialized" << endl;
    SDL_Event e;
    auto start = CLOCK_NOW();
    
    renderGamePlay(renderer, game);
    while (game.isGameRunning()) {
        while (SDL_PollEvent(&e)) {
            interpretEvent(e, game);
        }

        auto end = CLOCK_NOW();
        ElapsedTime elapsed = end-start;
        if (elapsed.count() > STEP_DELAY) {
            game.nextStep();
            renderGamePlay(renderer, game);
            start = end;
        }
        SDL_Delay(1);
    }
    renderGameOver(renderer, game);
    updateRankingTable(game);

    delete gallery;
    quitSDL(window, renderer);
    return 0;
}

float generateRandomNumber()
{
    return (float) rand() / RAND_MAX;
}

void renderSplashScreen()
{
    cout << "Press any key to start game" << endl;
    waitUntilKeyPressed();
}

void drawCell(SDL_Renderer* renderer, int left, int top, Position pos, SDL_Texture* texture)
{
	SDL_Rect cell; 
	cell.x = left + pos.x * CELL_SIZE + 5;
	cell.y = top + pos.y * CELL_SIZE + 5;
	cell.w = CELL_SIZE-10;
	cell.h = CELL_SIZE-10;
	SDL_RenderCopy(renderer, texture, NULL, &cell);
}

void drawCherry(SDL_Renderer* renderer, int left, int top, Position pos)
{	
    drawCell(renderer, left, top, pos, gallery->getImage(PIC_CHERRY));
}

void drawSnake(SDL_Renderer* renderer, int left, int top, vector<Position> pos)
{
	// snake's head
	drawCell(renderer, left, top, pos[pos.size()-1], gallery->getImage(PIC_SNAKE_HEAD));
	
	// snake's body
    for (int i = pos.size() - 2; i >= 0; i--) {
        SDL_Texture* texture = gallery->getImage(
			pos[i].y == pos[i+1].y ? PIC_SNAKE_HORIZONTAL : PIC_SNAKE_VERTICAL);
        drawCell(renderer, left, top, pos[i], texture);
    }
}

void drawVerticalLine(SDL_Renderer* renderer, int left, int top, int cells)
{
    SDL_SetRenderDrawColor(renderer, LINE_COLOR.r, LINE_COLOR.g, LINE_COLOR.b, 0);
    SDL_RenderDrawLine(renderer, left, top, left, top + cells * CELL_SIZE);
}

void drawHorizontalLine(SDL_Renderer* renderer, int left, int top, int cells)
{
    SDL_SetRenderDrawColor(renderer, LINE_COLOR.r, LINE_COLOR.g, LINE_COLOR.b, 0);
    SDL_RenderDrawLine(renderer, left, top, left + cells * CELL_SIZE, top);
}

void renderGamePlay(SDL_Renderer* renderer, const Game& game)
{
    int top = 0, left = 0;
    SDL_SetRenderDrawColor(renderer, BOARD_COLOR.r, BOARD_COLOR.g, BOARD_COLOR.b, 0);
    SDL_RenderClear(renderer);

    for (int x = 0; x <= BOARD_WIDTH; x++)
        drawVerticalLine(renderer, left + x*CELL_SIZE, top, BOARD_HEIGHT);
    for (int y = 0; y <= BOARD_HEIGHT; y++)
        drawHorizontalLine(renderer, left, top+y * CELL_SIZE, BOARD_WIDTH);

    drawCherry(renderer, left, top, game.getCherryPosition());
    drawSnake(renderer, left, top, game.getSnakePositions());
    
    SDL_RenderPresent(renderer);
}

void renderGameOver(SDL_Renderer* renderer, const Game& game)
{

}

void interpretEvent(SDL_Event e, Game& game)
{
    if (e.type == SDL_KEYUP) {
        switch (e.key.keysym.sym) {
        	case SDLK_UP: game.processUserInput(UP); break;
        	case SDLK_DOWN: game.processUserInput(DOWN); break;
        	case SDLK_LEFT: game.processUserInput(LEFT); break;
        	case SDLK_RIGHT: game.processUserInput(RIGHT); break;
        }
    }
}

void updateRankingTable(const Game& game)
{

}
