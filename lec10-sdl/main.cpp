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
void drawMandelbrot(Painter& painter, float xmin = -2, float ymin = -1.5, float xmax = 2, float ymax = 1.5);

int main(int argc, char* argv[])
{
    srand(time(0));
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture = NULL;
    initSDL(window, renderer);

    Painter painter(window, renderer);
    int figNumber = argc > 1 ? atoi(argv[1]) : 17;
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
    case 16:
        {
            if (argc <= 2) {
                cout << "Please provide image file path" << endl;
                break;
            }
            texture = painter.loadTexture(argv[2]);
            painter.clearWithBgColor(WHITE_COLOR);
            painter.createImage(texture);
        }
        break;
    case 17:
        drawMandelbrot(painter);
        break;
    }

    SDL_RenderPresent(renderer);
	waitUntilKeyPressed();
	SDL_DestroyTexture(texture);
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

const SDL_Color PALLETTE[] = {
    SDL_Color({66, 30, 15}),
    SDL_Color({25, 7, 26}),
    SDL_Color({9, 1, 47}),
    SDL_Color({4, 4, 73}),
    SDL_Color({0, 7, 100}),
    SDL_Color({12, 44, 138}),
    SDL_Color({24, 82, 177}),
    SDL_Color({57, 125, 209}),
    SDL_Color({134, 181, 229}),
    SDL_Color({211, 236, 248}),
    SDL_Color({241, 233, 191}),
    SDL_Color({248, 201, 95}),
    SDL_Color({255, 170, 0}),
    SDL_Color({204, 128, 0}),
    SDL_Color({153, 87, 0}),
    SDL_Color({106, 52, 3})
};
const int PALETTE_COUNT = sizeof(PALLETTE) / sizeof(SDL_Color);

void drawMandelbrot(Painter& painter, float xmin, float ymin, float xmax, float ymax)
{
    int width = painter.getWidth(), height = painter.getHeight();
    const int MAX_ITERATION = 1000;
    for (int px = 0; px < width; px++) {
        for (int py = 0; py < painter.getHeight(); py++) {
            float x0 = (float)px / width * (xmax-xmin) + xmin, x = 0;
            float y0 = (float)py / height * (ymax-ymin) + ymin, y = 0;
            int iteration = 0;
            while (x*x+y*y < 2 && iteration < MAX_ITERATION) {
                float xtemp = x*x-y*y+x0;
                y = 2*x*y+y0;
                x = xtemp;
                iteration++;
            }
            SDL_Color color = iteration < MAX_ITERATION ? PALLETTE[iteration % PALETTE_COUNT] : BLACK_COLOR;
            painter.setColor(color);
            SDL_RenderDrawPoint(painter.getRenderer(), px, py);
        }
    }
}
