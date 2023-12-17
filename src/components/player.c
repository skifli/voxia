#pragma once

#include <stdlib.h>

#include "raylib.h"

#include "../utils/panic.c"
#include "./entity.c"

int gravity = 400;
float playerJumpSpeed = 350.0f; // Vertical speed (y-axis)
float playerHORSpeed = 200.0f;  // Horizontal speed (x-axis)

/**
 * Represents a player.
 */
struct Player {
    struct Entity *entity;
};

#define PLAYER_STRUCT_SIZE sizeof(struct Player)

/**
 * Creates a new Player struct.
 *
 * @param position The position of the player.
 * @param velocity The velocity of the player.
 *
 * @return The created Player struct.
 */
struct Player *player_new(Vector2 position, float velocity, char *texturePath) {
    struct Player *self = malloc(PLAYER_STRUCT_SIZE);

    if (!self) {
        panic("failed to malloc Player struct");
    }

    self->entity = entity_new(position, velocity, texturePath);

    return self;
}

/**
 * Updates the player.
 *
 * @param player The player to update.
 * @param deltaTime The time since the last frame.
 */
void player_update(struct Player *self, float deltaTime) {
    if (IsKeyDown(KEY_LEFT)) { // move left
        self->entity->position.x -= playerHORSpeed * deltaTime;
    }

    if (IsKeyDown(KEY_RIGHT)) { // move right
        self->entity->position.x += playerHORSpeed * deltaTime;
    }

    if (IsKeyPressed(KEY_SPACE) * self->entity->canJump) { // jump
        self->entity->speed = -playerJumpSpeed;
        self->entity->canJump = false;
    }
}