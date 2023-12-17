#pragma once

#include <stdlib.h>

#include "../utils/panic.c"
#include "./camera.c"
#include "./player.c"

/**
 * Represents a world.
 */
struct World {
    struct Array *tiles;
    struct Camera *camera;
    struct Player *player;
};

#define WORLD_STRUCT_SIZE sizeof(struct World)
