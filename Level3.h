#ifndef LEVEL3_H
#define LEVEL3_H

#include "raylib.h"
#include "Item.h"
#include "Platform.h"
#include "Player.h"
#include "Enemy.h"
#include "StatusBar.h"

extern int currentScreen;

class Level3
{

private:
    Music backgroundMusic{LoadMusicStream("resources/sounds/level3.wav")};
    Sound trampolineSound{LoadSound("resources/sounds/trampoline.wav")};
    Sound checkpointSound{LoadSound("resources/sounds/checkpoint.wav")};
    Sound doorSound{LoadSound("resources/sounds/door_open.wav")};

    Texture2D backgroundBorder{LoadTexture("resources/textures/background/border.png")};
    Texture2D background{LoadTexture("resources/textures/background/level3.png")};

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

    Item apple1{appleTexture, 17, {75.0f, 250.0f}, RAYWHITE, disappearTexture};
    Item apple2{appleTexture, 17, {100.0f, 280.0f}, RAYWHITE, disappearTexture};
    Item apple3{appleTexture, 17, {125.0f, 250.0f}, RAYWHITE, disappearTexture};
    Item apple4{appleTexture, 17, {150.0f, 280.0f}, RAYWHITE, disappearTexture};
    Item apple5{appleTexture, 17, {175.0f, 250.0f}, RAYWHITE, disappearTexture};
    Item *apples[5]{&apple1, &apple2, &apple3, &apple4, &apple5};

    Item checkpoint1{checkpointTexture, 10, {700.0f, 370.0f}, RAYWHITE, checkpointCollectedTexture};
    Item checkpoint2{checkpointTexture, 10, {350.0f, 310.0f}, RAYWHITE, checkpointCollectedTexture};
    Item checkpoint3{checkpointTexture, 10, {450.0f, 180.0f}, RAYWHITE, checkpointCollectedTexture};
    Item *checkpoints[3]{&checkpoint1, &checkpoint2, &checkpoint3};

    Platform platform1{platformTexture, 1, {300.0f, 370.0f}, RAYWHITE};
    Platform platform2{platformTexture, 1, {15.0f, 300.0f}, RAYWHITE};
    Platform platform3{platformTexture, 1, {280.0f, 240.0f}, RAYWHITE};
    Platform platform4{platformTexture, 1, {530.0f, 190.0f}, RAYWHITE};
    Platform *platforms[4]{&platform1, &platform2, &platform3, &platform4};

    Item door{doorClosedTexture, 1, {730.0f, 140.0f}, RAYWHITE, doorOpenTexture};

    Enemy pig1{pigTexture, 16, {350.0f, 400.0f}, RAYWHITE, disappearTexture, true};
    Enemy pig2{pigTexture, 16, {450.0f, 400.0f}, RAYWHITE, disappearTexture, true};
    Enemy pig3{pigTexture, 16, {550.0f, 400.0f}, RAYWHITE, disappearTexture, true};
    Enemy pig4{pigTexture, 16, {370.0f, 215.0f}, RAYWHITE, disappearTexture, true};
    Enemy spikeHead{spikeHeadTexture, 4, {550.0f, 305.0f}, RAYWHITE, disappearTexture, false};
    Enemy *enemies[5]{&pig1, &pig2, &pig3, &spikeHead, &pig4};

    StatusBar status;
    int checkpointsRemaining{3};

public:
    Level3();
    void Init();
    void RenderBackground();
    void RenderItems();
    void Update(Player &player);
    void Unload();
};

#endif