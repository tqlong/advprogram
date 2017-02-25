#include <cmath>
#include <cstdlib>

#include "painter.h"

Painter::Painter(SDL_Window* window, SDL_Renderer* renderer_)
    : renderer(renderer_)
{
    SDL_RenderGetLogicalSize(renderer, &width, &height);
    if (width == 0 && height == 0)
        SDL_GetWindowSize(window, &width, &height);

    setPosition(width/2, height/2);
    setAngle(0);
    setColor(WHITE_COLOR);
    clearWithBgColor(BLUE_COLOR);
}

void Painter::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Painter::setAngle(float angle)
{
    this->angle = angle - floor(angle/360)*360;
}

void Painter::setColor(SDL_Color color)
{
    this->color = color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 0);
}

void Painter::clearWithBgColor(SDL_Color bgColor)
{
    SDL_Color curColor = color;
    setColor(bgColor);
    SDL_RenderClear(renderer);
    setColor(curColor);
}

void Painter::moveForward(float length)
{
    float prevX = x, prevY = y;
    jumpForward(length);
    SDL_RenderDrawLine(renderer, (int)prevX, (int)prevY, (int)x, (int)y);
}

void Painter::jumpForward(float length)
{
    float rad = (angle / 180) * M_PI;
    x += (cos(rad) * length);
    y -= (sin(rad) * length);
}

void Painter::setRandomColor()
{
    Uint8 r = rand() % 256;
    Uint8 g = rand() % 256;
    Uint8 b = rand() % 256;
    setColor((SDL_Color) { r, g, b });
}

void Painter::createCircle(float radius)
{
    double rad = (angle / 180) * M_PI;
    int centerX = x + cos(rad) * radius;
    int centerY = y - sin(rad) * radius;

    int dx = radius;
    int dy = 0;
    int err = 0;

    while (dx >= dy)
    {
        SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
        SDL_RenderDrawPoint(renderer, centerX + dy, centerY + dx);
        SDL_RenderDrawPoint(renderer, centerX - dy, centerY + dx);
        SDL_RenderDrawPoint(renderer, centerX - dx, centerY + dy);
        SDL_RenderDrawPoint(renderer, centerX - dx, centerY - dy);
        SDL_RenderDrawPoint(renderer, centerX - dy, centerY - dx);
        SDL_RenderDrawPoint(renderer, centerX + dy, centerY - dx);
        SDL_RenderDrawPoint(renderer, centerX + dx, centerY - dy);

        if (err <= 0)
        {
            dy += 1;
            err += 2*dy + 1;
        }
        if (err > 0)
        {
            dx -= 1;
            err -= 2*dx + 1;
        }
    }
}

void Painter::createSquare(float size)
{
    for (int i = 0; i < 4; ++i) {
        moveForward(size);
        turnLeft(90);
    }
}

void Painter::createParallelogram(float size)
{
    for (int i = 0; i < 2; ++i) {
        moveForward(size);
        turnLeft(60);
        moveForward(size);
        turnLeft(120);
    }
}
