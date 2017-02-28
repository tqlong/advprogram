#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>
#include <SDL2/SDL.h>

#include "painter.h"
#include "PlayGround.h"

using namespace std;

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Snake Game";

const int GROUND_WIDTH = 30;
const int GROUND_HEIGHT = 20;
const int CELL_SIZE = 30;

const double STEP_DELAY = 0.5;
#define CLOCK_NOW chrono::system_clock::now
typedef chrono::duration<double> ElapsedTime;

void logSDLError(std::ostream& os, const std::string &msg, bool fatal = false);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();

void renderSplashScreen();
void renderGamePlay(Painter&, const PlayGround& playGround);
void renderGameOver(Painter&, const PlayGround& playGround);
UserInput interpretEvent(SDL_Event e);
void updateRankingTable(const PlayGround& playGround);

int main(int argc, char* argv[])
{
    srand(time(0));
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    Painter painter(window, renderer);

    renderSplashScreen();
    PlayGround playGround(GROUND_WIDTH, GROUND_HEIGHT);

    SDL_Event e;
    auto start = CLOCK_NOW();
    renderGamePlay(painter, playGround);
    while (playGround.isGameRunning()) {
        while (SDL_PollEvent(&e)) {
            UserInput input = interpretEvent(e);
            playGround.processUserInput(input);
        }

        auto end = CLOCK_NOW();
        ElapsedTime elapsed = end-start;
        if (elapsed.count() > STEP_DELAY) {
            playGround.nextStep();
            renderGamePlay(painter, playGround);
            start = end;
        }
        SDL_Delay(1);
    }
    renderGameOver(painter, playGround);
    updateRankingTable(playGround);

    quitSDL(window, renderer);
    return 0;
}

void logSDLError(std::ostream& os, const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (window == nullptr)
        logSDLError(std::cout, "CreateWindow", true);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    //SDL_Renderer *renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == nullptr)
        logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

float generateRandomNumber()
{
    return (float) rand() / RAND_MAX;
}

void renderSplashScreen()
{
    waitUntilKeyPressed();
}

void renderGamePlay(Painter& painter, const PlayGround& playGround)
{
    int top = 0, left = 0;
    int width = playGround.getWidth();
    int height = playGround.getHeight();
    painter.clearWithBgColor(PURPLE_COLOR);

    painter.setColor(WHITE_COLOR);
    for (int i = 0; i <= width; i++) {
        painter.setAngle(-90);
        painter.setPosition(left+i * CELL_SIZE, top+0);
        painter.moveForward(height * CELL_SIZE);
    }

    for (int i = 0; i <= height; i++) {
        painter.setAngle(0);
        painter.setPosition(left+0, top+i * CELL_SIZE);
        painter.moveForward(width * CELL_SIZE);
    }

    const vector<vector<CellType> >& squares = playGround.getSquares();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (squares[i][j] == CELL_CHERRY) {
                painter.setColor(ORANGE_COLOR);
                painter.setAngle(-90);
                painter.setPosition(left+j*CELL_SIZE+5, top+i*CELL_SIZE+5);
                painter.createSquare(CELL_SIZE-10);
            } else if (squares[i][j] == CELL_SNAKE) {
                painter.setColor(RED_COLOR);
                painter.setAngle(0);
                painter.setPosition(left+j*CELL_SIZE+5, top+i*CELL_SIZE+CELL_SIZE/2);
                painter.createCircle(CELL_SIZE/2-5);
            }
        }
    }

    SDL_RenderPresent(painter.getRenderer());
}

void renderGameOver(Painter&, const PlayGround& playGround)
{

}

UserInput interpretEvent(SDL_Event e)
{
    if (e.type == SDL_KEYUP) {
        switch (e.key.keysym.sym) {
        case SDLK_UP: return KEY_UP;
        case SDLK_DOWN: return KEY_DOWN;
        case SDLK_LEFT: return KEY_LEFT;
        case SDLK_RIGHT: return KEY_RIGHT;
        }
    }
    return NO_INPUT;
}

void updateRankingTable(const PlayGround& playGround)
{

}
