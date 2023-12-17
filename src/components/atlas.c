#pragma once

#include "raylib.h"

#include "../utils/panic.c"

struct Atlas {
    Texture2D texture;
};

#define ATLAS_STRUCT_SIZE sizeof(struct Atlas)

/**
 * Creates a new Atlas struct.
 *
 * @param texturePath The path to the texture.
 *
 * @return The created Atlas struct.
 */
struct Atlas *atlas_new(char *texturePath) {
    struct Atlas *self = malloc(ATLAS_STRUCT_SIZE);

    if (!self) {
        panic("failed to malloc Atlas struct");
    }

    self->texture = LoadTexture(texturePath);

    return self;
}
