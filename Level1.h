#ifndef LEVEL1_H
#define LEVEL1_H

#include "raylib.h"
#include "Item.h"
#include "Platform.h"
#include "Player.h"
#include "Enemy.h"
#include "StatusBar.h"

extern int currentScreen;

class Level1
{

private:
    Music backgroundMusic{LoadMusicStream("resources/sounds/level1.wav")};
    Sound trampolineSound{LoadSound("resources/sounds/trampoline.wav")};
    Sound checkpointSound{LoadSound("resources/sounds/checkpoint.wav")};
    Sound doorSound{LoadSound("resources/sounds/door_open.wav")};

    Texture2D backgroundBorder{LoadTexture("resources/textures/background/border.png")};
    Texture2D background{LoadTexture("resources/textures/background/level1.png")};

    Texture2D disappearTexture{LoadTexture("resources/textures/items/collected.png")};
    Texture2D appleTexture{LoadTexture("resources/textures/items/apple.png")};
    Texture2D checkpointTexture{LoadTexture("resources/textures/items/checkpoint.png")};
    Texture2D checkpointCollectedTexture{LoadTexture("resources/textures/items/checkpoint_collected.png")};
    Texture2D trampolineTexture{LoadTexture("resources/textures/items/trampoline.png")};
    Texture2D platformTexture{LoadTexture("resources/textures/items/platform.png")};
    Texture2D doorClosedTexture{LoadTexture("resources/textures/items/door_closed.png")};
    Texture2D doorOpenTexture{LoadTexture("resources/textures/items/door_open.png")};
    Texture2D pigTexture{LoadTexture("resources/textures/characters/pig_walking.png")};
    Texture2D spikeHeadTexture{LoadTexture("resources/textures/characters/enemy_spike_head.png")};
    Texture2D turtleTexture{LoadTexture("resources/textures/characters/turtle_idle.png")};

    Item apple1, apple2, apple3, apple4, apple5;
    Item *apples[5]{&apple1, &apple2, &apple3, &apple4, &apple5};

    Item checkpoint1, checkpoint2, checkpoint3;
    Item *checkpoints[3]{&checkpoint1, &checkpoint2, &checkpoint3};

    Platform trampoline1{trampolineTexture, 8, {290.0f, 400.0f}, RAYWHITE};
    Platform trampoline2{trampolineTexture, 8, {25.0f, 275.0f}, RAYWHITE};
    Platform *trampolines[2]{&trampoline1, &trampoline2};

    Platform platform1{platformTexture, 1, {15.0f, 300.0f}, RAYWHITE};
    Platform platform2{platformTexture, 1, {70.0f, 150.0f}, RAYWHITE};
    Platform platform3{platformTexture, 1, {330.0f, 190.0f}, RAYWHITE};
    Platform platform4{platformTexture, 1, {530.0f, 300.0f}, RAYWHITE};
    Platform *platforms[4]{&platform1, &platform2, &platform3, &platform4};

    Item door;

    Enemy pig, spikeHead, turtle;
    Enemy *enemies[3]{&pig, &spikeHead, &turtle};

    StatusBar status;
    int checkpointsRemaining{3};

public:
    Level1();
    void Init();
    void RenderBackground();
    void RenderItems();
    void Update(Player &player);
    void Unload();
};

#endif