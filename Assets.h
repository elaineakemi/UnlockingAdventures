#ifndef ASSETS_H
#define ASSETS_H

#include "raylib.h"

struct TextureFrames
{
    Texture2D texture;
    int frames;
};

// Assets used across the application
struct StatusBarTextures
{
    Texture2D lifebar;
    Texture2D heart;
    Texture2D checkpointBar;
    Texture2D checkpointBarCollected;
};

struct BackgroundTextures
{
    Texture2D border;
    Texture2D menu;
    Texture2D level1;
    Texture2D level2;
    Texture2D level3;
    Texture2D levelBoss;
};

struct PlayerTextures
{
    struct TextureFrames frog;
    struct TextureFrames blueGuy;
    struct TextureFrames pinkGuy;
};

struct EnemyTextures
{
    struct TextureFrames pig;
    struct TextureFrames turtle;
    struct TextureFrames spikeHead;
    struct TextureFrames pigBoss;
};

#endif
