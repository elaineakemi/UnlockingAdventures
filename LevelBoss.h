#ifndef LEVELBOSS_H
#define LEVELBOSS_H

#include "raylib.h"
#include "Item.h"
#include "Platform.h"
#include "Player.h"
#include "Enemy.h"
#include "StatusBar.h"
#include "Assets.h"

// Global variables
extern int currentScreen;
extern bool isEnd;

// Global assets
extern BackgroundTextures backgroundTextures;

class LevelBoss
{

private:
    // Sounds
    Music backgroundMusic{LoadMusicStream("resources/sounds/level_boss.wav")};
    Sound hitBossSound{LoadSound("resources/sounds/hit_boss.wav")};
    Sound bossDiedSound{LoadSound("resources/sounds/boss_died.wav")};

    Texture2D disappearTexture{LoadTexture("resources/textures/items/collected.png")};
    Texture2D platformTexture{LoadTexture("resources/textures/items/platform.png")};
    Texture2D pigTexture{LoadTexture("resources/textures/characters/enemy_pig.png")};
    Texture2D pigBossTexture{LoadTexture("resources/textures/characters/pig_boss.png")};
    Texture2D bombOffTexture{LoadTexture("resources/textures/items/bomb_off.png")};
    Texture2D bombOnTexture{LoadTexture("resources/textures/items/bomb_on.png")};
    Texture2D bombExplodingTexture{LoadTexture("resources/textures/items/bomb_explosion.png")};

    // Items and Elements for this level only
    Item bomb;

    Platform platform1{platformTexture, 1, {300.0f, 360.0f}};
    Platform platform2{platformTexture, 1, {15.0f, 290.0f}};
    Platform platform3{platformTexture, 1, {320.0f, 230.0f}};
    Platform *platforms[3]{&platform1, &platform2, &platform3};

    Enemy pigBoss, pig1, pig2, pig3;
    Enemy *enemies[3]{&pig1, &pig2, &pig3};

    StatusBar status;
    int bossHealth{10};
    int intervalHit{50};

public:
    // Constructor
    LevelBoss();

    void Init();
    void RenderBackground();
    void RenderItems();
    void Update(Player &player);
    void Unload();
};

#endif