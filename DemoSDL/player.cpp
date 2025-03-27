#include "player.h"
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
using namespace std;

void Player::handleKeyPress(SDL_Event &e, SDL_Rect &rect) {
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_A]) {
        rect.x -= 10;
        if (rect.x < 0) rect.x = 0;
    } else if (state[SDL_SCANCODE_D]) {
        rect.x += 10;
        if (rect.x + rect.w > 800) rect.x = 800 - rect.w;
    }
}
