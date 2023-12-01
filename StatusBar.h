#ifndef STATUSBAR_H
#define STATUSBAR_H

#include "raylib.h"
#include "Item.h"
#include "Platform.h"
#include "Player.h"
#include "Enemy.h"

// Global variables
extern int score;
extern int playerLives;

class StatusBar
{

private:
    // Textures
    Texture2D lifebarTexture{LoadTexture("resources/textures/items/life_bar.png")};
    Texture2D heartTexture{LoadTexture("resources/textures/items/life.png")};
    Texture2D disappearTexture{LoadTexture("resources/textures/items/collected.png")};
    Texture2D checkpointBarTexture{LoadTexture("resources/textures/items/checkpoint_bar.png")};
    Texture2D checkpointBarCollectedTexture{LoadTexture("resources/textures/items/checkpoint_bar_collected.png")};

    // Items used only in status bar
    Item lifeBar{lifebarTexture, 1, {20.0f, 20.0f}, disappearTexture};
    Item life1{heartTexture, 8, {28.0f, 30.0f}, disappearTexture};
    Item life2{heartTexture, 8, {42.0f, 30.0f}, disappearTexture};
    Item life3{heartTexture, 8, {56.0f, 30.0f}, disappearTexture};
    Item *lives[3]{&life1, &life2, &life3};

    Item checkpointBar{checkpointBarTexture, 1, {100.0f, 25.0f}, disappearTexture};
    Item checkpointBarCollected1{checkpointBarCollectedTexture, 10, {148.0f, 28.0f}, disappearTexture};
    Item checkpointBarCollected2{checkpointBarCollectedTexture, 10, {116.0f, 28.0f}, disappearTexture};
    Item checkpointBarCollected3{checkpointBarCollectedTexture, 10, {82.0f, 28.0f}, disappearTexture};
    Item *checkpointsBar[3]{&checkpointBarCollected1, &checkpointBarCollected2, &checkpointBarCollected3};
    int checkpointsRemaining{3};

public:
    // Constructors
    StatusBar();

    void Render(int checkpointsRemaining);
    void Unload();
};

#endif