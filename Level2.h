#ifndef LEVEL2_H
#define LEVEL2_H

#include "raylib.h"
#include "Item.h"
#include "Player.h"
#include "Enemy.h"
#include "StatusBar.h"
#include "Assets.h"

// Global variables
extern int currentScreen;
extern bool isMute;

// Global assets
extern BackgroundTextures backgroundTextures;
extern EnemyTextures enemyTextures;
extern ItemTextures itemTextures;
extern GameSounds gameSounds;

class Level2
{

private:
    // Sounds
    Music backgroundMusic{LoadMusicStream("resources/sounds/level2.wav")};

    // Items and Elements for this level only
    Item apple1, apple2, apple3, apple4, apple5;
    Item *apples[5]{&apple1, &apple2, &apple3, &apple4, &apple5};

    Item checkpoint1, checkpoint2, checkpoint3;
    Item *checkpoints[3]{&checkpoint1, &checkpoint2, &checkpoint3};

    Item trampoline1{itemTextures.trampoline, {750.0f, 400.0f}};
    Item trampoline2{itemTextures.trampoline, {175.0f, 275.0f}};
    Item *trampolines[2]{&trampoline1, &trampoline2};

    Item platform1{itemTextures.platform, {180.0f, 300.0f}};
    Item platform2{itemTextures.platform, {450.0f, 150.0f}};
    Item platform3{itemTextures.platform, {230.0f, 190.0f}};
    Item platform4{itemTextures.platform, {480.0f, 300.0f}};
    Item *platforms[4]{&platform1, &platform2, &platform3, &platform4};

    Item door;

    Enemy pig, spikeHead, turtle;
    Enemy *enemies[3]{&pig, &spikeHead, &turtle};

    StatusBar status;
    int checkpointsRemaining{3};

    void RenderBackground();

public:
    // Constructor
    Level2() = default;

    void Init();
    void Render();
    void Update(Player &player);
    void Unload();
};

#endif