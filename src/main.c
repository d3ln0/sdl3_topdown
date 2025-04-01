#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;

Uint32 last_tick = 0;
Uint32 current_tick = 0;
float delta_time;