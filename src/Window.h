#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window {
public:
  Window();
  void start();
  void end();

private:
  int window_width = 800;
  int window_height = 600;
  SDL_Window *window = NULL;
  SDL_Surface *windowSurface = NULL;
};

#endif