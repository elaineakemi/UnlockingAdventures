#ifndef LEVELBOSS_H
#define LEVELBOSS_H

#include "raylib.h"
#include "Item.h"
#include "Player.h"
#include "Enemy.h"
#include "StatusBar.h"
#include "Assets.h"

// Global variables
extern int currentScreen;
extern bool isEnd;
extern bool isMute;

// Global assets
extern BackgroundTextures backgroundTextures;
extern EnemyTextures enemyTextures;
extern ItemTextures itemTextures;

class LevelBoss
{

private:
    // Sounds
    Music backgroundMusic{LoadMusicStream("resources/sounds/level_boss.wav")};
    Sound hitBossSound{LoadSound("resources/sounds/hit_boss.wav")};
    Sound bossDiedSound{LoadSound("resources/sounds/boss_died.wav")};

    // Items and Elements for this level only
    Item bomb;

    Item platform1{itemTextures.platform, {300.0f, 360.0f}};
    Item platform2{itemTextures.platform, {15.0f, 290.0f}};
    Item platform3{itemTextures.platform, {320.0f, 230.0f}};
    Item *platforms[3]{&platform1, &platform2, &platform3};

    Enemy pigBoss, pig1, pig2, pig3;
    Enemy *enemies[3]{&pig1, &pig2, &pig3};

    StatusBar status;
    int bossHealth{10};
    int intervalHit{50};

    void RenderBackground();

public:
    // Constructor
    LevelBoss() = default;

    void Init();
    void Render();
    void Update(Player &player);
    void Unload();
};

#endif