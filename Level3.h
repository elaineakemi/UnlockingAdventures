#ifndef LEVEL3_H
#define LEVEL3_H

#include "raylib.h"
#include "Item.h"
#include "Player.h"
#include "Enemy.h"
#include "StatusBar.h"
#include "Assets.h"

// Global variables
extern int currentScreen;

// Global assets
extern BackgroundTextures backgroundTextures;
extern EnemyTextures enemyTextures;
extern ItemTextures itemTextures;

class Level3
{

private:
    // Sounds
    Music backgroundMusic{LoadMusicStream("resources/sounds/level3.wav")};
    Sound trampolineSound{LoadSound("resources/sounds/trampoline.wav")};
    Sound checkpointSound{LoadSound("resources/sounds/checkpoint.wav")};
    Sound doorSound{LoadSound("resources/sounds/door_open.wav")};
    // Items and Elements for this level only
    Item apple1, apple2, apple3, apple4, apple5;
    Item *apples[5]{&apple1, &apple2, &apple3, &apple4, &apple5};

    Item checkpoint1, checkpoint2, checkpoint3;
    Item *checkpoints[3]{&checkpoint1, &checkpoint2, &checkpoint3};

    Item platform1{itemTextures.platform, {300.0f, 370.0f}};
    Item platform2{itemTextures.platform, {15.0f, 300.0f}};
    Item platform3{itemTextures.platform, {280.0f, 240.0f}};
    Item platform4{itemTextures.platform, {530.0f, 190.0f}};
    Item *platforms[4]{&platform1, &platform2, &platform3, &platform4};

    Item door;

    Enemy pig1, pig2, pig3, pig4, spikeHead;
    Enemy *enemies[5]{&pig1, &pig2, &pig3, &spikeHead, &pig4};

    StatusBar status;
    int checkpointsRemaining{3};

public:
    // Constructor
    Level3() = default;

    void Init();
    void RenderBackground();
    void RenderItems();
    void Update(Player &player);
    void Unload();
};

#endif