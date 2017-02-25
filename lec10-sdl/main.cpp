#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SDL2/SDL.h>

#include "painter.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "An Implementation of Code.org Painter";

void logSDLError(std::ostream& os, const std::string &msg, bool fatal = false);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();

void randomWalk(Painter& painter);

int main(int argc, char* argv[])
{
    srand(time(0));
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);

    Painter painter(window, renderer);
    int figNumber = argc > 1 ? atoi(argv[1]) : 3;
    switch (figNumber)
    {
    /* Square */
    case 0:
        painter.setColor(WHITE_COLOR);
        for (int i = 0; i < 4; ++i)
        {
            painter.moveForward(100);
            painter.turnRight(90);
        }
        break;
    //*/

    /* Triangle */
    //*
    case 1:
        painter.setColor(WHITE_COLOR);
        painter.clearWithBgColor(GREEN_COLOR);
        for (int i = 0; i < 3; ++i)
        {
            painter.turnLeft(120);
            painter.moveForward(100);
        }
        break;
    //*/

    /* Filled Triangle */
    //*
    case 2:
    {
        float curX = painter.getX();
        float curY = painter.getY();
        painter.setColor(WHITE_COLOR);
        painter.turnLeft(60);
        float size = 150;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                painter.turnLeft(120);
                painter.moveForward(size - i);
            }
            painter.setPosition(curX, curY);
            painter.jumpBackward(i+1);
        }
        painter.setPosition(curX, curY);
        break;
    }
    //*/


    /* Octagon */
    //*
    case 3:
        painter.setPosition(350, 500);
        painter.setColor(YELLOW_COLOR);
        for (int i = 0; i < 8; ++i)
        {
            painter.moveForward(150);
            painter.turnLeft(45);
        }
        break;
    //*/

    /* Star of fives */
    //*
    case 4:
        painter.setPosition(350, 200);
        painter.setColor(YELLOW_COLOR);
        for (int i = 0; i < 5; ++i)
        {
            painter.moveForward(200);
            painter.turnRight(144);
        }
        break;
    //*/

    /* Star of David */
    //*
    case 5:
        painter.setPosition(350, 400);
        painter.setColor(YELLOW_COLOR);
        painter.turnLeft(60);
        for (int i = 0; i < 3; ++i)
        {
            painter.moveForward(150);
            painter.turnLeft(120);
        }
        painter.turnLeft(30);
        painter.jumpForward((int) (150 * 2 / 1.73205080757)); // sqrt(3) = 1.73205080757
        painter.turnLeft(150);
        for (int i = 0; i < 3; ++i)
        {
            painter.moveForward(150);
            painter.turnLeft(120);
        }
        break;
    //*/

    /* Eight lines crossing at center*/
    //*
    case 6:
        painter.setColor(WHITE_COLOR);
        for (int i = 0; i < 8; ++i)
        {
            painter.moveForward(100);
            painter.moveBackward(100);
            painter.turnLeft(45);
        }
        break;
    //*/

    /* Six squares */
    //*
    case 7:
        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                painter.moveForward(100);
                painter.turnRight(90);
            }
            painter.turnLeft(60);
        }
        break;
    //*/

    /* Circles in line */
    //*
    case 8:
        painter.clearWithBgColor(GREEN_COLOR);
        painter.setColor(RED_COLOR);
        painter.setPosition(150, 150);
        for (int i = 0; i < 10; ++i)
        {
            painter.createCircle(100);
            painter.jumpForward(30);
        }
        break;
    //*/

    /* Circles in circle */
    //*
    case 9:
        painter.setPosition(350, 150);
        painter.clearWithBgColor(BLACK_COLOR);
        for (int i = 0; i < 20; ++i)
        {
            painter.setRandomColor();
            painter.createCircle(100);
            painter.jumpForward(1);
            painter.createCircle(100);
            painter.jumpForward(50);
            painter.turnRight(18);
        }
        break;
    //*/

    /*	Ten squares in circle */
    //*
    case 10:
        painter.setColor(WHITE_COLOR);
        for (int i = 0; i < 10; ++i)
        {
            //painter.randomColor();
            painter.createSquare(100);
            painter.turnRight(36);
        }
        break;
    //*/

    /* Multitude lines in cicles */
    //*
    case 11:
        for (int i = 0; i < 90; ++i)
        {
            painter.setRandomColor();
            painter.moveForward(150);
            painter.jumpBackward(150);
            painter.turnRight(4);
        }
        break;
    //*/

    /* Pattern of Ten parallelograms */
    //*
    case 12:
        painter.setColor(WHITE_COLOR);
        for (int i = 0; i < 10; ++i)
        {
            painter.createParallelogram(100);
            painter.turnRight(36);
        }
        break;
    //*/

    /* Five and five cirles */
    //*
    case 13:
        painter.setColor(WHITE_COLOR);
        painter.clearWithBgColor(GREEN_COLOR);
        for (int i = 0; i < 5; ++i)
        {
            painter.createCircle(100);
            painter.createCircle(50);
            painter.turnRight(72);
        }
        break;
    //*/

    /* Snow flake*/
    //*
    case 14:
    {
        painter.setColor(WHITE_COLOR);
        painter.turnLeft(20);
        for (int i = 0; i < 8; ++i)
        {
            int size = 40;
            painter.moveForward(size);
            for (int j = 0; j < 3; ++j)
            {
                painter.turnLeft(45);
                painter.moveForward(size);
                painter.jumpBackward(size);
                painter.turnRight(90);
                painter.moveForward(size);
                painter.jumpBackward(size);
                painter.turnLeft(45);
                painter.moveForward(size);
            }
            painter.jumpBackward(4*size);
            painter.turnRight(45);
        }
        break;
    }

    /* Random walk*/
    //*
    case 15:
        randomWalk(painter);
        break;
    }

    SDL_RenderPresent(renderer);
	waitUntilKeyPressed();
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

void randomWalk(Painter& painter)
{
    const int STEPS = 10;
    const float MAX_LENGTH = 100;
    for (int i = 0; i < STEPS; i++) {
        painter.setRandomColor();
        float length = generateRandomNumber() * MAX_LENGTH;
        painter.moveForward(length);
        float angle = generateRandomNumber() * 360;
        painter.turnLeft(angle);
    }
}
