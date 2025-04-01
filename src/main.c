#include "SDL3/SDL_events.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_oldnames.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_surface.h"
#include "SDL3/SDL_video.h"
#include "SDL3_image/SDL_image.h"
#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *player_texture;

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    if(event->type == SDL_EVENT_QUIT){
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

void update(){

}

void render() {
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    SDL_FRect sprite_portion = {17, 14, 15, 18};
    SDL_FRect player_position = {250, 250, 15, 18};
    SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_LINEAR);
    SDL_RenderTexture(renderer, player_texture, &sprite_portion, &player_position);

    SDL_RenderPresent(renderer);
}

SDL_AppResult SDL_AppIterate(void *appstate){
    render();
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("Error Initializing SDL: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  window = SDL_CreateWindow("SDL3 Game", 800, 600, 0);
  if (!window) {
    SDL_Log("Error creating window: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  renderer = SDL_CreateRenderer(window, NULL);
  if (!renderer) {
    SDL_Log("Error creating window: %s", SDL_GetError());
  }

  const char path[] = "./assets/Top_Down_Adventure_Pack_v.1.0/Char_Sprites/char_spritesheet.png";
  player_texture = IMG_LoadTexture(renderer, path);

  return SDL_APP_CONTINUE;
}