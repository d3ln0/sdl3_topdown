#pragma once
#include <SDL3/SDL.h>
#define MAX_ENTITIES 100

#define GENERIC_ENTITY                                                         \
  { cleanup, handle_event, update, render }

#define ENTITIES_RUN_OPTIONAL(function, ...)                                   \
  for (int i = 0; i < entities_count; i++) {                                   \
    if (entities[i].function) {                                                \
      entities[i].function(__VA_ARGS__);                                       \
    }                                                                          \
  }

typedef struct {
  void (*cleanup)(void);
  void (*handle_event)(SDL_Event *);
  void (*update)(float);
  void (*render)(SDL_Renderer *);
} Entity;

extern Entity entities[MAX_ENTITIES];
extern int entities_count;

void swap_entities(int index1, int index2);
void delete_entity(int index);
void create_entity(Entity entity);