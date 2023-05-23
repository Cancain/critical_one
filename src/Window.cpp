#include "Window.h"

Window::Window() { printf("Window constructor"); }

void Window::start() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
  } else {
    window = SDL_CreateWindow("Critical one", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, window_width,
                              window_height, SDL_WINDOW_SHOWN);
    if (window == NULL) {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    } else {
      windowSurface = SDL_GetWindowSurface(window);

      SDL_FillRect(windowSurface, NULL,
                   SDL_MapRGB(windowSurface->format, 0xFF, 0xFF, 0xFF));

      SDL_UpdateWindowSurface(window);
    }
  }
};

void Window::end() {
  SDL_DestroyWindow(window);
  SDL_Quit();
};