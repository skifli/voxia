#pragma once

#include "./level.c"

struct World {
    const char *NAME;

    struct Array *levels;
};

#define WORLD_STRUCT_SIZE sizeof(struct World)

struct World *world_new(const char *NAME) {
    struct World *self = malloc(WORLD_STRUCT_SIZE);

    if (!self) {
        panic("failed to malloc World struct");
    }

    self->NAME = NAME;

    self->levels = array_new();

    return self;
}
