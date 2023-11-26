#ifndef LEVELBOSS_H
#define LEVELBOSS_H

#include "raylib.h"
#include "Item.h"
#include "Platform.h"
#include "Player.h"
#include "Enemy.h"
#include "StatusBar.h"

extern int currentScreen;

class LevelBoss
{

private:
    Music backgroundMusic{LoadMusicStream("resources/sounds/level_boss.wav")};

    Texture2D backgroundBorder{LoadTexture("resources/textures/background/border.png")};
    Texture2D background{LoadTexture("resources/textures/background/level_boss.png")};

    Texture2D disappearTexture{LoadTexture("resources/textures/items/collected.png")};
    Texture2D platformTexture{LoadTexture("resources/textures/items/platform.png")};
    Texture2D pigTexture{LoadTexture("resources/textures/characters/pig_walking.png")};
    Texture2D pigBossTexture{LoadTexture("resources/textures/characters/pig_boss.png")};

    Platform platform1{platformTexture, 1, {300.0f, 360.0f}, RAYWHITE};
    Platform platform2{platformTexture, 1, {15.0f, 290.0f}, RAYWHITE};
    Platform platform3{platformTexture, 1, {320.0f, 230.0f}, RAYWHITE};
    Platform *platforms[3]{&platform1, &platform2, &platform3};

    Enemy pigBoss{pigBossTexture, 12, {700.0f, 375.0f}, RAYWHITE, disappearTexture, true};
    Enemy pig1{pigTexture, 16, {650.0f, 400.0f}, RAYWHITE, disappearTexture, true};
    Enemy pig2{pigTexture, 16, {450.0f, 400.0f}, RAYWHITE, disappearTexture, true};
    Enemy pig3{pigTexture, 16, {550.0f, 400.0f}, RAYWHITE, disappearTexture, true};
    Enemy *enemies[3]{&pig1, &pig2, &pig3};

    StatusBar status;
    int bossHealth{10};
    int intervalHit{50};

public:
    LevelBoss();
    void Init();
    void RenderBackground();
    void RenderItems();
    void Update(Player &player);
    void Unload();
};

#endif