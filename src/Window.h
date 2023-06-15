#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Window {
   public:
    Window();
    void start();
    void end();
    void printText(char *text);
    void clearWindow();
    void renderButton();
    void update();

   private:
    SDL_Window *window = NULL;
    SDL_Surface *windowSurface = NULL;
    SDL_Renderer *renderer = NULL;
};

#endif