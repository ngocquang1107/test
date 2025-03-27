#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"
#include "player.h"

using namespace std;

int main(int argc, char *argv[])
{
    Graphics graphics;
    Player player;
    graphics.init();

    SDL_Texture* background = graphics.loadTexture("image/bikiniBottom.jpg");

    SDL_Rect rect = {500, 500, 50, 50}; // Rectangle position and size

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                player.handleKeyPress(e, rect);
            }
        }
        graphics.prepareScene(background);

        // Render rectangle
        SDL_SetRenderDrawColor(graphics.renderer, 255, 0, 0, 255); // Red color
        SDL_RenderFillRect(graphics.renderer, &rect);

        graphics.presentScene();
        SDL_Delay(1); // Delay to control the speed of movement
    }
    SDL_DestroyTexture(background);
    background = NULL;
    graphics.quit();
    return 0;
}
