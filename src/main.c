#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>

#define RENDER_ENTITIES(entities, entities_count)                              \
  for (int i = 0; i < entities_count; i++) {                                   \
    entities[i].render(renderer);                                              \
  }

#define UPDATE_ENTITIES(entities, entities_count, delta_time)                  \
  for (int i = 0; i < entities_count; i++) {                                   \
    entities[i].update(delta_time);                                            \
  }

#define QUIT_ENTITIES(entities, entities_count)                                \
  for (int i = 0; i < entities_count; i++) {                                   \
    entities[i].cleanup();                                                     \
  }

#define HANDLE_EVENT_ENTITIES(entities, entities_count, event)                 \
  for (int i = 0; i < entities_count; i++) {                                   \
    entities[i].handle_event(event);                                           \
  }

SDL_Window *window;
SDL_Renderer *renderer;

Uint32 last_tick = 0;
Uint32 current_tick = 0;
float delta_time;