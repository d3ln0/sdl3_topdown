#pragma once

#include "SDL3/SDL_render.h"
#include "SDL3_image/SDL_image.h"
#include "camera.h"
#include "entity.h"
#include <SDL3/SDL.h>

typedef struct {
  float x, y;
} Position;

typedef struct {
  float w, h;
} SpriteSize;

extern Position player_position;

void init_player(SDL_Renderer *renderer);