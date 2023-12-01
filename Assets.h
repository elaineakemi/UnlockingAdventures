#ifndef ASSETS_H
#define ASSETS_H

#include "raylib.h"

// Assets used across the application

typedef struct StatusBarTextures
{
    Texture2D lifebar;
    Texture2D heart;
    Texture2D checkpointBar;
    Texture2D checkpointBarCollected;
} StatusBarTextures;

typedef struct BackgroundTextures
{
    Texture2D border;
    Texture2D menu;
    Texture2D level1;
    Texture2D level2;
    Texture2D level3;
    Texture2D levelBoss;
} BackgroundTextures;

typedef struct PlayerTextures
{
    Texture2D frog;
    Texture2D blueGuy;
    Texture2D pinkGuy;
} PlayerTextures;

#endif
