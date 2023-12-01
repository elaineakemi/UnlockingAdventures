#ifndef LEVEL2_H
#define LEVEL2_H

#include "raylib.h"
#include "Item.h"
#include "Platform.h"
#include "Player.h"
#include "Enemy.h"
#include "StatusBar.h"
#include "Assets.h"

// Global variables
extern int currentScreen;

// Global assets
extern BackgroundTextures backgroundTextures;

class Level2
{

private:
    // Sounds
    Music backgroundMusic{LoadMusicStream("resources/sounds/level2.wav")};
    Sound trampolineSound{LoadSound("resources/sounds/trampoline.wav")};
    Sound checkpointSound{LoadSound("resources/sounds/checkpoint.wav")};
    Sound doorSound{LoadSound("resources/sounds/door_open.wav")};

    Texture2D disappearTexture{LoadTexture("resources/textures/items/collected.png")};
    Texture2D appleTexture{LoadTexture("resources/textures/items/apple.png")};
    Texture2D checkpointTexture{LoadTexture("resources/textures/items/checkpoint.png")};
    Texture2D checkpointCollectedTexture{LoadTexture("resources/textures/items/checkpoint_collected.png")};
    Texture2D trampolineTexture{LoadTexture("resources/textures/items/trampoline.png")};
    Texture2D platformTexture{LoadTexture("resources/textures/items/platform.png")};
    Texture2D doorClosedTexture{LoadTexture("resources/textures/items/door_closed.png")};
    Texture2D doorOpenTexture{LoadTexture("resources/textures/items/door_open.png")};
    Texture2D pigTexture{LoadTexture("resources/textures/characters/enemy_pig.png")};
    Texture2D spikeHeadTexture{LoadTexture("resources/textures/characters/enemy_spike_head.png")};
    Texture2D turtleTexture{LoadTexture("resources/textures/characters/enemy_spike_turtle.png")};

    // Items and Elements for this level only
    Item apple1, apple2, apple3, apple4, apple5;
    Item *apples[5]{&apple1, &apple2, &apple3, &apple4, &apple5};

    Item checkpoint1, checkpoint2, checkpoint3;
    Item *checkpoints[3]{&checkpoint1, &checkpoint2, &checkpoint3};

    Platform trampoline1{trampolineTexture, 8, {750.0f, 400.0f}};
    Platform trampoline2{trampolineTexture, 8, {175.0f, 275.0f}};
    Platform *trampolines[2]{&trampoline1, &trampoline2};

    Platform platform1{platformTexture, 1, {180.0f, 300.0f}};
    Platform platform2{platformTexture, 1, {450.0f, 150.0f}};
    Platform platform3{platformTexture, 1, {230.0f, 190.0f}};
    Platform platform4{platformTexture, 1, {480.0f, 300.0f}};
    Platform *platforms[4]{&platform1, &platform2, &platform3, &platform4};

    Item door;

    Enemy pig, spikeHead, turtle;
    Enemy *enemies[3]{&pig, &spikeHead, &turtle};

    StatusBar status;
    int checkpointsRemaining{3};

public:
    // Constructor
    Level2();

    void Init();
    void RenderBackground();
    void RenderItems();
    void Update(Player &player);
    void Unload();
};

#endif