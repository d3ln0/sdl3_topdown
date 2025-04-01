#pragma once
#include <SDL3/SDL.h>
#define MAX_ENTITIES 100

#define GENERIC_ENTITY                                                         \
  { cleanup, handle_event, update, render }

typedef struct {
  void (*cleanup)(void);
  void (*handle_event)(SDL_Event *);
  void (*update)(float);
  void (*render)(SDL_Renderer *);
} Entity;

extern Entity entities[MAX_ENTITIES];
extern int entities_count;