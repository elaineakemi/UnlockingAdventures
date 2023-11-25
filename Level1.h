#ifndef LEVEL1_H
#define LEVEL1_H

#include "raylib.h"
#include "Item.h"
#include "Platform.h"
#include "Player.h"

class Level1
{

private:
    Texture2D backgroundBorder{LoadTexture("resources/textures/background/border.png")};
    Texture2D background{LoadTexture("resources/textures/background/background1.png")};

    Texture2D disappearTexture{LoadTexture("resources/textures/items/collected.png")};
    Texture2D appleTexture{LoadTexture("resources/textures/items/apple.png")};
    Texture2D checkpointTexture{LoadTexture("resources/textures/items/checkpoint.png")};
    Texture2D checkpointCollectedTexture{LoadTexture("resources/textures/items/checkpoint_collected.png")};
    Texture2D trampolineTexture{LoadTexture("resources/textures/items/trampoline.png")};
    Texture2D platformTexture{LoadTexture("resources/textures/items/platform.png")};

    // workaround to fix apples animation
    int applesCount = 5;
    Item apple1{appleTexture, 17, {75.0f, 250.0f}, RAYWHITE, disappearTexture};
    Item apple2{appleTexture, 17, {100.0f, 280.0f}, RAYWHITE, disappearTexture};
    Item apple3{appleTexture, 17, {125.0f, 250.0f}, RAYWHITE, disappearTexture};
    Item apple4{appleTexture, 17, {150.0f, 280.0f}, RAYWHITE, disappearTexture};
    Item apple5{appleTexture, 17, {175.0f, 250.0f}, RAYWHITE, disappearTexture};
    Item *apples[5]{&apple1, &apple2, &apple3, &apple4, &apple5};

    // workaround to fix checkpoints animation
    Item checkpoint1{checkpointTexture, 10, {700.0f, 370.0f}, RAYWHITE, checkpointCollectedTexture};
    Item checkpoint2{checkpointTexture, 10, {200.0f, 88.0f}, RAYWHITE, checkpointCollectedTexture};
    Item checkpoint3{checkpointTexture, 10, {730.0f, 237.0f}, RAYWHITE, checkpointCollectedTexture};
    Item *checkpoints[3]{&checkpoint1, &checkpoint2, &checkpoint3};

    Platform trampoline1{trampolineTexture, 8, {290.0f, 400.0f}, RAYWHITE};
    Platform trampoline2{trampolineTexture, 8, {25.0f, 275.0f}, RAYWHITE};
    Platform *trampolines[2]{&trampoline1, &trampoline2};

    Platform platform1{platformTexture, 1, {15.0f, 300.0f}, RAYWHITE};
    Platform platform2{platformTexture, 1, {70.0f, 150.0f}, RAYWHITE};
    Platform platform3{platformTexture, 1, {330.0f, 180.0f}, RAYWHITE};
    Platform platform4{platformTexture, 1, {530.0f, 300.0f}, RAYWHITE};
    Platform *platforms[4]{&platform1, &platform2, &platform3, &platform4};

public:
    Level1();
    void Init();
    void RenderBackground();
    void RenderItems();
    void Update(Player &player);
    void Unload();
};

#endif