#pragma once

#include "../components/world.c"
#include "../../includes/cJSON/cJSON.h"

struct World *parse_world(const char *worldFilePath) {
    char *worldFileContents = NULL;
    cJSON *worldJSON = NULL;
    cJSON *nameJSON = NULL;
    cJSON *indexJSON = NULL;
    FILE *worldFile = NULL;
    long worldFileLength = 0;
    struct World *world = NULL;

    worldFile = fopen(worldFilePath, "r");

    if (!worldFile) {
        panic("failed to open world file");
    }

    fseek(worldFile, 0, SEEK_END);      // move cursor to EOF
    worldFileLength = ftell(worldFile); // get current position of cursor
    fseek(worldFile, 0, SEEK_SET);      // move cursor to BOF

    worldFileContents = malloc(worldFileLength + 1); // allocate memory for file contents, including null terminator

    if (!worldFileContents) {
        panic("failed to malloc world file contents");
    }

    fread(worldFileContents, 1, worldFileLength, worldFile); // read file contents into buffer
    fclose(worldFile);

    worldFileContents[worldFileLength] = '\0'; // add null terminator

    worldJSON = cJSON_Parse(worldFileContents);

    if (!worldJSON) {
        panic("failed to parse world JSON");
    }

    nameJSON = cJSON_GetObjectItemCaseSensitive(worldJSON, "name");

    if (!nameJSON || !cJSON_IsString(nameJSON) || nameJSON->valuestring == NULL) {
        panic("failed to get world name");
    }

    world = world_new(nameJSON->valuestring);

    indexJSON = cJSON_GetObjectItemCaseSensitive(worldJSON, "index");

    if (!indexJSON || !cJSON_IsNumber(indexJSON)) {
        panic("failed to get world index");
    }
}