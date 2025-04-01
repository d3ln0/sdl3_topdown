#include "init.h"
#include "SDL3/SDL_render.h"

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
  AppState *state = SDL_malloc(sizeof(AppState));
  *appstate = state;

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("Error Initializing SDL: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  state->window = SDL_CreateWindow("SDL3 Game", 1280, 720, 0);
  if (!state->window) {
    SDL_Log("Error creating window: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  state->renderer = SDL_CreateRenderer(state->window, NULL);
  if (!state->renderer) {
    SDL_Log("Error creating window: %s", SDL_GetError());
  }

  init_map(state->renderer);
  init_player(state->renderer);

  SDL_SetRenderLogicalPresentation(state->renderer, 320, 180,
                                   SDL_LOGICAL_PRESENTATION_LETTERBOX);

  return SDL_APP_CONTINUE;
}