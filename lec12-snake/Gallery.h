#ifndef GALLERY_H
#define GALLERY_H

#include <vector>
#include <SDL2/SDL.h>
#include "painter.h"

enum PictureID {
    PIC_CHERRY = 0, PIC_SNAKE_VERTICAL,
    PIC_SNAKE_HORIZONTAL, PIC_SNAKE_HEAD,
};

class Gallery
{
    std::vector<SDL_Texture*> pictures;
    Painter& painter;
public:
    Gallery(Painter& painter_);
    ~Gallery();

    void loadGamePictures();
    SDL_Texture* getImage(PictureID id) const { return pictures[id]; }
};

#endif // GALLERY_H
