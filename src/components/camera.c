#pragma once

#include <stdlib.h>

#include "raylib.h"

#include "../utils/panic.c"

/**
 * Represents a camera.
 */
struct Camera {
    Camera2D camera;
};

#define CAMERA_STRUCT_SIZE sizeof(struct Camera)

/**
 * Creates a new Camera struct.
 *
 * @param target The target of the camera.
 * @param rotation The rotation of the camera.
 * @param zoom The zoom of the camera.
 *
 * @return The created Camera struct.
 */
struct Camera *camera_new(Vector2 target, float rotation, float zoom) {
    struct Camera *self = malloc(CAMERA_STRUCT_SIZE);

    if (!self) {
        panic("failed to malloc Camera struct");
    }

    self->camera.target = target;
    self->camera.offset = (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    self->camera.rotation = rotation;
    self->camera.zoom = zoom;

    return self;
}