#include "raylib.h"
#include "raymath.h"

#include "./components/camera.c"
#include "./components/player.c"
#include "./helpers/worlds.c"

#define ASSETS_DIR "./assets"
#define ASEPRITE_DIR ASSETS_DIR "/aseprite"
#define WORLDS_DIR "./worlds"

int main(int argc, char **argv) {
    struct Worlds *worlds = worlds_new(WORLDS_DIR);

    InitWindow(800, 450, "Voxia");
    SetTargetFPS(60);
}