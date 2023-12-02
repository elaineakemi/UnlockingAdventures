#ifndef CONSTS_H
#define CONSTS_H

#include "raylib.h"

// This file defines some constants used across the application

// All textures uses raywhite colour
const Color defaultColour = RAYWHITE;

//----------------------------------------------------------------------------------
// Level 1
//----------------------------------------------------------------------------------
const Vector2 level1ApplePositions[] = {{75.0f, 250.0f}, {100.0f, 280.0f}, {125.0f, 250.0f}, {150.0f, 280.0f}, {175.0f, 250.0f}};
const Vector2 level1CheckpointPositions[] = {{700.0f, 370.0f}, {200.0f, 88.0f}, {730.0f, 237.0f}};
const Vector2 level1DoorPosition = {530.0f, 245.0f};
#endif
