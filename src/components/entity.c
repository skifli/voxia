#pragma once

#include <stdlib.h>

#include "raylib.h"

#include "../utils/panic.c"
#include "./atlas.c"

/**
 * Represents an entity.
 */
struct Entity {
    bool canJump;        // Used to prevent double jumping, etc.
    float speed;         // The speed of the entity.
    struct Atlas *atlas; // The atlas of the entity.
    Vector2 position;    // The position of the entity.
};

#define ENTITY_STRUCT_SIZE sizeof(struct Entity)

/**
 * Creates a new Entity struct.
 *
 * @param position The position of the entity.
 * @param velocity The velocity of the entity.
 *
 * @return The created Entity struct.
 */
struct Entity *entity_new(Vector2 position, float speed, char *texturePath) {
    struct Entity *self = malloc(ENTITY_STRUCT_SIZE);

    if (!self) {
        panic("failed to malloc Entity struct");
    }

    self->atlas = atlas_new(texturePath);

    self->canJump = false;
    self->position = position;
    self->speed = speed;

    return self;
}
