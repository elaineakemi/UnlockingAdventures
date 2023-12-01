#ifndef LEVEL1_H
#define LEVEL1_H

#include "raylib.h"
#include "Item.h"
#include "Player.h"
#include "Enemy.h"
#include "StatusBar.h"
#include "Assets.h"

// Global variables
extern int currentScreen;
extern GameSounds gameSounds;

// Global assets
extern BackgroundTextures backgroundTextures;
extern EnemyTextures enemyTextures;
extern ItemTextures itemTextures;

class Level1
{

private:
    // Sounds
    Music backgroundMusic{LoadMusicStream("resources/sounds/level1.wav")};

    // Items and Elements for this level only
    Item apple1, apple2, apple3, apple4, apple5;
    Item *apples[5]{&apple1, &apple2, &apple3, &apple4, &apple5};

    Item checkpoint1, checkpoint2, checkpoint3;
    Item *checkpoints[3]{&checkpoint1, &checkpoint2, &checkpoint3};

    Item trampoline1{itemTextures.trampoline, {290.0f, 400.0f}};
    Item trampoline2{itemTextures.trampoline, {25.0f, 275.0f}};
    Item *trampolines[2]{&trampoline1, &trampoline2};

    Item platform1{itemTextures.platform, {15.0f, 300.0f}};
    Item platform2{itemTextures.platform, {70.0f, 150.0f}};
    Item platform3{itemTextures.platform, {330.0f, 190.0f}};
    Item platform4{itemTextures.platform, {530.0f, 300.0f}};
    Item *platforms[4]{&platform1, &platform2, &platform3, &platform4};

    Item door;

    Enemy pig, spikeHead, turtle;
    Enemy *enemies[3]{&pig, &spikeHead, &turtle};

    StatusBar status;
    int checkpointsRemaining{3};

public:
    // Constructor
    Level1() = default;

    void Init();
    void RenderBackground();
    void RenderItems();
    void Update(Player &player);
    void Unload();
};

#endif