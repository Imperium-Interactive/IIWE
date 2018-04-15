#include "Game.h"

SDL_Texture* playerTex;
SDL_Rect srcR, destR;

int posY = 0, posX = 0;

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        setFlag(fs,fullscreen);

        std::cout << "SDL successfully initialized!" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, xflags);
        if(window){
            std::cout << "Windows successfully created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer successfully created!" << std::endl;
        }

        isRunning = true;
    } else {
        isRunning = false;
    }

    SDL_Surface* tmpSurface = IMG_Load("../assets/Dwarf.jpg");
    playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

}

void Game::handleEvents() {

    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
    }
}

void Game::update() {

    destR.h = 128;
    destR.w = 128;
    if (posX < 672 && posY == 0){
        posX++;
    } else if (posX == 672 && posY < 472) {
        posY++;
    } else if (posX > 0 && posY == 472) {
        posX--;
    } else {
        posY--;
    }

    std::cout << posX << std::endl;
    std::cout << posY << std::endl;

    destR.x = posX;
    destR.y = posY;
   // std::cout << cnt << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, playerTex, NULL, &destR);
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game shutdown" << std::endl;
}

bool Game::running() {
    return isRunning;
}

void Game::setFlag(Flag flag, bool value) {
    switch(flag){
        case fs: if(value) xflags = SDL_WINDOW_FULLSCREEN;
    }
}