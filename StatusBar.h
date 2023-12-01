#ifndef STATUSBAR_H
#define STATUSBAR_H

#include "raylib.h"
#include "Item.h"
#include "Player.h"
#include "Enemy.h"
#include "Assets.h"

// Global variables
extern int score;
extern int playerLives;

// Global assets
extern StatusBarTextures statusbarTextures;
extern ItemTextures itemTextures;

class StatusBar
{

private:
    // Items used only in status bar
    Item lifeBar{statusbarTextures.lifebar, {20.0f, 20.0f}, itemTextures.collect};
    Item life1{statusbarTextures.heart, {28.0f, 30.0f}, itemTextures.collect};
    Item life2{statusbarTextures.heart, {42.0f, 30.0f}, itemTextures.collect};
    Item life3{statusbarTextures.heart, {56.0f, 30.0f}, itemTextures.collect};
    Item *lives[3]{&life1, &life2, &life3};

    Item checkpointBar{statusbarTextures.checkpointBar, {100.0f, 25.0f}, itemTextures.collect};
    Item checkpointBarCollected1{statusbarTextures.checkpointBarCollected, {148.0f, 28.0f}, itemTextures.collect};
    Item checkpointBarCollected2{statusbarTextures.checkpointBarCollected, {116.0f, 28.0f}, itemTextures.collect};
    Item checkpointBarCollected3{statusbarTextures.checkpointBarCollected, {82.0f, 28.0f}, itemTextures.collect};
    Item *checkpointsBar[3]{&checkpointBarCollected1, &checkpointBarCollected2, &checkpointBarCollected3};
    int checkpointsRemaining{3};

public:
    // Constructors
    StatusBar();

    void Render(int checkpointsRemaining);
};

#endif