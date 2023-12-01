#ifndef STATUSBAR_H
#define STATUSBAR_H

#include "raylib.h"
#include "Item.h"
#include "Platform.h"
#include "Player.h"
#include "Enemy.h"
#include "Assets.h"

// Global variables
extern int score;
extern int playerLives;

// Global assets
extern StatusBarTextures statusbarTextures;

class StatusBar
{

private:
    Texture2D disappearTexture = LoadTexture("resources/textures/items/collected.png");

    // Items used only in status bar
    Item lifeBar{statusbarTextures.lifebar, 1, {20.0f, 20.0f}, disappearTexture};
    Item life1{statusbarTextures.heart, 8, {28.0f, 30.0f}, disappearTexture};
    Item life2{statusbarTextures.heart, 8, {42.0f, 30.0f}, disappearTexture};
    Item life3{statusbarTextures.heart, 8, {56.0f, 30.0f}, disappearTexture};
    Item *lives[3]{&life1, &life2, &life3};

    Item checkpointBar{statusbarTextures.checkpointBar, 1, {100.0f, 25.0f}, disappearTexture};
    Item checkpointBarCollected1{statusbarTextures.checkpointBarCollected, 10, {148.0f, 28.0f}, disappearTexture};
    Item checkpointBarCollected2{statusbarTextures.checkpointBarCollected, 10, {116.0f, 28.0f}, disappearTexture};
    Item checkpointBarCollected3{statusbarTextures.checkpointBarCollected, 10, {82.0f, 28.0f}, disappearTexture};
    Item *checkpointsBar[3]{&checkpointBarCollected1, &checkpointBarCollected2, &checkpointBarCollected3};
    int checkpointsRemaining{3};

public:
    // Constructors
    StatusBar();

    void Render(int checkpointsRemaining);
    void Unload();
};

#endif