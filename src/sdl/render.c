#include "render.h"

void app_render(void *appstate) {
  AppState *state = (AppState *)appstate;

  SDL_RenderClear(state->renderer);
  SDL_SetRenderDrawColor(state->renderer, 0, 255, 0, 255);

  ENTITIES_RUN_OPTIONAL(render, state->renderer)

  SDL_RenderPresent(state->renderer);
}