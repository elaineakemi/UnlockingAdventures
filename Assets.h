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
    struct TextureFrames lifebar;
    struct TextureFrames heart;
    struct TextureFrames checkpointBar;
    struct TextureFrames checkpointBarCollected;
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

struct ItemTextures
{
    struct TextureFrames apple;
    struct TextureFrames collect;
    struct TextureFrames bombOff;
    struct TextureFrames bombOn;
    struct TextureFrames bombExplosion;
    struct TextureFrames doorClosed;
    struct TextureFrames doorOpened;
    struct TextureFrames checkpoint;
    struct TextureFrames checkpointCollected;
    struct TextureFrames platform;
    struct TextureFrames trampoline;
};

struct GameSounds
{
    Sound trampoline;
    Sound checkpoint;
    Sound door;
    Sound apple;
    Sound bombDrop;
    Sound bombExplode;
    Sound killEnemy;
    Sound gameOver;
    Sound playerDied;
};

#endif
