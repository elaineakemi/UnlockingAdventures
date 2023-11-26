#ifndef LEVEL1_H
#define LEVEL1_H

#include "raylib.h"
#include "Item.h"
#include "Platform.h"
#include "Player.h"
#include "Enemy.h"

extern int score;
extern int playerLives;

class Level1
{

private:
    Music backgroundMusic{LoadMusicStream("resources/sounds/level1.wav")};
    Sound trampolineSound{LoadSound("resources/sounds/trampoline.wav")};
    Sound appleSound{LoadSound("resources/sounds/apple.wav")};
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
    Texture2D lifebarTexture{LoadTexture("resources/textures/items/life_bar.png")};
    Texture2D heartTexture{LoadTexture("resources/textures/items/life.png")};
    Texture2D doorClosedTexture{LoadTexture("resources/textures/items/door_closed.png")};
    Texture2D doorOpenTexture{LoadTexture("resources/textures/items/door_open.png")};
    Texture2D pigTexture{LoadTexture("resources/textures/characters/pig_walking.png")};
    Texture2D spikeHeadTexture{LoadTexture("resources/textures/characters/enemy_spike_head.png")};
    Texture2D turtleTexture{LoadTexture("resources/textures/characters/turtle_idle.png")};
    Texture2D checkpointBarTexture{LoadTexture("resources/textures/items/checkpoint_bar.png")};
    Texture2D checkpointBarCollectedTexture{LoadTexture("resources/textures/items/checkpoint_bar_collected.png")};

    Item apple1{appleTexture, 17, {75.0f, 250.0f}, RAYWHITE, disappearTexture};
    Item apple2{appleTexture, 17, {100.0f, 280.0f}, RAYWHITE, disappearTexture};
    Item apple3{appleTexture, 17, {125.0f, 250.0f}, RAYWHITE, disappearTexture};
    Item apple4{appleTexture, 17, {150.0f, 280.0f}, RAYWHITE, disappearTexture};
    Item apple5{appleTexture, 17, {175.0f, 250.0f}, RAYWHITE, disappearTexture};
    Item *apples[5]{&apple1, &apple2, &apple3, &apple4, &apple5};

    Item checkpoint1{checkpointTexture, 10, {700.0f, 370.0f}, RAYWHITE, checkpointCollectedTexture};
    Item checkpoint2{checkpointTexture, 10, {200.0f, 88.0f}, RAYWHITE, checkpointCollectedTexture};
    Item checkpoint3{checkpointTexture, 10, {730.0f, 237.0f}, RAYWHITE, checkpointCollectedTexture};
    Item *checkpoints[3]{&checkpoint1, &checkpoint2, &checkpoint3};

    Platform trampoline1{trampolineTexture, 8, {290.0f, 400.0f}, RAYWHITE};
    Platform trampoline2{trampolineTexture, 8, {25.0f, 275.0f}, RAYWHITE};
    Platform *trampolines[2]{&trampoline1, &trampoline2};

    Platform platform1{platformTexture, 1, {15.0f, 300.0f}, RAYWHITE};
    Platform platform2{platformTexture, 1, {70.0f, 150.0f}, RAYWHITE};
    Platform platform3{platformTexture, 1, {330.0f, 190.0f}, RAYWHITE};
    Platform platform4{platformTexture, 1, {530.0f, 300.0f}, RAYWHITE};
    Platform *platforms[4]{&platform1, &platform2, &platform3, &platform4};

    Item door{doorClosedTexture, 1, {530.0f, 245.0f}, RAYWHITE, doorOpenTexture};

    Enemy pig{pigTexture, 16, {550.0f, 400.0f}, RAYWHITE, disappearTexture, true};
    Enemy spikeHead{spikeHeadTexture, 4, {550.0f, 305.0f}, RAYWHITE, disappearTexture, false};
    Enemy turtle1{turtleTexture, 14, {305.0f, 165.0f}, RAYWHITE, disappearTexture, false};
    Enemy *enemies[3]{&pig, &spikeHead, &turtle1};

    // TODO: move to a status component
    Item lifeBar{lifebarTexture, 1, {20.0f, 20.0f}, RAYWHITE, disappearTexture};
    Item life1{heartTexture, 8, {28.0f, 30.0f}, RAYWHITE, disappearTexture};
    Item life2{heartTexture, 8, {42.0f, 30.0f}, RAYWHITE, disappearTexture};
    Item life3{heartTexture, 8, {56.0f, 30.0f}, RAYWHITE, disappearTexture};
    Item *lives[3]{&life1, &life2, &life3};

    Item checkpointBar{checkpointBarTexture, 1, {100.0f, 25.0f}, RAYWHITE, disappearTexture};
    Item checkpointBarCollected1{checkpointBarCollectedTexture, 10, {148.0f, 28.0f}, RAYWHITE, disappearTexture};
    Item checkpointBarCollected2{checkpointBarCollectedTexture, 10, {116.0f, 28.0f}, RAYWHITE, disappearTexture};
    Item checkpointBarCollected3{checkpointBarCollectedTexture, 10, {82.0f, 28.0f}, RAYWHITE, disappearTexture};
    Item *checkpointsBar[3]{&checkpointBarCollected1, &checkpointBarCollected2, &checkpointBarCollected3};
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