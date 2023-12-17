#pragma once

#include <dirent.h>

#include "../components/world.c"
#include "../utils/array.c"
#include "../utils/panic.c"

/**
 * Represents a collection of worlds.
 */
struct Worlds {
    struct Array *worlds;     // The worlds
    struct Array *worldNames; // Names of the worlds
};

#define WORLDS_STRUCT_SIZE sizeof(struct Worlds)

/**
 * Creates a new Worlds struct.
 *
 * @param worldsDirPath The path to the worlds directory.
 *
 * @return The created Worlds struct.
 */
struct Worlds *worlds_new(char *worldsDirPath) {
    struct Worlds *self = malloc(WORLDS_STRUCT_SIZE);

    if (!self) {
        panic("failed to malloc Worlds struct");
    }

    self->worlds = array_new();
    self->worldNames = array_new();

    DIR *worldsDir = opendir(worldsDirPath);

    if (!worldsDir) {
        panic("failed to open worlds directory");
    }

    struct dirent *entry;

    while ((entry = readdir(worldsDir)) != NULL) {
    }

    closedir(worldsDir);

    return self;
}