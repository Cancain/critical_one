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
    SDL_Renderer *getRenderer();
    SDL_Surface *getSurface();

   private:
    SDL_Window *_window = NULL;
    SDL_Surface *_windowSurface = NULL;
    SDL_Renderer *_renderer = NULL;
};

#endif