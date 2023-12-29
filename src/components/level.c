#pragma once

#include <stdlib.h>

#include "../utils/array.c"
#include "../utils/panic.c"
#include "../utils/string.c"
#include "./camera.c"
#include "./player.c"

/**
 * Represents a world.
 */
struct Level {
    const char *NAME;

    struct Array *tiles;
    struct Camera *camera;
    struct Player *player;
};

#define LEVEL_STRUCT_SIZE sizeof(struct Level)

struct Level *level_new(const char *NAME) {
    struct Level *self = malloc(LEVEL_STRUCT_SIZE);

    if (!self) {
        panic("failed to malloc Level struct");
    }

    self->NAME = NAME;

    self->tiles = array_new();
    self->camera = camera_new();
    self->player = player_new();

    return self;
}
