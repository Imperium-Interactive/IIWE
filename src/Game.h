#ifndef DWARFGINE_GAME_H
#define DWARFGINE_GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

enum Flag {fs};

class Game {
public:
    Game();
    ~Game();

    /** Initializes game
     *
     * @param title title of the window
     * @param xpos x position of the window
     * @param ypos y position of the window
     * @param width width of the window
     * @param height height of the window
     * @param fullscreen fullscreen enabled if true, disabled if false
     */
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();
    bool running();

    void setFlag(Flag flag, bool value);
private:
    int cnt = 0;
    bool isRunning;
    int xflags;
    SDL_Window *window;
    SDL_Renderer *renderer;
};


#endif //DWARFGINE_GAME_H
