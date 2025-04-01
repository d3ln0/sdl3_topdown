#include "player.h"
#include "SDL3/SDL_keyboard.h"
#include "SDL3/SDL_scancode.h"

static SDL_FRect sprite_portion = {17, 14, 15, 18};
static SDL_Texture *player_texture;

typedef struct {
  float x, y;
} Position;

Position position = {0, 0};

static void quit() {}

static void handle_event() {}

static void update(float delta_time) {
  const _Bool *keyboard_state = SDL_GetKeyboardState(NULL);

  if (keyboard_state[SDL_SCANCODE_W]) {
    position.y -= 30 * delta_time;
  }
  if (keyboard_state[SDL_SCANCODE_S]) {
    position.y += 30 * delta_time;
  }
  if (keyboard_state[SDL_SCANCODE_D]) {
    position.x += 30 * delta_time;
  }
  if (keyboard_state[SDL_SCANCODE_A]) {
    position.x -= 30 * delta_time;
  }
}

static void render(SDL_Renderer *renderer) {
  SDL_FRect player_position = {position.x, position.y, 15, 18};
  SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_LINEAR);
  SDL_RenderTexture(renderer, player_texture, &sprite_portion,
                    &player_position);
}

Entity init_player(SDL_Renderer *sdl_renderer) {
  const char path[] = "./assets/Top_Down_Adventure_Pack_v.1.0/Char_Sprites/"
                      "char_spritesheet.png";
  player_texture = IMG_LoadTexture(sdl_renderer, path);

  Entity player = GENERIC_ENTITY;

  return player;
}