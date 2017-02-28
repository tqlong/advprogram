#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SDL2/SDL.h>

#include "painter.h"
#include "PlayGround.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Snake Game";

const int GROUND_WIDTH = 30;
const int GROUND_HEIGHT = 20;

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
    renderGamePlay(painter, playGround);
    while (playGround.isGameRunning()) {
        if (SDL_WaitEvent(&e) != 0) {
            UserInput input = interpretEvent(e);
            playGround.processUserInput(input);
        }
        playGround.nextStep();
        renderGamePlay(painter, playGround);
        SDL_Delay(100);
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

}

void renderGamePlay(Painter&, const PlayGround& playGround)
{

}

void renderGameOver(Painter&, const PlayGround& playGround)
{

}

UserInput interpretEvent(SDL_Event e)
{
    return NO_INPUT;
}

void updateRankingTable(const PlayGround& playGround)
{

}
