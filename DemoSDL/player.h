#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"

using namespace std;

class Player : public Graphics{
public:
    void handleKeyPress(SDL_Event &e, SDL_Rect &rect);
};

#endif // PLAYER_H
